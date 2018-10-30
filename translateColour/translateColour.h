#ifndef translateColour_h
#define translateColour_h

#include "Arduino.h"

class translateColour
{
	public:
		translateColour();
		void whatColour(int R,int G,int B,char & color);
		
	private:
		int _R; int _G; int _B; int WHITE[3]; int YELLOW[3];
		int RED[3]; int GREEN[3]; int BLUE[3]; int tol;
	
};

#endif