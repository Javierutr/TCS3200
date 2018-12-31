//Using SimpleTCS3200, this library will sense and map the current colour
//to experimental calibration values in the 0-255 range. 
//Usage: readColor(R,G,B) convierte las variables R,G,B en los valores correspondientes.

#include "Arduino.h"
#include "SimpleTCS3200.h"

SimpleTCS3200::SimpleTCS3200(int s0, int s1, int s2, int s3, int out)
{
  pinMode(s0,OUTPUT); 
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT); 
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);

  _s0 = s0; _s1 = s1; _s2 = s2; _s3 = s3;
  _out = out;
}

void SimpleTCS3200::readColour(int & R, int & G, int & B, int mapeo)
{
  digitalWrite(_s0,HIGH);
  digitalWrite(_s1,LOW);
  digitalWrite(_s2,LOW);
  digitalWrite(_s3,LOW);

  R = pulseIn(_out, LOW);
  if (mapeo==0) {
    R = map(R, mapR_0, mapR_255, 0, 255); 
  }

  digitalWrite(_s2,HIGH);
  digitalWrite(_s3,HIGH);

  G = pulseIn(_out, LOW);
  if (mapeo==0) {
    G = map(G, mapG_0, mapG_255, 0, 255); 
  }

  digitalWrite(_s2,LOW);
  digitalWrite(_s3,HIGH);

  B = pulseIn(_out, LOW);
  if (mapeo==0) {
    B = map(B, mapB_0, mapB_255, 0, 255);
  }
   
}

void SimpleTCS3200::calibrar(translateColour & tc) {
  
  int R,G,B;
  int RED[3], GREEN[3], BLUE[3], WHITE[3];
  int i;
  

  Serial.println("Lee algo negro y pulsa el botón");
  delay(1000);
    for (i=1;i<300;i++){
  readColour(R,G,B,1);
  }
  int R_map0=R, G_map0=G, B_map0=B;
  
  Serial.print(R_map0); Serial.print("  ");   Serial.print(G_map0); Serial.print("  "); Serial.print(B_map0); Serial.print("  ");

  Serial.println("Lee algo rojo");
  delay(5000);
    for (i=1;i<100;i++){
  readColour(R,G,B,1);
  }
    //int R_map255=R; 
  RED[0]=R; RED[1]=G; RED[2]=B;
  
  Serial.print(RED[0]); Serial.print("  ");  Serial.print(RED[1]); Serial.print("  "); Serial.print(RED[2]); Serial.print("  ");

  Serial.println("Lee algo verde");
  delay(5000);
  for (i=1;i<100;i++){
  readColour(R,G,B,1);
  }
  //int G_map255=G; 
  GREEN[0]=R; GREEN[1]=G; GREEN[2]=B;

  Serial.println("Lee algo Azul");
  delay(5000);
  for (i=1;i<100;i++){
  readColour(R,G,B,1);
  }
  //int B_map255=B
  BLUE[0]=R; BLUE[1]=G; BLUE[2]=B;

  Serial.println("Lee algo blanco");
  delay(5000);
  readColour(R,G,B,1);
  WHITE[0]=R; WHITE[1]=G; WHITE[2]=B;
  int B_map255=B; int G_map255=G; int R_map255=R;  

  setR_limits(R_map0,R_map255); 
  setG_limits(G_map0,G_map255); 
  setB_limits(B_map0,B_map255); 
  
  

  RED[0]=map(RED[0], R_map0, R_map255,0,255);
  RED[1]=map(RED[1], G_map0, G_map255,0,255);
  RED[2]=map(RED[2], B_map0, B_map255,0,255);
  
 Serial.print(RED[0]); Serial.print("  ");  Serial.print(RED[1]); Serial.print("  ");


  GREEN[0]=map(GREEN[0], R_map0, R_map255,0,255);
  GREEN[1]=map(GREEN[1], G_map0, G_map255,0,255);
  GREEN[2]=map(GREEN[2], B_map0, B_map255,0,255);

  BLUE[0]=map(BLUE[0], R_map0, R_map255,0,255);
  BLUE[1]=map(BLUE[1], G_map0, G_map255,0,255);
  BLUE[2]=map(BLUE[2], B_map0, B_map255,0,255);

  WHITE[0]=map(WHITE[0], R_map0, R_map255,0,255);
  WHITE[1]=map(WHITE[1], G_map0, G_map255,0,255);
  WHITE[2]=map(WHITE[2], B_map0, B_map255,0,255);

  tc.set_R(RED[0],RED[1],RED[2]);
  tc.set_G(GREEN[0],GREEN[1],GREEN[2]);
  tc.set_B(BLUE[0],BLUE[1],BLUE[2]);
  tc.set_W(WHITE[0],WHITE[1],WHITE[2]);

}
