#include <Servo.h>
#include <LIDARLite.h>
Servo servoX;
Servo servoY;
int degree = 145;
LIDARLite lidar;
int cal_cnt=0;


void setup() {
  // put your setup code here, to run once:
lidar.begin(0,true);
lidar.configure(0);
servoY.attach (6);
servoX.attach (5);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
delay(30);
servoY.write(degree);
servoX.write(5);
delay(1000);
servoX.write(190);
delay(1000);

while (degree >45)
{
  servoX.write(5);
  delay(1000);
  servoX.write(190);
  degree=degree-1;
  servoY.write (degree);
  delay (1000);
}
}
