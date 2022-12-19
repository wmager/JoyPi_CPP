/*!
 * @file Adafruit_LEDBackpack.cpp
 *
 * @mainpage Adafruit LED Backpack library for Arduino.
 *
 * @section intro_sec Introduction
 *
 * This is an Arduino library for our I2C LED Backpacks:
 * ----> http://www.adafruit.com/products/
 * ----> http://www.adafruit.com/products/
 *
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
 * with 3 Address Select pins: 0x70 thru 0x77
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * @section dependencies Dependencies
 *
 * This library depends on <a
 * href="https://github.com/adafruit/Adafruit-GFX-Library"> Adafruit_GFX</a>
 * being present on your system. Please make sure you have installed the latest
 * version before using this library.
 *
 * @section author Author
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries.
 *
 * @section license License
 *
 * MIT license, all text above must be included in any redistribution
 *
 */

#include "Adafruit_LEDBackpack.h"

#include  <iostream>
#include <wiringPiI2C.h>

int fd = -1;

static const uint8_t sevensegfonttable[] = {

    0b00000000, // (space)
    0b10000110, // !
    0b00100010, // "
    0b01111110, // #
    0b01101101, // $
    0b11010010, // %
    0b01000110, // &
    0b00100000, // '
    0b00101001, // (
    0b00001011, // )
    0b00100001, // *
    0b01110000, // +
    0b00010000, // ,
    0b01000000, // -
    0b10000000, // .
    0b01010010, // /
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b00001001, // :
    0b00001101, // ;
    0b01100001, // <
    0b01001000, // =
    0b01000011, // >
    0b11010011, // ?
    0b01011111, // @
    0b01110111, // A
    0b01111100, // B
    0b00111001, // C
    0b01011110, // D
    0b01111001, // E
    0b01110001, // F
    0b00111101, // G
    0b01110110, // H
    0b00110000, // I
    0b00011110, // J
    0b01110101, // K
    0b00111000, // L
    0b00010101, // M
    0b00110111, // N
    0b00111111, // O
    0b01110011, // P
    0b01101011, // Q
    0b00110011, // R
    0b01101101, // S
    0b01111000, // T
    0b00111110, // U
    0b00111110, // V
    0b00101010, // W
    0b01110110, // X
    0b01101110, // Y
    0b01011011, // Z
    0b00111001, // [
    0b01100100, //
    0b00001111, // ]
    0b00100011, // ^
    0b00001000, // _
    0b00000010, // `
    0b01011111, // a
    0b01111100, // b
    0b01011000, // c
    0b01011110, // d
    0b01111011, // e
    0b01110001, // f
    0b01101111, // g
    0b01110100, // h
    0b00010000, // i
    0b00001100, // j
    0b01110101, // k
    0b00110000, // l
    0b00010100, // m
    0b01010100, // n
    0b01011100, // o
    0b01110011, // p
    0b01100111, // q
    0b01010000, // r
    0b01101101, // s
    0b01111000, // t
    0b00011100, // u
    0b00011100, // v
    0b00010100, // w
    0b01110110, // x
    0b01101110, // y
    0b01011011, // z
    0b01000110, // {
    0b00110000, // |
    0b01110000, // }
    0b00000001, // ~
    0b00000000, // del
};

void Adafruit_LEDBackpack::setBrightness(uint8_t b) {
  if (b > 15)
    b = 15; // limit to max brightness
  uint8_t buffer = HT16K33_CMD_BRIGHTNESS | b;
  wiringPiI2CWrite(fd, buffer);
}

void Adafruit_LEDBackpack::blinkRate(uint8_t b) {
  if (b > 3)
    b = 0; // turn off if not sure
  uint8_t buffer = HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON | (b << 1);
  wiringPiI2CWrite(fd, buffer);
}

Adafruit_LEDBackpack::Adafruit_LEDBackpack(void) {}

Adafruit_LEDBackpack::~Adafruit_LEDBackpack(void) {
  clear();
  writeDisplay();
}

