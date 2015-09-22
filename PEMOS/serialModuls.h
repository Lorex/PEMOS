#pragma once

class serialClass {
public:
	void uploadStatus();
};

void serialClass::uploadStatus(){
	int temp = DHT.getTemp();
	int humid = DHT.getHumid();
	int invaded = PIR.getValue();
	int mute = PIR.getMute();
	
	Serial.println("B" + (String)temp + "/" + (String)humid + "/" + (String)invaded + "/" + (String)mute + "E");
}

serialClass SER;