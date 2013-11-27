// encoders.h

#ifndef ENCODERS_H
#define ENCODERS_H

#include "Arduino.h"
#include "settings.h"
#include "debug.h"

class Encoders{
public:
	Encoders();

	void encA_rising();
	void encA_falling();

	byte 			getPosition();
	Beltshift_t 	getBeltshift();
	Direction_t 	getDirection();

private:
	Direction_t 	m_direction;
	Beltshift_t 	m_beltShift;
	byte 			m_encoderPos;
};

#endif