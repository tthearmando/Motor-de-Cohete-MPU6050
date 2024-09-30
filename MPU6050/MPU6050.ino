

#include "Wire.h"
#include "MPU6050.h"    
#include "Servo.h"      
 
MPU6050 mpu; 
int16_t ax, ay, az;  
int16_t gx, gy, gz;  
Servo outer; 
Servo inner;

int valo;     
int prevValo; 

int vali; 
int prevVali; 

void setup() 
{
    Wire.begin(); 
    Serial.begin(38400); 
 
    Serial.println("Initialize MPU");
    mpu.initialize();
    Serial.println(mpu.testConnection() ? "Connected" : "Connection failed"); 
    outer.attach(8); //servo y
    inner.attach(9);//servo x
}
 
void loop() 
{
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
 
    valo = map(ax, -17000, 17000, 179, 0);
    if (valo != prevValo)
    {
        outer.write(valo); 
        prevValo = valo; 
    }
    
     vali = map(ay, -17000, 17000, 179, 0);
    if (vali != prevVali)
    {
        inner.write(vali); 
        prevVali = vali; 
    }
}
