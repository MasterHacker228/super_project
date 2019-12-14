#include <PRIZM.h>

#define LEFT 1
#define RIGHT 2

#define CM35 1537
#define DG45 441

PRIZM prizm;

void setup()
{
  prizm.PrizmBegin();
  prizm.setMotorInvert(LEFT, 1);
  Serial.begin(9600);
  prizm.setServoSpeed(1,15);
  prizm.setServoSpeed(2,15);
  prizm.setServoPosition(1, 90);
  prizm.setServoPosition(2, 90);
}

void b()
{
  prizm.resetEncoders();

  int v = 0;
  while (prizm.readEncoderCount(1) < CM35)
  {
    Serial.println(v);
    prizm.setMotorSpeeds(-v, -v);
    if (v < 720) v += 10;
  }

  while (prizm.readEncoderCount(1) < CM35 * 2)
  {
    Serial.println(v);
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
    Serial.println(v);
    prizm.setMotorSpeeds(v, v);
    if (v < 720) v += 10;
  }

  while (-prizm.readEncoderCount(1) < CM35 * 2)
  {
    Serial.println(v);
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
    Serial.println(v);
    prizm.setMotorSpeeds(-v, v);
    if (v < 720) v += 10;
  }
  while (prizm.readEncoderCount(1) < DG45 * 2)
  {
    Serial.println(v);
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
    Serial.println(v);
    prizm.setMotorSpeeds(v, -v);
    if (v < 720) v += 10;
  }

  while (prizm.readEncoderCount(1) > -DG45 * 2)
  {
    Serial.println(v);
    prizm.setMotorSpeeds(v, -v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
}

void kus()
{
  prizm.setServoPosition(1, 135);
  prizm.setServoPosition(2, 45); 
}

void bros()
{
  prizm.setServoPosition(1, 45);
  prizm.setServoPosition(2, 135);
}

void zahvat()
{
  prizm.resetEncoders();

  bros();
  int v = 0;
  while (-prizm.readEncoderCount(1) < 1700)
  {
    Serial.println(v);
    prizm.setMotorSpeeds(v, v);
    if (v < 720) v += 10;
  }

  kus();
  while (-prizm.readEncoderCount(1) < 1700 * 2)
  {
    Serial.println(v);
    prizm.setMotorSpeeds(v, v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
}

void loop()
{

//  delay(6000);



zahvat();

//f();
//r();
//r();
//f();
//f();
  while(1) delay(10);



}
