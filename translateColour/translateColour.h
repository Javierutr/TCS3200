#ifndef translateColour_h
#define translateColour_h

#include "Arduino.h"

class translateColour
{
	public:
		translateColour() {
		    tol = 30;
		    RED[0] =230; RED[1]=160; RED[2]=170;
            GREEN[0]=205; GREEN[1]=230; GREEN[2]=195;
            //YELLOW[0]=255; YELLOW[1]=250; YELLOW[2]=230;
            WHITE[0]=245; WHITE[1]=245;WHITE[2]=245;
            BLUE[0]=100; BLUE[1]=170; BLUE[2]=200;
		};
		void whatColour(int R,int G,int B,char & color);

	private:
	    int RED[3];
	    int GREEN[3];
        int YELLOW[3];
        int WHITE[3];
        int BLUE[3];
        int tol;
};

#endif
