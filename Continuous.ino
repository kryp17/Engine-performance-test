 /* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
int flag = 0,dist,count = 1,d_int,alpha = 1;
unsigned long timer,t_int,t;
//char in[4],out[4],tof[4];

String str1,str2,str3;
void setup()
{
  Serial.begin(9600);
  Wire.begin(); 
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();                 
}
void loop()
{   
  if (count == 1)
  {
    Serial.println("Hello");
    d_int=sensor.readRangeContinuousMillimeters();
    t_int = micros();
    
    Serial.print("Initial distance= ");
    Serial.println(d_int);      
    Serial.println(" mm");
    str1=String(d_int);
    //str1.toCharArray(in,4);
    count=0;
  }
  if (alpha==1)
  {
    dist=sensor.readRangeContinuousMillimeters(); 
  if (abs(d_int - dist) >= 20)
  {   
     
      timer = micros(); 
      Serial.print("Final Distance = ");
      Serial.println(dist);
      Serial.println(" mm");
       str2=String(dist);
       //str2.toCharArray(out,4);
     
      
      Serial.print("Time measured = ");
      //(timer-t_int)/1000000.0;
      Serial.println((timer-t_int)/1000000.0);
      Serial.println(" sec");
       str3=String(t);
       //str3.toCharArray(tof,3);
     
      
      //Serial.write(str1);
      //Serial.write(str2);
      //Serial.write(str3);
      
      digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      alpha = 0;
      Serial.println();
  }
  }

}
