#include  <signal.h>
#include  <stdlib.h>
#include <iostream>
#include <wiringPi.h>

#include "distance.h"
#include "Adafruit_LEDBackpack.h"

using namespace std;

void INThandler(int);

#define TRIG 27 // Wpi27 entspricht Pin36
#define ECHO 26 // Wpi26 entspricht Pin32
#define ADDR 0x70 // I2C-Adresse der 7-Segment-Anzeige

Adafruit_7segment *seg;

int  main(void)
{
	signal(SIGINT, INThandler);
	seg = new Adafruit_7segment();

	seg->begin(ADDR); 
	seg->clear();
	seg->writeDisplay();

	seg->print("----");
	seg->writeDisplay();

	distanceSetup(TRIG, ECHO);

	while(true){
		double distance = getDistance();
		//distance = round(distance, 2);      # Ergebnis wird auf 2 Nachkommastellen gerundet.
		cout << "Distance: "  << to_string(distance) << " cm\n"<<flush;
		seg->println(distance, 1);
		seg->writeDisplay();
		delay(100); 
	}
}

void  INThandler(int sig)
{
	signal(sig, SIG_IGN);
	distanceCleanup();
	delete seg;
	exit(0);
}
