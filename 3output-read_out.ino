#include <Servo.h>
#include <LIDARLite.h>

Servo servoX;
Servo servoY;
LIDARLite lidar;

int cal_cnt=0;
int Xdegree = 5;
int Ydegree = 165;
int increment = 2;
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
  int rho;
  
LidarProgram:  // LidarProgram is the title that goto statements will go back to
//LIDAR goes to starting position
servoY.write(Ydegree);
servoX.write(Xdegree);
delay(100);
// read a point
rho = lidar.distance();
delay(100);
 // CALCULATIONS
  cal_cnt++;
  cal_cnt = cal_cnt % 100;

  // Calculations
  float theta = Xdegree*3.141/180;
  float phi = (90- (165 - Ydegree))*3.141/180;
  byte x = rho*sin(phi)*cos(theta);
  byte y = rho*sin(phi)*sin(theta);
  byte z = rho*cos(phi);
delay(30);
  double X = x / 3;
  double Y = y / 3;
  double Z = z / 3;
  
  Serial.println(x);
  delay(30);
  Serial.println(y);
  delay(30);
  Serial.println(z);
  delay(30);
  delay(500);

  

  
  /*Serial.print(rho);
  Serial.print("(distance)");
  Serial.print(" ");
  Serial.print("cm");
  Serial.print("       ");
  Serial.print("polar angle(theta) =  ");
  Serial.print(Xdegree);
  Serial.print("  ");
  Serial.print( "azimuthal angle(phi) = ");
  Serial.print(90 -(165 - Ydegree));
  Serial.print("   ");
  Serial.print("Spherical Coordinates");
  Serial.print("  ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(z);
  Serial.print("  ");
  Serial.println("Carteisian Coordinates");*/
  

  delay(1000);

Xdegree = Xdegree + increment;
delay(30);
if (Xdegree < 185) 
{
goto LidarProgram;
}
else
{
  Serial.print("azimuthal angle =");
  Serial.print((90 -(165 - Ydegree)));
  Serial.println(" degrees scan complete");
  if (Ydegree > 90)
  {
  Ydegree = Ydegree - increment;
  Xdegree = 5;
  goto LidarProgram;
}
} 


 
}
