
#ifndef _VMA400_h
#define _VMA400_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
class VMA400 {
public:

	int SetRelayPin(int pin);
	int SetMultiRelayPin(int startRange, int StopRange);
	void WriteSingelPin(int pin, bool value);
	byte ReadSingelPin(int pin);
	byte ReadMultiPin(int StartRange, int stopRange);
	byte DebugSerialMultiPin(int StartRange, int stopRange);
	byte DebugSerialSingelPin(int pin);
	void WriteMultiPin(int StartRange, int StopRange, bool value);
	void DelayWritePin(int pin, bool value, int DelayTime);

};

#endif
