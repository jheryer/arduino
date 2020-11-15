#include "MotorControlUtil.h"

String parseMotorControlInputValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

int getLeftMotorValue(MotorValue *mValue) {
  return mValue->left;
}

int getRightMotorValue(MotorValue *mValue) {
  return mValue->right;
}

void initMotorValue(MotorValue *mValue) {
  mValue->right = 0;
  mValue->left = 0;
}

void parseMotorControlInputDegree(MotorValue *mValue, int degree)
{

  //Forward
  if (degree >= 65 && degree < 115)
  {
    mValue->right = 255;
    mValue->left = 255;
  }
  //FORWARD RIGHT
  if (degree >= 115 && degree < 170)
  {
    mValue->right = 128;
    mValue->left = 255;
  }
  // ROTATE RIGHT
  if (degree >= 170 && degree < 190)
  {
    mValue->right = -255;
    mValue->left = 255;
  }
  // BACK RIGHT
  if (degree >= 190 && degree < 255)
  {
    mValue->right = -128;
    mValue->left = -255;
  }
  // BACK
  if (degree >= 255 && degree < 300)
  {
    mValue->right = -255;
    mValue->left = -255;
  }
  //BACK LEFT
  if (degree >= 300 && degree < 350)
  {
    mValue->right = -255;
    mValue->left = -128;
  }

  // LEFT
  if (degree >= 350 && degree <= 360)
  {
    mValue->right = 255;
    mValue->left = -255;
  }
  // LEFT
  if (degree >= 0 && degree < 10)
  {
    mValue->right = 255;
    mValue->left = -255;
  }
  //Forward Left
  if (degree >= 10 && degree < 65)
  {
    mValue->right = 255;
    mValue->left = 128;
  }
}

/*

 Angle Value:

 motor1(L) | motor2 (R)

 

 // MOVE FORWARD

 if value is between 45 and 135

    motor1 = 255

    motor2 = 255

 

 //TURN RIGHT

 if value is between 135 and 180

    motor1 = 255

    motor2 = 128

 

 // ROTATE RIGHT

 if value is between 135 and 179

    motor1 = 255

    motor2 = 0

 

 //REVRSE TURN RIGHT

 if value is between 180 and 225

    motor1 = 128

    motor2 = -128

 

 // MOVE BACKWARDS

 if value is between 225 and 315

    motor1 = -255

    motor2 = -255

 

 //REVRSE TURN LEFT

 if value is between 315 and 0

    motor1 = -128

    motor2 = 128

 

 // ROTATE LEFT

 if value is between 135 and 179

    motor1 = 0

    motor2 = 255

 

 // TURN LEFT

 if value is between 0 and 45

    motor1 = 128

    motor2 = 255

 */
