#include <PRIZM.h>

#define LEFT 1
#define RIGHT 2

#define CM35 1537
#define DG45 441

PRIZM prizm;          // Instantiate an object named prizm

void setup()
{
  prizm.PrizmBegin(); // Initiates the PRIZM controller - must be called in the setup of each PRIZM sketch
  prizm.setMotorInvert(LEFT, 1);
  Serial.begin(9600);
}

void b()
{
  prizm.resetEncoders();

  int v = 0;
  while (prizm.readEncoderCount(1) < CM35)
  {
    prizm.setMotorSpeeds(-v, -v);
    if (v < 720) v += 10;
  }
  //prizm.resetEncoders();

  while (prizm.readEncoderCount(1) < CM35 * 2)
  {
    prizm.setMotorSpeeds(-v, -v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
}

void f()
{
  prizm.resetEncoders();

  int v = 0;
  while (-prizm.readEncoderCount(1) < CM35)
  {
    prizm.setMotorSpeeds(v, v);
    if (v < 720) v += 10;
  }

  while (-prizm.readEncoderCount(1) < CM35 * 2)
  {
    prizm.setMotorSpeeds(v, v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
}

void l()
{
  prizm.resetEncoders();

  int v = 0;
  while (prizm.readEncoderCount(1) < DG45)
  {
    prizm.setMotorSpeeds(-v, v);
    if (v < 720) v += 10;
  }
  while (prizm.readEncoderCount(1) < DG45 * 2)
  {
    prizm.setMotorSpeeds(-v, v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
}

void r()
{
  prizm.resetEncoders();

  int v = 0;
  while (prizm.readEncoderCount(1) > -DG45)
  {
    prizm.setMotorSpeeds(v, -v);
    if (v < 720) v += 10;
  }

  while (prizm.readEncoderCount(1) > -DG45 * 2)
  {
    prizm.setMotorSpeeds(v, -v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
}


void kd()
{
  prizm.setServoPosition(1, 160);//опустить ковш
  prizm.setServoPosition(2, 160);
  prizm.setServoPosition(3, 20);
  delay(100);
  prizm.setServoPosition(5, 90);//открыт захват
}

void ku()
{
  prizm.setServoPosition(5, 0);//захват закрыт
  delay(100);
  prizm.setServoPosition(1, 90);//поднять ковш
  prizm.setServoPosition(2, 90);
  prizm.setServoPosition(3, 90);
}





void loop()
{

//  delay(5000);


f();
kd();
f();
ku();
r();
r();
f();
f();




}
