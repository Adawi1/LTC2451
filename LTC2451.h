/*==============================================================================================================*
    LTC2451
*===============================================================================================================*

    @file     LTC2451.h
    @author   Khaleel Adawy

    LTC2451 Driver (Ultra-Tiny, 16-Bit ∆∑ ADC with I2C Interface)
 
    Ver. 1.0.0 - First release (21.11.24)

*===============================================================================================================*
    INTRODUCTION
*===============================================================================================================*

The LTC®2451 is an ultra-tiny, 16-bit, analog-to-digital converter. The LTC2451 uses a single 2.7V to 5.5V supply,
accepts a single-ended analog input voltage and communicates through an I2C interface. The converter is available in an 8-pin, 3mm × 2mm DFN or TSOT-23 package.
It includes an integrated oscillator that does not require any external components. It uses a delta-sigma modulator as a converter core and provides single-cycle settling time for multiplexed applications.
The LTC2451 includes a proprietary input sampling scheme that reduces the average input sampling current several orders of magnitude lower than conventional ∆∑ converters.

The LTC2451 is capable of up to 60 conversions per second and, due to the very large oversampling ratio, 
has extremely relaxed antialiasing requirements. In the 30Hz mode, the LTC2451 includes continuous internal offset calibration algorithms which are transparent to the user,
ensuring accuracy over time and over the operating temperature range. The converter has external REF+ and REF– pins and the input voltage can range from VREF– to VREF+.
If VREF+ = VCC and VREF– = GND, the input voltage can range from GND to VCC.

Following a single conversion, the LTC2451 can automatically enter sleep mode and reduce its power to less than 0.2µA.
If the user reads the ADC once per second, the LTC2451 consumes an average of less than 50µW from a 2.7V supply.

*===============================================================================================================*
    I2C ADDRESSES
*===============================================================================================================*

    Each LTC2451 has 1 possible I2C addresses (factory hardwired):

    PART               DEVICE I2C ADDRESS          
    NUMBER           BIN         HEX       DEC      
    ---------       -------      ----      ---      
   LTC2451         00010100      0x14       20   


*==============================================================================================================*/


#ifndef LTC2451_H
#define LTC2451_H

#include <Arduino.h>

#include <Wire.h>
#include <stdint.h>


class LTC2451{
private:
int add;
public:

LTC2451();
LTC2451(int add);

~LTC2451();

void begin();

#if defined(ESP32)
void begin(int sda, int scl);
#endif



uint16_t readAnalogData();

float readVoltage(float ref);
float readVoltageRef3_3();
float readVoltageRef5();

};

#endif

