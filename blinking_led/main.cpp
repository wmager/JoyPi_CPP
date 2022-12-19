#include <signal.h>
#include <stdlib.h>
#include <wiringPi.h>
#include  <iostream>

using namespace std;

#define led_pin  25

void  INThandler(int sig);

int  main(void)
{
  signal(SIGINT, INThandler);
  wiringPiSetup ();
  pinMode (led_pin, OUTPUT) ;

  cout << "Program blinking led started." << endl << flush;

  while (true)
  {
    digitalWrite (led_pin, HIGH); 
    delay (200);
    digitalWrite (led_pin,  LOW); 
    delay (200);
  }
  return 0;
}

void  INThandler(int sig)
{
  signal(sig, SIG_IGN);
  digitalWrite (led_pin,  LOW); 
  pinMode (led_pin, INPUT);
  exit(0);
}