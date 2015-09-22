#pragma once
LiquidCrystal_I2C lcd(0x27, 16, 2);

class LCDClass {
public:
	void init();
};

void LCDClass::init() {
	lcd.init();
	lcd.backlight();
	lcd.print("P.E.M.O.S");
	lcd.setCursor(0, 1);
	lcd.print("v1.0.150922");
	delay(1000);
}

LCDClass LCD;