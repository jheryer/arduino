#include <Arduino.h>

// Left motor pins
#define LM_PWM_SPEED 9     
#define LM_IN1 8
#define LM_IN2 11

// Right motor pins
#define RM_PWM_SPEED 10
#define RM_IN3 12
#define RM_IN4 13

int rightspeed = 230;
int leftspeed = 230;

void setup() {

  pinMode (LM_PWM_SPEED, OUTPUT);
  pinMode(LM_IN1, OUTPUT);
  pinMode(LM_IN2, OUTPUT);

  pinMode(RM_PWM_SPEED, OUTPUT);
  pinMode(RM_IN3, OUTPUT); 
  pinMode(RM_IN4, OUTPUT);

  analogWrite (LM_PWM_SPEED, leftspeed);
  analogWrite(RM_PWM_SPEED, rightspeed);

}

void loop()  {

  digitalWrite(LM_IN1, HIGH);
  digitalWrite(LM_IN2, LOW);

  digitalWrite(RM_IN3, HIGH);
  digitalWrite(RM_IN4, LOW); 

}