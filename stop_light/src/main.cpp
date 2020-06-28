#include <Arduino.h>

#define LIGHT_1_RED 12
#define LIGHT_1_YELLOW 11
#define LIGHT_1_GREEN 10
#define LIGHT_2_RED 2
#define LIGHT_2_YELLOW 1
#define LIGHT_2_GREEN 0

#define BUTTON_1 13
#define BUTTON_2 3

int ENABLED_LIGHT = 0;

void setup() {
  pinMode(LIGHT_1_RED, OUTPUT);
  pinMode(LIGHT_1_YELLOW, OUTPUT);
  pinMode(LIGHT_1_GREEN, OUTPUT);
  pinMode(BUTTON_1, INPUT);
  pinMode(LIGHT_2_RED, OUTPUT);
  pinMode(LIGHT_2_YELLOW, OUTPUT);
  pinMode(LIGHT_2_GREEN, OUTPUT);
  pinMode(BUTTON_2, INPUT); 
}

void light_1_sequence() {
   digitalWrite(LIGHT_1_RED, LOW);
   digitalWrite(LIGHT_1_GREEN, HIGH);
   delay(1000);
   digitalWrite(LIGHT_1_GREEN, LOW);
   digitalWrite(LIGHT_1_YELLOW, HIGH);
   delay(1000);
   digitalWrite(LIGHT_1_YELLOW, LOW);
   digitalWrite(LIGHT_1_RED, HIGH);
    delay(1000);
   digitalWrite(LIGHT_2_RED, LOW);
   digitalWrite(LIGHT_2_GREEN, HIGH);
}

void light_2_sequence() {
   digitalWrite(LIGHT_2_RED, LOW);
   digitalWrite(LIGHT_2_GREEN, HIGH);
   delay(1000);
   digitalWrite(LIGHT_2_GREEN, LOW);
   digitalWrite(LIGHT_2_YELLOW, HIGH);
   delay(1000);
   digitalWrite(LIGHT_2_YELLOW, LOW);
   digitalWrite(LIGHT_2_RED, HIGH);
   delay(1000);
   digitalWrite(LIGHT_1_RED, LOW);
   digitalWrite(LIGHT_1_GREEN, HIGH);
}



void loop() {
  if(digitalRead(BUTTON_1) == HIGH && ENABLED_LIGHT != 1) {
    light_2_sequence();
    ENABLED_LIGHT = 1;
  }

  if(digitalRead(BUTTON_2) == HIGH && ENABLED_LIGHT != 2) {    
    light_1_sequence();
    ENABLED_LIGHT = 2;
  }
  

}

