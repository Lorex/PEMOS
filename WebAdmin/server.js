// require modules
var express = require('express');
var serial = require('serialport').SerialPort;
var sys = require('sys');
var parser = require('serialport');
var morgan = require('morgan');

// require config file
var config = require('./config');

// variables
const appVersion = "2.1.150923";
var sp = new serial(config.pemosComPort, { baudrate: 115200, parser: parser.parsers.readline("\n") });
var app = express();
var data = {
    "temp": 0,
    "humid": 0,
    "invaded": 0,
    "mute": 0,
    "refresh": 5,
    "apiVersion": 0,
    "appVersion": appVersion,
    "muteToggled": 0
};

// configuration
app.use(morgan(':remote-addr :status :method :url :response-time'));
app.use(express.static(__dirname + '/public'));
app.set('views', __dirname + '/views');
app.set('view engine', 'jade');

//receive serial port data
sp.on('data', function (chunk) {
    var spData;
    spData += chunk.toString();
    if (spData.indexOf('T') >= 0 && spData.indexOf('E') >= 0) {
        data.temp = spData.substring(spData.indexOf('T') + 1, spData.indexOf('H'));
        data.humid = spData.substring(spData.indexOf('H') + 1, spData.indexOf('I'));
        data.invaded = spData.substring(spData.indexOf('I') + 1, spData.indexOf('M'));
        data.mute = spData.substring(spData.indexOf('M') + 1, spData.indexOf('A'));
        data.apiVersion = spData.substring(spData.indexOf('A') + 1, spData.indexOf('E'));
    }
});

// routing
app.get('/', function (req, res) {
    data.muteToggled = 0;
    delete require.cache[require.resolve('./config')];
    data.refresh = require('./config').refreshInterval;
    res.render('main', data);
});

app.get('/toggleMute', function (req, res) {
    data.muteToggled = 1;
    sp.write('1');
    res.render('main', data);
});

app.listen(config.listenOnPort, config.listenOnIP, function () {
    console.log("Server listening on " + config.listenOnIP + ":" + config.listenOnPort);
});