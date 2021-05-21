// beeper.cpp
/*
This file is part of AYAB.

    AYAB is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AYAB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with AYAB.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2013 Christian Obersteiner, Andreas Müller
    http://ayab-knitting.com
*/

#include "Arduino.h"
#include "./beeper.h"

#define NOTE_C5 523.25
#define NOTE_D5 587.33
#define NOTE_E5 659.25
#define NOTE_F5 698.46
#define NOTE_G5 783.99
#define NOTE_A5 880.00
#define NOTE_BES5 932.33
#define NOTE_B5 987.77
#define NOTE_C6 1046.50

Beeper::Beeper() {
  // Intentionally left blank
}


void Beeper::ready() {
  beep(5);
}


void Beeper::finishedLine() {
  beep(3);
}


void Beeper::endWork() {
  beep(10);
}

/*
 * Beeps happy birthday.
 * Notes:
 *   C C D C F E
 *   C C D C G F
 *   C C C+ A F E D
 *   B B A F G F
 */
void Beeper::happyBirthday() {
	int duration1 = 350;
	int pause1 = 10;
	int duration2 = duration1 * 2;
	int pause2 = pause1 * 2;
	int duration3 = duration1 * 4;
	int pause3 = pause1 * 4;
	
	beep(NOTE_C5, duration1, pause1);
	beep(NOTE_C5, duration1, pause1);
	beep(NOTE_D5, duration2, pause2);
	beep(NOTE_C5, duration2, pause2);
	beep(NOTE_F5, duration2, pause2);
	beep(NOTE_E5, duration3, pause3);
	
	beep(NOTE_C5, duration1, pause1);
	beep(NOTE_C5, duration1, pause1);
	beep(NOTE_D5, duration2, pause2);
	beep(NOTE_C5, duration2, pause2);
	beep(NOTE_G5, duration2, pause2);
	beep(NOTE_F5, duration3, pause3);
	
	beep(NOTE_C5, duration1, pause1);
	beep(NOTE_C5, duration1, pause1);
	beep(NOTE_C6, duration2, pause2);
	beep(NOTE_A5, duration2, pause2);
	beep(NOTE_F5, duration2, pause2);
	beep(NOTE_E5, duration2, pause2);
	beep(NOTE_D5, duration3, pause3);
	
	beep(NOTE_BES5, duration1, pause1);
	beep(NOTE_BES5, duration1, pause1);
	beep(NOTE_A5, duration2, pause2);
	beep(NOTE_F5, duration2, pause2);
	beep(NOTE_G5, duration2, pause2);
	beep(NOTE_F5, duration3, pause3);
}


/*
 * PRIVATE METHODS
 */
void Beeper::beep(byte length) {
  for (int i=0; i < length; i++) {
    analogWrite(PIEZO_PIN, 255);
    delay(BEEPDELAY);
    analogWrite(PIEZO_PIN, 235);
    delay(BEEPDELAY);
  }
  analogWrite(PIEZO_PIN, 0);
}


void Beeper::beep(float freq, int durationMs, int pauseDurationMs) {
	int delayUs = (int) (1000000L / freq);
	long durationUs = durationMs * 1000L;
	for(long i = 0; i < durationUs; i += 2 * delayUs) {
		digitalWrite(PIEZO_PIN, HIGH);
		delayMicroseconds(delayUs);
		digitalWrite(PIEZO_PIN, LOW);
		delayMicroseconds(delayUs);
	}
	delay(pauseDurationMs);
}
