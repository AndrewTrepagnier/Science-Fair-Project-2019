#include <Servo.h>
#include <LIDARLite.h>

Servo servoX;
Servo servoY;
LIDARLite lidar;

int cal_cnt=0;
int Xdegree = 5;
int Ydegree = 165;

void setup()
{
  Serial.begin(9600); // Initialize serial connection to display distance readings
  servoY.attach (6);
  servoX.attach (5);
  lidar.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidar.configure(0); // Change this number to try out alternate configurations
}

void loop()
{
  int Elangle = 0;
  int dist;
  int AZangle = 0;
LidarProgram:  // LidarProgram is the title that goto statements will go back to
//LIDAR goes to starting position
servoY.write(Ydegree);
servoX.write(Xdegree);
delay(100);
// read a point
dist = lidar.distance();
delay(100);
 // CALCULATIONS
  cal_cnt++;
  cal_cnt = cal_cnt % 100;

  // Display distance
  float azimuth = Xdegree*3.141/180;
  float elevation = (165 - Ydegree)*3.141/180;
  double x = dist*sin(elevation)*cos(azimuth);
  double y = dist*sin(elevation)*sin(azimuth);
  double z = dist*cos(elevation);
delay(30);
  
  //Serial.println(String(-x, 5)+""+String(y,5) + "" +String (-z,5));
  //print coordinates
  
  Serial.print(dist);
  Serial.print(" ");
  Serial.print("cm");
  Serial.print("        ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(z);
  Serial.print(" ");
  Serial.println("carteisian coordinates");
  //Serial.println(" cm");

  delay(500);

Xdegree = Xdegree + 5;
delay(30);
if (Xdegree < 185) 
{
goto LidarProgram;
}
else
{
  Serial.println("level scan done");
  if (Ydegree > 85)
  {
  Ydegree = Ydegree-5;
  Xdegree = 5;
  goto LidarProgram;
}
}
}

