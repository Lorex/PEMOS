#pragma once

class fireClass
{
public:
	bool getValue();
	void scan();
	int getFirePin();
private:
	const int pin = 9;
	bool fire = false;
};



bool fireClass::getValue() {
	return fire;
}

void fireClass::scan()
{
	fire = digitalRead(pin);
}

int fireClass::getFirePin()
{
	return fire;
}

fireClass FIRE;