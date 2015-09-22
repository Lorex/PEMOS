/*
========================================
|  Prometheus Environment Monitor OS   |
|             v1.0.150922              |
|                                      |
|  Author: Lorex                       |
|  Special Thanks: chiou_mark          |
========================================
*/

//#include "emModule.h"
#include "Wire\Wire.h"
#include "LiquidCrystal_I2C\LiquidCrystal_I2C.h"
#include "DHT\dht11.h"
#include "PEMOS.h"

void setup()
{
	pemosInitialize();
	createTask((char*)refreshDHT, 500);
	createTask((char*)refreshPIR, 100);

}

void loop()
{
	runTask((char*)refreshDHT);
	runTask((char*)refreshPIR);
}


void refreshDHT() {
	if (DHT.isAvailable()) {
		DHT.getValue();
		DHT.printValue();
	}
}

void refreshPIR() {
	PIR.scan();
	PIR.printValue();
	if (PIR.getValue())
		tone(PIR.getBuzzerPin(), 1000,50);
}