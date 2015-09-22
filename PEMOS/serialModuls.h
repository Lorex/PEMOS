#pragma once

class serialClass {
public:
	void uploadStatus();
};

void serialClass::uploadStatus(){
	int temp = DHT.getTemp();
	int humid = DHT.getHumid();
	int invaded = PIR.getValue();
	
	Serial.println("B" + (String)temp + "/" + (String)humid + "/" + (String)invaded + "E");
}

serialClass SER;