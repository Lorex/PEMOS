#pragma once
#include <Arduino.h>
#include "task.h"
#include "lcdModule.h"
#include "dhtModule.h"
#include "pirModule.h"

void pemosInitialize(){
	LCD.init();
	pinMode(PIR.getBuzzerPin(), OUTPUT);
	pinMode(PIR.getPirPin(), INPUT);
	Serial.begin(115200);
}
