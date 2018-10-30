//Using SimpleTCS3200, this library will sense and map the current colour
//to experimental calibration values in the 0-255 range. 
//Usage: readColor(R,G,B) convierte las variables R,G,B en los valores correspondientes.

#include "Arduino.h"
#include "SimpleTCS3200.h"

SimpleTCS3200::SimpleTCS3200(int s0, int s1, int s2, int s3, int out)
{
  pinMode(s0,OUTPUT); pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT); pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  _s0 = s0; _s1 = s1; _out = out; _s2 = s2; _s3 = s3;
}

void SimpleTCS3200::readColour(int & R, int & G, int & B)
{
  digitalWrite(_s0,HIGH);
  digitalWrite(_s1,LOW);
    
	
  digitalWrite(_s2,LOW);
  digitalWrite(_s3,LOW);

  freq = pulseIn(_out, LOW);
  freq = map(freq, 305, 19, 0, 255);
  R=freq;
  
  digitalWrite(_s2,HIGH);
  digitalWrite(_s3,HIGH);

  freq = pulseIn(_out, LOW);
  freq = map(freq, 350, 21, 0, 255);
  G=freq;  
  
  digitalWrite(_s2,LOW);
  digitalWrite(_s3,HIGH);

  freq = pulseIn(_out, LOW);
  freq = map(freq, 290, 18, 0, 255);
  B=freq;  
 
}