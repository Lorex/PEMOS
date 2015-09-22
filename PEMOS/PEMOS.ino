/*
========================================
|  Prometheus Environment Monitor OS   |
|             v1.5.150923              |
|                                      |
|  Author: Lorex                       |
|  Special Thanks:                     |
|    - chiou_mark for device testing   |
|    - ADR for technical support       |
|    - tasi for technical support      |
========================================
*/

// include required arduino libs
#include "Wire\Wire.h"
#include "LiquidCrystal_I2C\LiquidCrystal_I2C.h"
#include "DHT\dht11.h"

// include PEMOS
#include "PEMOS.h"

void setup()
{
	pemosInitialize();
	createTask("refDHT", 500);
	createTask("refPIR", 200);
	createTask("refSerial", 1000);
	createTask("scanSerial", 1);
}

void loop()
{
	runTask((char*)refreshDHT, "refDHT");
	runTask((char*)refreshPIR, "refPIR");
	runTask((char*)refreshSerial, "refSerial");
	runTask((char*)scanSerial, "scanSerial");
}

// tasks


void refreshDHT() {
	if (DHT.isAvailable()) {
		DHT.reloadValue();
		DHT.printValue();
	}
}

void refreshPIR() {
	PIR.scan();
	PIR.printValue();
	if (PIR.getValue() && !PIR.getMute())
	{
		tone(PIR.getBuzzerPin(), 1000);
	}
	else {
		noTone(PIR.getBuzzerPin());
	}

}
void refreshSerial() {
	SER.uploadStatus();
}

void scanSerial() {
	SER.commandHandler();
}