#pragma once

class gasClass
{
public:
	bool getValue();
	void scan();
	int getGasPin();
private:
	const int pin = 10;
	bool gas = false;
};



bool gasClass::getValue() {
	return gas;
}

void gasClass::scan()
{
	gas = digitalRead(pin);
}

int gasClass::getGasPin()
{
	return gas;
}

gasClass GAS;