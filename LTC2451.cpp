/*==============================================================================================================*
    LTC2451
*===============================================================================================================*

    @file     LTC2451.cpp
    @author   Khaleel Adawy

    LTC2451 Driver (Ultra-Tiny, 16-Bit ∆∑ ADC with I2C Interface)
 
    Ver. 1.0.0 - First release (21.11.24)

*==============================================================================================================*/

#include "LTC2451.h"
#include <stdint.h>

/*==============================================================================================================*
    CONSTRUCTOR
 *==============================================================================================================*/

LTC2451::LTC2451()
{
  add=0x14;
}

LTC2451::LTC2451(int add)
{
  this->add=add;
}

/*==============================================================================================================*
    DESTRUCTOR
 *==============================================================================================================*/

LTC2451::~LTC2451()
{
}

/*==============================================================================================================*
    Begin
 *==============================================================================================================*/

void LTC2451::begin()
{
  Wire.begin();
}

#if defined(ESP32) // if you use esp32 like s3 you can set I2C pins
void LTC2451::begin(int sda, int scl)
{
  Wire.begin(sda,scl);
}
#endif

/*==============================================================================================================*
    Read Analoge Value from ADC 16-bit
 *==============================================================================================================*/

uint16_t LTC2451::readAnalogData() {
  Wire.beginTransmission(add);
  Wire.endTransmission();

  Wire.requestFrom(add, 2); 

  if (Wire.available() == 2) {
    int highByte = Wire.read(); 
    int lowByte = Wire.read();  

    uint16_t adcData = (highByte << 8) | lowByte; 
    return adcData;
  } else {
    return -1; 
  }
}

/*==============================================================================================================*
    Read Anloge and convert it to Voltage
 *==============================================================================================================*/

float LTC2451::readVoltage(float ref) // using specific reference
{
  uint16_t rawData = readAnalogData(); 
  float voltage = (rawData * ref) / 65535.0; 
  return voltage;
}
 

 float LTC2451::readVoltageRef3_3()  //using 3.3V reference (like using esp32, arduino nano33 and other 3.3v MCU ref)
{
  uint16_t rawData = readAnalogData(); 
  float voltage = (rawData * 3.3) / 65535.0; 
  return voltage;
}


 float LTC2451::readVoltageRef5() //using 5v reference (like using arduino uno, mega and other 5V MCU ref )
{
  uint16_t rawData = readAnalogData(); 
  float voltage = (rawData * 5) / 65535.0; 
  return voltage;
}