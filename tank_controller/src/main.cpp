#ifndef UNIT_TEST

#ifdef UNIT_TEST
    #include <ArduinoFake.h>
#else
    #include <Arduino.h>
    #include <SoftwareSerial.h>
#endif

#include <MotorControlUtil.h>

// Left motor pins
#define LM_PWM_SPEED 9     
#define LM_IN1 8
#define LM_IN2 7

// Right motor pins
#define RM_PWM_SPEED 3
#define RM_IN3 5
#define RM_IN4 4

int rightspeed = 0;
int leftspeed = 0;

// BLE Serial RX TX
#define RX 11
#define TX 12
#define BAUD_RATE 9600
SoftwareSerial HM18(RX,TX);

char appData;
String inData = "";
MotorValue mValue;


void setup() {
  // Serial.begin(BAUD_RATE);
  HM18.begin(BAUD_RATE);
  Serial.println("HM18 serial started!!!");

  Serial.setTimeout(10);
  HM18.setTimeout(10);

  pinMode(LM_PWM_SPEED, OUTPUT);
  pinMode(LM_IN1, OUTPUT);
  pinMode(LM_IN2, OUTPUT);

  pinMode(RM_PWM_SPEED, OUTPUT);
  pinMode(RM_IN3, OUTPUT); 
  pinMode(RM_IN4, OUTPUT);

  initMotorValue(&mValue);
}


void loop()  {

  // if (HM18.available()) // Read from HM-10 and send to Serial Monitor
  //   Serial.write(HM18.read());
  // if (Serial.available()) // Read from Serial Monitor and send to HM-10
  //   HM18.write(Serial.read());

if(HM18.available() > 0) {
  inData = HM18.readStringUntil('\n');
  inData.trim();
  String deviceValue = parseMotorControlInputValue(inData,':',0);
  String numberValue = parseMotorControlInputValue(inData,':',1);

  parseMotorControlInputDegree(&mValue,numberValue.toInt());
  int rightMotorValue = getRightMotorValue(&mValue);
  int leftMotorValue = getLeftMotorValue(&mValue);

  //gt 0 forward
  if(rightMotorValue > 0) {
    digitalWrite(RM_IN3, HIGH);
    digitalWrite(RM_IN4, LOW);
  } else {
    digitalWrite(RM_IN3, LOW);
    digitalWrite(RM_IN4, HIGH);
  }

  if(leftMotorValue > 0) {
    digitalWrite(LM_IN1, HIGH);
    digitalWrite(LM_IN2, LOW);
  } else {
    digitalWrite(LM_IN1, LOW);
    digitalWrite(LM_IN2, HIGH);
  }

  rightspeed = abs(rightMotorValue);
  leftspeed = abs(leftMotorValue);


}

analogWrite (LM_PWM_SPEED, leftspeed);
analogWrite(RM_PWM_SPEED, rightspeed);

}

#endif