class PIRClass
{
public:
	void scan();
	int getPirPin();
	int getBuzzerPin();
	int getValue();
	void printValue();
private:
	bool invaded = false;
	const int pirPin = 12;
	const int buzzerPin = 11;
};

void PIRClass::scan() {
	invaded = digitalRead(pirPin);
}

int PIRClass::getPirPin() {
	return pirPin;
}

int PIRClass::getBuzzerPin() {
	return buzzerPin;
}

int PIRClass::getValue() {
	return invaded;
}
void PIRClass::printValue() {
	lcd.setCursor(0, 1);
	lcd.print((invaded) ? "INVADED." : "Safe.");
}

PIRClass PIR;