#ifndef SimpleTCS3200_h
#define SimpleTCS3200_h

#include "Arduino.h"

class SimpleTCS3200
{
	public:
	  SimpleTCS3200(int s0, int s1, int s2, int s3, int out);
	  void readColour(int & R, int & G, int & B);
	private:
	  int _s0; int _s1; int _s2; int _s3; int _out; int freq;
};	  

#endif