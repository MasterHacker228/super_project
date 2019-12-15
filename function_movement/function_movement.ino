#include <PRIZM.h>

#define LEFT 1
#define RIGHT 2

#define CM35 1525
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
//    Serial.println(v);
    prizm.setMotorSpeeds(-v, -v);
    if (v < 720) v += 10;
  }

  while (prizm.readEncoderCount(1) < CM35 * 2)
  {
//    Serial.println(v);
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
//    Serial.println(v);
    prizm.setMotorSpeeds(v, v);
    if (v < 720) v += 10;
  }

  while (-prizm.readEncoderCount(1) < CM35 * 2)
  {
//    Serial.println(v);
    prizm.setMotorSpeeds(v, v);
    if (v > 0) v -= 12;
  }
  prizm.setMotorSpeeds(0, 0);
}

void l()
{
  prizm.resetEncoders();

  int v = 0;
  while (prizm.readEncoderCount(1) < DG45)
  {
//    Serial.println(v);
    prizm.setMotorSpeeds(-v, v);
    if (v < 720) v += 10;
  }
  while (prizm.readEncoderCount(1) < DG45 * 2)
  {
//    Serial.println(v);
    prizm.setMotorSpeeds(-v, v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
  delay(100);
}

void r()
{
  prizm.resetEncoders();

  int v = 0;
  while (prizm.readEncoderCount(1) > -DG45)
  {
//    Serial.println(v);
    prizm.setMotorSpeeds(v, -v);
    if (v < 720) v += 10;
  }

  while (prizm.readEncoderCount(1) > -DG45 * 2)
  {
//    Serial.println(v);
    prizm.setMotorSpeeds(v, -v);
    if (v > 0) v -= 13;
  }
  prizm.setMotorSpeeds(0, 0);
  delay(100);
}

void kus()
{
  prizm.setServoPosition(1, 135);
  prizm.setServoPosition(2, 45); 
  delay(1000);
}

void bros()
{
  prizm.setServoPosition(1, 90);
  prizm.setServoPosition(2, 1200);
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
int i = 0;
void loop()
{
 prizm.setRedLED(HIGH); 
//  while(3)//
//  f();//
//  while(3) delay(10);//
 delay(5500);
  l();
  if(prizm.readSonicSensorCM(3) < 30)
  {
    bros();
    r();
    f();//выезд

    for(; i<5 ; i++)
    {
      
      delay(1000);
      
      prizm.setRedLED(HIGH);
      delay(1000);
      prizm.setRedLED(LOW);
      Serial.println(i);
      if(prizm.readSonicSensorCM(3) < 30)
      {
        
        l();
        f();
        r();
        delay(1000);
        bros();
        prizm.setRedLED(HIGH);
        delay(1000);
        prizm.setRedLED(LOW);
        continue;
      }
      f();//мусор
      kus();
      b();
      l();
      Serial.println(i);
      for(int j=0; j<5-i-1 ;j++)
      {
        bros();
        f();
      }
      l();
      f();
      bros();
      b();
      kus();
      l();
      for(int j=0; j<5-i-2;j++)
      {
        f();
      }
      l();
    }
    //возвращение на финиш
    r();
    for(int j=0; j<4; j++)
    {
      f();
    }
    r();
    f();
  }
  else
  {
    //2 поле
bros();
    r();
    f();//выезд
    
    for(; i<5 ; i++)
    {
      
      delay(1000);
      bros();
      prizm.setRedLED(HIGH);
      delay(1000);
      prizm.setRedLED(LOW);
      Serial.println(i);
      if(prizm.readSonicSensorCM(3) < 35)
      {
        bros();
        r();
        f();
        l();
        
        delay(1000);
        bros();
        prizm.setRedLED(HIGH);
        delay(1000);
        prizm.setRedLED(LOW);
        continue;
      }
      bros();   
      f();  //мусор
      kus();
      b();
      r();
      Serial.println(i);
      for(int j=0; j<5-i-1 ;j++)
      {
        bros();
        f();
      }
      r();
      f();
      bros();
      b();
      kus();
      r();
      for(int j=0; j<5-i-2;j++)
      {
        f();
      }
      r();
    }
    //возвращение на финиш
    l();
    for(int j=0; j<4; j++)
    {
      f();
    }
    l();
    f();
  }
  
  while(1) delay(10);
}
