///Given a RGB colour value (0-255)
//this library will compare with previously defined (in this library) colors.
//Example: #include "translateColour.h"
//whatColour(R, G, B, colour), being colour a char.

#include "Arduino.h"
#include "translateColour.h"


void translateColour::whatColour(int R, int G, int B, char & color)
{
	if ( ((R-tol<RED[0])&&(G-tol<RED[1]) && (B-tol<RED[2]))  &&
(   (R+tol>RED[0])&&(G+tol>RED[1]) && (B+tol>RED[2])  )      )
{
  Serial.println('R');
  color = 'R';
}

else if (     ((R-tol<GREEN[0])&&(G-tol<GREEN[1]) && (B-tol<GREEN[2]))  &&
(   (R+tol>GREEN[0])&&(G+tol>GREEN[1]) && (B+tol>GREEN[2])  )      )
{
  Serial.println('G');
  color = 'G';
}

else if (     ((R-tol<YELLOW[0])&&(G-tol<YELLOW[1]) && (B-tol<YELLOW[2]))  &&
(   (R+tol>YELLOW[0])&&(G+tol>YELLOW[1]) && (B+tol>YELLOW[2])  )      )
{
  Serial.println('Y');
  color = 'Y';
}

else if (     ((R-tol<WHITE[0])&&(G-tol<WHITE[1]) && (B-tol<WHITE[2]))  &&
(   (R+tol>WHITE[0])&&(G+tol>WHITE[1]) && (B+tol>WHITE[2])  )      )
{
  Serial.println('W');
  color = 'W';
}

else if (     ((R-tol<BLUE[0])&&(G-tol<BLUE[1]) && (B-tol<BLUE[2]))  &&
(   (R+tol>BLUE[0])&&(G+tol>BLUE[1]) && (B+tol>BLUE[2])  )      )
{
  Serial.println('B');
  color = 'B';
}
else {
	color= 'N';
}
}