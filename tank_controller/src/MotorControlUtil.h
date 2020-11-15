
#ifndef __MotorControlUtil_H
#define __MotorControlUtil_H

#ifdef UNIT_TEST
    #include <ArduinoFake.h>
#else
    #include <Arduino.h>
#endif

typedef struct MotorValue {
    int right;
    int left;
} MotorValue;

String parseMotorControlInputValue(String data, char separator, int index);
void parseMotorControlInputDegree(MotorValue *mValue, int degree);
void initMotorValue(MotorValue *mValue);
int getLeftMotorValue(MotorValue *mValue);
int getRightMotorValue(MotorValue *mValue);

#endif