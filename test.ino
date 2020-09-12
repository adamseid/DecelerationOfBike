#include <Wire.h>
#include <SFE_MMA8452Q.h>


MMA8452Q accel;
float x;
float z;
float calcXZ;



void setup() {
  //Serial.begin(9600);
  pinMode(4,OUTPUT);
  accel.init();
}

void loop() {
  
  lightCondition();
  printCartesianVariables();
  digitalWrite(4,LOW);
}

void printCalculatedAccels()
{ 
  x=accel.cx;
  z=accel.cy;
  calcXZ = -1*atan(x/z);
  x=x-sin(calcXZ);
  calcXZ = calcXZ*(180/3.1415);
}

void lightCondition(){
  float triggerValue;
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
  if (accel.available()){
    accel.read();
    triggerValue = -6.7/9.8;
    if(x < triggerValue){
      digitalWrite(8,HIGH);
      delay(1000);
   }
  } 
    break;
  }
}
