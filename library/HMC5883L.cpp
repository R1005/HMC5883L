#include "HMC5883L.h"
#include "Arduino.h"
#include "Wire.h"

HMC5883L::HMC5883L(){
  Wire.begin();
}

int HMC5883L::getAngle(){
  int x,y,z;
  int re;
  Wire.beginTransmission(0x1E);
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.requestFrom(0x1E,6);
  
  if(6<=Wire.available()){
    x = Wire.read() << 8; 
    x |= Wire.read(); 
    z = Wire.read() << 8; 
    z |= Wire.read(); 
    y = Wire.read() << 8; 
    y |= Wire.read(); 
  }
  re = atan2((x + 20),(y + 20)*(-1))* RAD_TO_DEG+ 180;
  return re;
}
