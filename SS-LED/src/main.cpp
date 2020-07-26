#include <Arduino.h>
#include <Arduino.h>

#define DATA 6
#define LATCH 8
#define CLOCK 10

#define number 6

int digits[] = {63,24,115,121,92,109,111,25,127,125};

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop() {
  
  int i;
  for(i = 0; i < 10; i++) {
    digitalWrite(LATCH,LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, digits[i]);
    digitalWrite(LATCH, HIGH);
    delay(1000);
  }
}