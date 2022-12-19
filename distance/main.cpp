#include  <signal.h>
#include  <stdlib.h>
#include <iostream>

#include "distance.h"
using namespace std;

void INThandler(int);

#define TRIG 27 // Wpi27 entspricht Pin36
#define ECHO 26 // Wpi26 entspricht Pin32

int  main(void)
{
	signal(SIGINT, INThandler);
	distanceSetup(TRIG, ECHO);

	while(true){
		double distance = getDistance();
		//distance = round(distance, 2);      # Ergebnis wird auf 2 Nachkommastellen gerundet.
		cout << "Distance: "  << to_string(distance) << " cm\n"<<flush;  
		//delay(1000); 
	}
}

void  INThandler(int sig)
{
	signal(sig, SIG_IGN);
//	digitalWrite (TRIG,  LOW); 
//	pinMode (TRIG, INPUT) ;
	exit(0);
}
