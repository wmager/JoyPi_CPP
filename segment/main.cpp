#include <signal.h>
#include <stdlib.h>
#include <wiringPi.h>
#include  <iostream>
#include <ctime>

#include "Adafruit_LEDBackpack.h"

using namespace std;

#define led_pin  25
#define  addr 0x70

void  INThandler(int sig);

Adafruit_7segment *seg;

int  main(void)
{
  signal(SIGINT, INThandler);
  cout << "Program segment started." << endl << flush;

  seg = new Adafruit_7segment();

   seg->begin(addr); 
   seg->clear();
   seg->writeDisplay();

  seg->print("AFFE");
  seg->writeDisplay();
  delay(5000);

  /*
  for(int i = 0; i<10;i++){
    seg.writeDigitNum(0,i);
    seg.writeDisplay();
    delay(1000);
*/

  while(true){
  time_t t = time(0);
  tm* now = localtime(&t);
    seg->writeDigitNum(0, now->tm_hour / 10, false);     // Zehnerzahlen
    seg->writeDigitNum(1, now->tm_hour % 10, false);     // Einerzahlen
    // Anzeige für die Minuten.
    seg->writeDigitNum(3, now->tm_min / 10, false);   // Zehnerzahlen
    seg->writeDigitNum(4, now->tm_min % 10, false);        // Einerzahlen
    seg->drawColon( now->tm_sec%2==0);
    seg->writeDisplay();
    delay(1000);
}

}

void  INThandler(int sig)
{
  signal(sig, SIG_IGN);
  delete seg;
  exit(0);
}