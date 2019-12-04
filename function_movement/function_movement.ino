#include <PRIZM.h>

#define LEFT 1
#define RIGHT 2

#define CM35 1637
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

void loop()
{
  l();
  f();
  r();
  f();
  f();
  f();
  b();
  b();
  b();
  l();
  b();
  r();
}
