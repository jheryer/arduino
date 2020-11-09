
#ifndef __STRING_PARSE_H
#define __STRING_PARSE_H

#ifdef UNIT_TEST
    #include <ArduinoFake.h>
#else
    #include <Arduino.h>
#endif

String parseValue(String data, char separator, int index);


#endif