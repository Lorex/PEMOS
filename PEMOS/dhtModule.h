#pragma once

dht11 dht;

class DHTClass {
public:
	void getValue();
	void printValue();
	bool isAvailable();
private:
	int temp;
	int humid;
	const int pin = 13;
};

void DHTClass::getValue() {
	temp = dht.temperature;
	humid = dht.humidity;
}

void DHTClass::printValue() {
	lcd.clear();
	lcd.print("T:" + (String)((temp < 100) ? " " : "") + (String)((temp < 10) ? " " : "") + (String)temp + (char)0xDF + "C ");
	lcd.print("H:" + (String)((humid < 100) ? " " : "") + (String)((humid < 10) ? " " : "") + (String)humid + "%RH");
}

bool DHTClass::isAvailable() {
	return(dht.read(pin) == DHTLIB_OK) ? true : false;
}


DHTClass DHT;