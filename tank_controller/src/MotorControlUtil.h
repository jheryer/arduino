
#ifndef __MotorControlUtil_H
#define __MotorControlUtil_H

#ifdef UNIT_TEST
    #include <ArduinoFake.h>
#else
    #include <Arduino.h>
#endif

String parseValue(String data, char separator, int index);


#endif