#include "HMC5883L.h"

HMC5883L HMC5883L;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int angle = HMC5883L.getAngle();
  Serial.println(angle);
}
