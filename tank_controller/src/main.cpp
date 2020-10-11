#include <Arduino.h>
#include <SoftwareSerial.h>


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

// BLE Serial RX TX
#define RX 2
#define TX 3
#define BAUD_RATE 9600
SoftwareSerial HM18(RX,TX);

char appData;
String inData = "";


#define BLUE_LED 10
#define RED_LED 9

int blue_brightness = 0;
int red_brightness = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  
  HM18.begin(BAUD_RATE);
   Serial.println("HM18 serial started!!!");

  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.setTimeout(10);
  HM18.setTimeout(10);

/*
  pinMode (LM_PWM_SPEED, OUTPUT);
  pinMode(LM_IN1, OUTPUT);
  pinMode(LM_IN2, OUTPUT);

  pinMode(RM_PWM_SPEED, OUTPUT);
  pinMode(RM_IN3, OUTPUT); 
  pinMode(RM_IN4, OUTPUT);

  analogWrite (LM_PWM_SPEED, leftspeed);
  analogWrite(RM_PWM_SPEED, rightspeed);
*/



}


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



void loop()  {

// HM18.write("test");
analogWrite(BLUE_LED, blue_brightness);
analogWrite(RED_LED, red_brightness);

//BLE 
  // if (HM18.available()) // Read from HM-10 and send to Serial Monitor
  //   Serial.write(HM18.read());
  // if (Serial.available()) // Read from Serial Monitor and send to HM-10
  //   HM18.write(Serial.read());

if(HM18.available() > 0) {
  inData = HM18.readStringUntil('\n');
  inData.trim();

   String deviceValue = getValue(inData,':',0);
  String numberValue = getValue(inData,':',1);

  if(deviceValue == "motor1") {
    blue_brightness = numberValue.toInt();
  }

  if(deviceValue == "motor2") {
    red_brightness = numberValue.toInt();
  }
  
  //Serial.println(inData);
  



}


  // if(HM18.available()) {
  //   //Serial.println("yep!!");
  //   HM18.write("hello world");  
  //   appData = HM18.read();
  //   Serial.write(appData);
  // }


//delay(10);
/*
  digitalWrite(LM_IN1, HIGH);
  digitalWrite(LM_IN2, LOW);

  digitalWrite(RM_IN3, HIGH);
  digitalWrite(RM_IN4, LOW); 
*/
}

