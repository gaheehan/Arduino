#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>

float leg_angle = 0; 
float foot_angle = 0; 

Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5; 

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
} 

void _loop(){

} // empty function

void forward() {
  while(!(leg_angle > 120)){
  _loop();
  servo_2.write(leg_angle);
  servo_3.write(leg_angle);
  leg_angle += 2;
  _delay(0.03);
}

while(!(foot_angle < 60)){
  _loop();
  servo_4.write(foot_angle);
  servo_5.write(foot_angle);
  foot_angle += -2;
  _delay(0.03);
}

while(!(leg_angle < 60)){
  _loop();
  servo_2.write(leg_angle);
  servo_3.write(leg_angle);
  leg_angle += -2;
  _delay(0.03);
}

while(!(foot_angle > 120)){
  _loop();
  servo_4.write(foot_angle);
  servo_5.write(foot_angle);
  foot_angle += 2;
  _delay(0.03);
}

}


void backward() {
  while(!(leg_angle > 120)){
  _loop();
  servo_2.write(leg_angle);
  servo_3.write(leg_angle);
  leg_angle += 2;
  _delay(0.03);
}

while(!(foot_angle > 120)){
  _loop();
  servo_4.write(foot_angle);
  servo_5.write(foot_angle);
  foot_angle += 2;
  _delay(0.03);
}

while(!(leg_angle < 60)){
  _loop();
  servo_2.write(leg_angle);
  servo_3.write(leg_angle);
  leg_angle += -2;
  _delay(0.03);
}

while(!(foot_angle < 60)){
  _loop();
  servo_4.write(foot_angle);
  servo_5.write(foot_angle);
  foot_angle += -2;
  _delay(0.03);
}

}

void setup() {
 servo_2.attach(2);
 servo_3.attach(3);
 servo_4.attach(4);
 servo_5.attach(5);

 leg_angle = 90;
 foot_angle = 90;

//  servo_2.write(90);
//  servo_3.write(90);
//  servo_4.write(90);
//  servo_5.write(90);
 
 
 while(1){
   for(int count=0;count<3;count++){
     forward();
   }
   for(int count2=0;count2<3;count2++){
     backward();
   }
     
   }

   _loop();
 }
 
 

 
 



void loop() {

}