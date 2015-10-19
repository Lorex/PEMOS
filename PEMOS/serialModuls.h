#pragma once

class serialClass {
public:
	void uploadStatus();
	void commandHandler();
private:
	const String APIVersion = "3";
};

void serialClass::uploadStatus(){
	int temp = DHT.getTemp();
	int humid = DHT.getHumid();
	int invaded = PIR.getValue();
	int mute = PIR.getMute();
	int gas = GAS.getValue();
	int fire = FIRE.getValue();
	
	Serial.println("T" + (String)temp + "H" + (String)humid + "I" + (String)invaded + "M" + (String)mute + "G" + (String)gas + "F" + (String)fire + "A" + APIVersion + "E");
}

void serialClass::commandHandler() {
	if (Serial.available()) {
		switch (Serial.read())
		{
		case '1':
			PIR.toggleMute();
			break;
		case '2':
			tone(PIR.getBuzzerPin(), 1000);
		case '3':
			noTone(PIR.getBuzzerPin());
		default:
			break;
		}
	}
}

serialClass SER;