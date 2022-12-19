#include <signal.h>
#include <stdlib.h>
#include <wiringPi.h>
#include  <iostream>
#include "sg90.h"

using namespace std;

#define servo1_pin 6
#define servo_pin 25

void  INThandler(int sig);

Sg90 *s;

int main(void)
{
  signal(SIGINT, INThandler);

  //Sg90 s(servo_pin,0);
  s = new Sg90(servo_pin,0);  

  while(true){
    cout << "Turn left ..." << endl << flush;
    s->setDirection(100);
    delay(5000);
    cout << "Turn right ..." << endl << flush;
    s->setDirection(-100);
    delay(5000);
  }
  return 0;
}

void  INThandler(int sig)
{
  signal(sig, SIG_IGN);
  delete s;
  exit(0);
}