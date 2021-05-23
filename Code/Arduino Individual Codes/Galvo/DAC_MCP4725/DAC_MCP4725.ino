#include <Wire.h>
//MCP4725 library
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup() 
{
  
  Serial.begin(9600);//Start Serial
  dac.begin(0x61);//Start DAC. DAC address 0x61(Pin A0 HIGH)

  //Pin Settings
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

}

void loop()
{
  
  
}
