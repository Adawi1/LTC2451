/* 
  LTC2451 LIBRARY BY: Khaleel Adawy - Voltage Measure From ADC Analog Read EXAMPLE
  ----------------------------------------------
  
  INTRODUCTION
  ------------
  This sketch is a simple code to measure voltage from analoge value using ADC I2C IC (LTC2451)
  
    IMPORTANT: The LTC2451 library depends on the Arduino IDE's native 'Wire' library for I2C communication between the Arduino (Master) and the LTC2451 (Slave).

  WIRING DIAGRAM
  --------------
                                       LTC2451
                                       -------
                                GND --| •     |-- SDA
                                      |       |
                               -Ref --|       |-- SCL
                                      |       |
                               +Ref --|       |-- IN
                                      |       |
                                Vcc --|       |-- GND
                                       -------

  PIN 1 (GND)  - Connect to MCU GNG.
  PIN 2 (-REF) - Connect to -V ref or GND MUC (IF YOUR REF IS MCU VOLTAGE).
  PIN 3 (+REF) - Connect to +V ref or Vcc MUC (IF YOUR REF IS MCU VOLTAGE).
  PIN 4 (VCC)  - Connect to MCU VCC.
  PIN 5 (SDA)  - Connect to MCU SDA.
  PIN 6 (SCL)  - Connect to MCU SCL.
  PIN 7 (IN)   - Connect to Voltage Source between +Ref and -Ref.
  PIN 8 (GND)  - Connect to MCU GND.
 
The initial addres for LTC2451 is 0x14, but you can change it from pass new add using Constructors parameter
*/

//uncommant this line if you need change addres, and put your addrea.
//#define addr 0x14 

//uncommant this lines if you use a I2C spical Pins (LIKE USE ESP32 S3).
//#define sda 18
//#define scl 17

//uncommant this line if you have a spical voltage referenc.
//float ref = 1.8;


#include <LTC2451.h>

LTC2451 adc1;
//LTC2451 adc1(addr);


void setup() {

adc1.begin();
//adc1.begin(sda,scl);

Serial.begin(115200);
}

void loop() {

  //for read frome ADC Analoge Value, using spical referenc.
  //float adcVoltage =adc1.readVoltage(ref); 

  //for read frome ADC Analoge Value, using 5V referenc.
  //float adcVoltage =adc1.readVoltageRef5(); 

  //for read frome ADC Analoge Value, using spical referenc.
  float adcVoltage =adc1.readVoltageRef3_3(); 


Serial.println(adcVoltage);
delay(1000);
}
