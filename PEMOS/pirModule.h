class PIRClass
{
public:
	void scan();
	int getPirPin();
	int getBuzzerPin();
	bool getValue();
	bool toggleMute();
	void printValue();
private:
	bool invaded = false;
	bool mute = false;
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

bool PIRClass::getValue() {
	return invaded;
}

bool PIRClass::toggleMute() {

}
void PIRClass::printValue() {
	lcd.setCursor(0, 1);
	lcd.print((invaded) ? "INVADED." : "Safe.");
}

PIRClass PIR;