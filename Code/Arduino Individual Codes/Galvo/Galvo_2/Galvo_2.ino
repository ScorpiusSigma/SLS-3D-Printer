#include <Wire.h>

// pin definitions

int lred   = 6;  // blanking pin red 

// variables 

int pause = 50;         // mirror pause
int times = 0;
int grad = 0;
float rad = 0;
float pi = 3.14;

int midx       = 2040;      // master center for x
int midy       = 2040;      // master center for y
int valx       = 2040;      // set the x-coordinate to center
int valy       = 2040;      // set the x-coordinate to center

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(lred,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);

  digitalWrite(lred,  LOW);
  
  black(); // lasers off

} // end void setup

void loop()
{
  green();
  for (times = 0; times < 15; times++)
  {
  for (int grad = 0; grad < 360; grad=grad+10)
  {
   float rad = 2*pi * (grad/360.0);
   valx = cos(rad)*2000 + midx;    
   valy = sin(rad)*2000 + midy;
   setx();
   sety();
  }
  }
  
 } // end loop

//***************************************
//              functions 
//***************************************


void setx()
{
 digitalWrite(2,HIGH);
 Wire.beginTransmission(0x61);  
 Wire.write(64);                // cmd to update the DAC  
 Wire.write(valx >> 4);         // the 8 most significant bits...
 Wire.write((valx & 15) << 4);  // the 4 least significant bits...
 Wire.endTransmission();
 digitalWrite(2,LOW);
}
 
void sety()
{
 digitalWrite(4,HIGH);
 Wire.beginTransmission(0x61);  
 Wire.write(64);                // cmd to update the DAC  
 Wire.write(valy >> 4);         // the 8 most significant bits...
 Wire.write((valy & 15) << 4);  // the 4 least significant bits...
 Wire.endTransmission();
 digitalWrite(4,LOW);
}

void black()
{
 digitalWrite(lred,   LOW); 
}

void green()
{
 digitalWrite(lred,   HIGH);
}
