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

/*
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
*/


void loop()  {

//BLE 
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
  } else {
    digitalWrite(RM_IN3, LOW);
  }

  if(leftMotorValue > 0) {
    digitalWrite(LM_IN1, HIGH);
  } else {
    digitalWrite(LM_IN1, LOW);
  }

  rightspeed = abs(rightMotorValue);
  leftspeed = abs(leftMotorValue);

/*
  if(deviceValue == "motor2") {
    rightspeed = numberValue.toInt();
  }

  if(deviceValue == "motor1") {
    leftspeed = numberValue.toInt();
  }

  if(rightspeed > 1) {
    digitalWrite(RM_IN3, HIGH);
  } else {
    digitalWrite(RM_IN3, LOW);
  }

  if(leftspeed > 1) {
    digitalWrite(LM_IN1, HIGH);
  } else {
    digitalWrite(LM_IN1, LOW);
  }
  */

}

analogWrite (LM_PWM_SPEED, leftspeed);
analogWrite(RM_PWM_SPEED, rightspeed);

}

#endif