bool Adafruit_LEDBackpack::begin(uint8_t _addr) {
    if(fd!=-1){
      // close, but how? 
    }
    fd = wiringPiI2CSetup(_addr);
    if (fd == -1) {
        std::cout << "Failed to init I2C communication.\n";
        return -1;
    }
    std::cout << "I2C communication successfully setup.\n";

  // turn on oscillator
    wiringPiI2CWrite(fd, 0x21);

  // internal RAM powers up with garbage/random values.
  // ensure internal RAM is cleared before turning on display
  // this ensures that no garbage pixels show up on the display
  // when it is turned on.
  clear();
  writeDisplay();

  blinkRate(HT16K33_BLINK_OFF);

  setBrightness(15); // max brightness

  return true;
}

void Adafruit_LEDBackpack::writeDisplay(void) {
  wiringPiI2CWrite (fd, 0x00) ;
	for (int i = 0; i < 8; i++) {
		wiringPiI2CWriteReg8  (fd,i*2,displaybuffer[i] & 0xFF);
		wiringPiI2CWriteReg8  (fd,i*2 + 1,displaybuffer[i] >> 8);
	}
}

void Adafruit_LEDBackpack::clear(void) {
  for (uint8_t i = 0; i < 8; i++) {
    displaybuffer[i] = 0;
  }
}

/******************************* 7 SEGMENT OBJECT */

Adafruit_7segment::Adafruit_7segment(void) { position = 0; }

void Adafruit_7segment::print(std::string &c) { write(c.c_str(), c.length()); }

void Adafruit_7segment::print(const char c[]) { write(c, strlen(c)); }

void Adafruit_7segment::print(char c) { write(c); }

void Adafruit_7segment::print(unsigned long n, int base) {
  if (base == 0)
    write(n);
  else
    printNumber(n, base);
}

void Adafruit_7segment::print(unsigned char b, int base) {
  print((unsigned long)b, base);
}

void Adafruit_7segment::print(int n, int base) { print((long)n, base); }

void Adafruit_7segment::print(unsigned int n, int base) {
  print((unsigned long)n, base);
}

void Adafruit_7segment::println(void) { position = 0; }

void Adafruit_7segment::println(std::string &c) {
   print(c);
   println();
}

void Adafruit_7segment::println(const char c[]) {
  print(c);
  println();
}

void Adafruit_7segment::println(char c) {
  print(c);
  println();
}

void Adafruit_7segment::println(unsigned char b, int base) {
  print(b, base);
  println();
}

void Adafruit_7segment::println(int n, int base) {
  print(n, base);
  println();
}

void Adafruit_7segment::println(unsigned int n, int base) {
  print(n, base);
  println();
}

void Adafruit_7segment::println(long n, int base) {
  print(n, base);
  println();
}

void Adafruit_7segment::println(unsigned long n, int base) {
  print(n, base);
  println();
}

void Adafruit_7segment::println(double n, int digits) {
  print(n, digits);
  println();
}

void Adafruit_7segment::print(double n, int digits) { printFloat(n, digits); }

size_t Adafruit_7segment::write(char c) {

  uint8_t r = 0;

  if (c == '\n')
    position = 0;
  if (c == '\r')
    position = 0;

  if ((c >= ' ') && (c <= 127)) {
    writeDigitAscii(position, c);
    r = 1;
  }

  position++;
  if (position == 2)
    position++;

  return r;
}

size_t Adafruit_7segment::write(const char *buffer, size_t size) {
  size_t n = 0;

  while (n < size) {
    write(buffer[n]);
    n++;
  }

  // Clear unwritten positions
  for (uint8_t i = position; i < 5; i++) {
    writeDigitRaw(i, 0x00);
  }

  return n;
}

void Adafruit_7segment::writeDigitRaw(uint8_t d, uint8_t bitmask) {
  if (d > 4)
    return;
  displaybuffer[d] = bitmask;
}

