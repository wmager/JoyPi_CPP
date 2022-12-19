#include "distance.h"
#include <wiringPi.h>

int pTrig, pEcho;

#define SPEED_OF_SOUND 343.2 // Schallgeschwindigkeit in m/s


void distanceSetup(int trig, int echo){
    wiringPiSetup () ;
    pTrig = trig;
     pEcho = echo;

	pinMode (pTrig, OUTPUT) ;
	pinMode (pEcho,INPUT );
	//cout <<"Entfernung wird ermittelt.\n"<<flush; // Ausgabe von Text in der Konsole
	
	digitalWrite(pTrig, LOW);
	//cout << "Warte auf den Sensor.\n"<<flush;
	delay(2000); // 2 Sekunden Wartezeit.



}

double getDistance(){
digitalWrite(pTrig, HIGH);  // Sendet ein Ultraschallsignal
	delay(1);      // Wartet 0,0001 Sekunden
	digitalWrite(pTrig, LOW); // Beendet das senden des Ultraschallsignals

int pulse_start, pulse_end, pulse_duration;

while (digitalRead(pEcho)==LOW)
  pulse_start = micros();

while (digitalRead(pEcho)==HIGH)
  pulse_end =  micros();

pulse_duration = pulse_end - pulse_start; // Berechnung für die Dauer Des Pulses
//cout << "Pulse: " << pulse_duration << " µs\n"<<flush;

double distance = pulse_duration * SPEED_OF_SOUND / 20000;  // Berechnung zur Bestimmung der Entfernung.

return distance;

}

