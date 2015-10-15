#pragma once

class serialClass {
public:
	void uploadStatus();
	void commandHandler();
private:
	const String APIVersion = "2";
};

void serialClass::uploadStatus(){
	int temp = DHT.getTemp();
	int humid = DHT.getHumid();
	int invaded = PIR.getValue();
	int mute = PIR.getMute();
	
	Serial.println("T" + (String)temp + "H" + (String)humid + "I" + (String)invaded + "M" + (String)mute + "A" + APIVersion + "E");
}

void serialClass::commandHandler() {
	if (Serial.available()) {
		switch (Serial.read())
		{
		case '1':
			PIR.toggleMute();
			break;
		default:
			break;
		}
	}
}

serialClass SER;