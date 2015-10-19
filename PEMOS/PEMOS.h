#pragma once
#include <Arduino.h>
#include "task.h"
#include "lcdModule.h"
#include "dhtModule.h"
#include "pirModule.h"
#include "gasModule.h"
#include "fireModule.h"
#include "serialModuls.h"

void pemosInitialize(){
	LCD.init();
	pinMode(PIR.getBuzzerPin(), OUTPUT);
	pinMode(PIR.getPirPin(), INPUT);
	pinMode(GAS.getGasPin(), INPUT);
	pinMode(FIRE.getFirePin(), INPUT);
	Serial.begin(115200);

}
