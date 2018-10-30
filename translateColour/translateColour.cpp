//Given a RGB colour value (0-255)
//this library will compare with previously defined (in this library) colors.
//Example: #include "translateColour.h"
//whatColour(R, G, B, colour), being colour a char.

#include "translateColour.h"
#include "Arduino.h"

translateColour::translateColour()
{
int RED[3]={245,180,190};
int GREEN[3]={205,230,195};
int YELLOW[3]={255,250,230};
int WHITE[3]={255,255,255};
int BLUE[3]={193,203,234};
int tol=20;
}

void translateColour::whatColour(int R, int G, int B, char & color)
{
	if (      ((R-tol<RED[0])&&(G-tol<RED[1]) && (B-tol<RED[2]))  &&
(   (R+tol>RED[0])&&(G+tol>RED[1]) && (B+tol>RED[2])  )      )  
{
  Serial.println("   RED");
}

else if (     ((R-tol<GREEN[0])&&(G-tol<GREEN[1]) && (B-tol<GREEN[2]))  &&
(   (R+tol>GREEN[0])&&(G+tol>GREEN[1]) && (B+tol>GREEN[2])  )      )  
{
  Serial.println("   GREEN");
}

else if (     ((R-tol<YELLOW[0])&&(G-tol<YELLOW[1]) && (B-tol<YELLOW[2]))  &&
(   (R+tol>YELLOW[0])&&(G+tol>YELLOW[1]) && (B+tol>YELLOW[2])  )      )  
{
  Serial.println("   YELLOW");
}

else if (     ((R-tol<WHITE[0])&&(G-tol<WHITE[1]) && (B-tol<WHITE[2]))  &&
(   (R+tol>WHITE[0])&&(G+tol>WHITE[1]) && (B+tol>WHITE[2])  )      )  
{
  Serial.println("   WHITE");
}

else if (     ((R-tol<BLUE[0])&&(G-tol<BLUE[1]) && (B-tol<BLUE[2]))  &&
(   (R+tol>BLUE[0])&&(G+tol>BLUE[1]) && (B+tol>BLUE[2])  )      )  
{
  Serial.println("   BLUE");
}
}