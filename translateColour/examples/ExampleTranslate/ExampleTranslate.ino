#include <translateColour.h>

int R; int G; int B;
char color;

translateColour idColour;

void setup() {
Serial.begin(9600);
}

void loop() {
R=100; 
G=200;
B=100;
idColour.whatColour(R, G, B, color);
Serial.print("R=");
Serial.print(R);
Serial.print("   G=");
Serial.print(G);
Serial.print("   B=");
Serial.println(B);
Serial.println(color);


delay(300);
}
