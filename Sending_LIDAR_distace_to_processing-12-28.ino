#include <Wire.h>

#include <LIDARLite.h>

LIDARLite lidar;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lidar.begin(0, true);
lidar.configure(0);
}

void loop() {
  // put your main code here, to run repeatedly:


Serial.write(lidar.distance() / 4);
delay(200);
}
