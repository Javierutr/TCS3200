#include <SimpleTCS3200.h>
#include <translateColour.h>

int R=0, G=0, B=0;
char color;

SimpleTCS3200 sensor(8,9,10,11,12);
translateColour traducir(40);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
sensor.calibrar(traducir);
}

void loop() {
  // put your main code here, to run repeatedly:
sensor.readColour(R,G,B,0);
Serial.print(R); Serial.print("  ");
Serial.print(G); Serial.print("  ");
Serial.println(B); Serial.print("  ");
traducir.whatColour(R,G,B,color);
Serial.println(color);
delay(300);
}
