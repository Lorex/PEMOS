/*
========================================
|  Prometheus Environment Monitor OS   |
|             v1.2.150922              |
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
}

void loop()
{
	runTask((char*)refreshDHT, "refDHT");
	runTask((char*)refreshPIR, "refPIR");
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
	Serial.println(PIR.getValue());
	PIR.printValue();
	if (PIR.getValue())
	{
		tone(PIR.getBuzzerPin(), 1000);
	}
	else {
		noTone(PIR.getBuzzerPin());
	}

}