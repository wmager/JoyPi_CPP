#include "distance.h"
#include <wiringPi.h>

int pTrig, pEcho;

#define SPEED_OF_SOUND 343.2 // Schallgeschwindigkeit in m/s

void distanceSetup(int trig, int echo){
    wiringPiSetup () ;
    pTrig = trig;
     pEcho = echo;

	pinMode (pTrig, OUTPUT);
	pinMode (pEcho, INPUT );
	
	digitalWrite(pTrig, LOW);
	delay(2000); // 2 Sekunden Wartezeit.
}

void distanceCleanup(){
	digitalWrite(pTrig, LOW);
	pinMode (pTrig, INPUT);
}

double getDistance(){
	digitalWrite(pTrig, HIGH);  // Sendet ein Ultraschallsignal
	delay(1);      				// Wartet 0,0001 Sekunden
	digitalWrite(pTrig, LOW); 	// Beendet das senden des Ultraschallsignals

	int pulse_start, pulse_end, pulse_duration;

	while (digitalRead(pEcho)==LOW)
	pulse_start = micros();

	while (digitalRead(pEcho)==HIGH)
	pulse_end =  micros();

	pulse_duration = pulse_end - pulse_start; // Berechnung für die Dauer Des Pulses
	double distance = pulse_duration * SPEED_OF_SOUND / 20000;  // Berechnung zur Bestimmung der Entfernung.

	return distance;
}

