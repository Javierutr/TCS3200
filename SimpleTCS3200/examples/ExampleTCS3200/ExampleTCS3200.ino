#include <SimpleTCS3200.h>

int R; int G; int B;

SimpleTCS3200 sense(8, 9, 12, 11, 10);

void setup() {
Serial.begin(9600);
}

void loop() {
sense.readColour(R, G, B);
Serial.print("R=");
Serial.print(R);
Serial.print("   G=");
Serial.print(G);
Serial.print("   B=");
Serial.println(B);

delay(300);
}
