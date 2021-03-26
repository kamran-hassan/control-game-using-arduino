#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);   //start the serial communication
  Wire.begin();         // start I2C communication for comunicating with MPU6050
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(A1,INPUT);            // throttle button signal pin
  pinMode(A0,INPUT);            // brake button signal pin
}

void loop() {
  mpu6050.update();
  if(mpu6050.getAngleZ()>25 && digitalRead(A0))   // check if forward(throttle) and left
   Serial.println('q');                           // print 'q' on the serial port
  else if(mpu6050.getAngleZ()<-25 && digitalRead(A0))   // check if forward(throttle) and right
   Serial.println('e');                                 // print 'e' on the Serial Port
  else if(mpu6050.getAngleZ()>25 && digitalRead(A1))    // check if backward(brake) and left 
   Serial.println('z');                                 // print 'z' on the Serial Port
  else if(mpu6050.getAngleZ()<-25 && digitalRead(A1))   // check if backward(brake) and right 
   Serial.println('c');                                 // print 'c' on the Serial Port 
  else if(digitalRead(A0))                              // check if forward(throttle)
   Serial.println('w');                                 // print 'w' on the serial port
  else if(digitalRead(A1))                              // check if backward(brake)
   Serial.println('s');                                 // print 's' on the Serial 
  else if(mpu6050.getAngleZ()>25)                       // check if left 
  Serial.println('a');                                  // print 'a' on the Serial Port
  else if(mpu6050.getAngleZ()<-25)                      // check if right
  Serial.println('d');                                  // print 'd' on the Serial Port
}