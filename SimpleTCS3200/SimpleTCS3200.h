#ifndef SimpleTCS3200_h
#define SimpleTCS3200_h

#include "Arduino.h"
#include "translateColour.h"

class SimpleTCS3200
{
	public:
	  SimpleTCS3200(int s0, int s1, int s2, int s3, int out);
	  void readColour(int & R, int & G, int & B, int mapeo);
	  void calibrar(translateColour & tc);

	  void setR_limits(int p_0, int p_255) { mapR_0=p_0; mapR_255=p_255; };
	  void setG_limits(int p_0, int p_255) { mapG_0=p_0; mapG_255=p_255; };
	  void setB_limits(int p_0, int p_255) { mapB_0=p_0; mapB_255=p_255; };

	private:
	  int _s0; int _s1; int _s2; int _s3; int _out;
	  int mapR_0 = 305, mapR_255 = 19;
	  int mapG_0 = 350, mapG_255 = 21;
	  int mapB_0 = 290, mapB_255 = 18;
};	  

#endif