void Adafruit_7segment::drawColon(bool state) {
  if (state)
    displaybuffer[2] = 0x2;
  else
    displaybuffer[2] = 0;
}

/*
void Adafruit_7segment::writeColon(void) {
  uint8_t buffer[3];

  buffer[0] = 0x04; // start at address $02
  buffer[1] = displaybuffer[2] & 0xFF;
  buffer[2] = displaybuffer[2] >> 8;

  //i2c_dev->write(buffer, 3);
   for(int i = 0;i<3;i++){ 
    wiringPiI2CWrite(fd, buffer[i]);
  }
}*/

void Adafruit_7segment::writeDigitNum(uint8_t d, uint8_t num, bool dot) {
  if (d > 4 || num > 15)
    return;

  if (num >= 10) { // Hex characters
    switch (num) {
    case 10:
      writeDigitAscii(d, 'a', dot);
      break;
    case 11:
      writeDigitAscii(d, 'B', dot);
      break;
    case 12:
      writeDigitAscii(d, 'C', dot);
      break;
    case 13:
      writeDigitAscii(d, 'd', dot);
      break;
    case 14:
      writeDigitAscii(d, 'E', dot);
      break;
    case 15:
      writeDigitAscii(d, 'F', dot);
      break;
    }
  }

  else
    writeDigitAscii(d, num + 48, dot); // use ASCII offset
}

void Adafruit_7segment::writeDigitAscii(uint8_t d, uint8_t c, bool dot) {
  if (d > 4)
    return;

  uint8_t font = sevensegfonttable[c-32];

  writeDigitRaw(d, font | (dot << 7));
}

void Adafruit_7segment::print(long n, int base) { printNumber(n, base); }

void Adafruit_7segment::printNumber(long n, uint8_t base) {
  printFloat(n, 0, base);
}

void Adafruit_7segment::printFloat(double n, uint8_t fracDigits, uint8_t base) {
  uint8_t numericDigits = 4; // available digits on display
  bool isNegative = false;   // true if the number is negative

  // is the number negative?
  if (n < 0) {
    isNegative = true; // need to draw sign later
    --numericDigits;   // the sign will take up one digit
    n *= -1;           // pretend the number is positive
  }

  // calculate the factor required to shift all fractional digits
  // into the integer part of the number
  double toIntFactor = 1.0;
  for (int i = 0; i < fracDigits; ++i)
    toIntFactor *= base;

  // create integer containing digits to display by applying
  // shifting factor and rounding adjustment
  uint32_t displayNumber = n * toIntFactor + 0.5;

  // calculate upper bound on displayNumber given
  // available digits on display
  uint32_t tooBig = 1;
  for (int i = 0; i < numericDigits; ++i)
    tooBig *= base;

  // if displayNumber is too large, try fewer fractional digits
  while (displayNumber >= tooBig) {
    --fracDigits;
    toIntFactor /= base;
    displayNumber = n * toIntFactor + 0.5;
  }

  // did toIntFactor shift the decimal off the display?
  if (toIntFactor < 1) {
    printError();
  } else {
    // otherwise, display the number
    int8_t displayPos = 4;

    for (uint8_t i = 0; displayNumber || i <= fracDigits; ++i) {
      bool displayDecimal = (fracDigits != 0 && i == fracDigits);
      writeDigitNum(displayPos--, displayNumber % base, displayDecimal);
      if (displayPos == 2)
        writeDigitRaw(displayPos--, 0x00);
      displayNumber /= base;
    }

    // display negative sign if negative
    if (isNegative)
      writeDigitRaw(displayPos--, 0x40);

    // clear remaining display positions
    while (displayPos >= 0)
      writeDigitRaw(displayPos--, 0x00);
  }
}

void Adafruit_7segment::printError(void) {
  for (uint8_t i = 0; i < SEVENSEG_DIGITS; ++i) {
    writeDigitRaw(i, (i == 2 ? 0x00 : 0x40));
  }
}