
#include "VMA400.h"


//Defines a pin to be used by the relay
int VMA400::SetRelayPin(int pin) {

	pinMode(pin, OUTPUT);
	return pin;

}

//Defines pin for pin until it reaches the givin stop value
int VMA400::SetMultiRelayPin(int StartRange, int StopRange) {

	for (int start = StartRange; start < StopRange + 1; start++) {

		pinMode(start, OUTPUT);
		return start;

	}

}


//Sets a pin to HIGH or LOW
void VMA400::WriteSingelPin(int pin, bool value) {

	digitalWrite(pin, value);

}

//Readsout the state of a pin
byte VMA400::ReadSingelPin(int pin) {

	byte value = digitalRead(pin);
	return value;

}

//Reads out all givin pin states until Stop value is reached
byte VMA400::ReadMultiPin(int StartRange, int StopRange) {

	for (int start = StartRange; start < StopRange + 1; start++) {

		int value = digitalRead(start);
		return value;
	}


}

/*Reads out all givin pin statuses than prints it
  to the serial monitor for debugging purposes*/
byte VMA400::DebugSerialMultiPin(int StartRange, int StopRange) {

	int pinNumber = 0;

	for (int start = StartRange; start < StopRange+1; start++) {
		pinNumber++;
		bool readout = digitalRead(start);
		Serial.print("The state of relay ");
		Serial.print(pinNumber);
		Serial.print(" is: ");
		Serial.print(readout);
		Serial.println();
		delay(500);
	}

	Serial.println();

}

/*Reads out one pin status than prints it
	to the serial monitor for debugging purposes*/
byte VMA400::DebugSerialSingelPin(int pin) {

	bool readout = digitalRead(pin);
	Serial.print("The relay state is: ");
	Serial.print(readout);
	Serial.println();

}

//Sets all givin pins to the state of LOW or HIGH
void VMA400::WriteMultiPin(int StartRange, int StopRange, bool value) {


	for (int start = StartRange; start < StopRange+1; start++) {

		digitalWrite(start, value);

	}

}

//Sets the givin pin to HIGH or LOW after the givin delay has elapsed
void VMA400::DelayWritePin(int pin, bool value, int DelayTime){

	delay(DelayTime);
	digitalWrite(pin,value);

}
