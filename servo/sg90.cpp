#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "sg90.h"

using namespace std;

Sg90::Sg90(int pin, int direction) : pin_(pin),
                                     direction_(direction)
{
    wiringPiSetup();
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    softPwmCreate(pin, 0, 2000);
}

//-100= 0 + 4
//+100= 20 + 24
int _henkan(int value)
{
    value = (value + 100) / 10 + 4;
    if (value < 4)
        value = 4;
    if (value > 24)
        value = 24;
    return (value);
}

int Sg90::currentDirection()
{
    return direction_;
}

void Sg90::setDirection(int direction)
{
    softPwmWrite(pin_, _henkan(direction));
    direction_ = direction;
     cout << "Set:" <<  direction << endl << flush;
}

void Sg90::setDirection(int direction, int speed)
{
    for (int d = direction_; (speed > 0) ? (d < direction) : (d > direction); d += speed)
    {
        softPwmWrite(pin_, _henkan(d));
        delay(100);
    }
    softPwmWrite(pin_, _henkan(direction));
    direction_ = direction;
}

Sg90:: ~ Sg90()
{
    softPwmWrite(pin_, _henkan(0));
    delay(1000);
    softPwmStop(pin_);
    digitalWrite (pin_,  LOW); 
    pinMode (pin_, INPUT);
}
