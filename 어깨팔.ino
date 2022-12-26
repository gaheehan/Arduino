#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>


float shoulder = 0;
float arm = 0; //초기화

Servo servo_6;
Servo servo_7;
Servo servo_8;
Servo servo_9; 

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
} 

void _loop(){

} //empty function

//어깨 올리기
void shoulder_raise() {
  while(!(shoulder > 180)){
    _loop();
    servo_6.write(shoulder);
    servo_7.write((180-shoulder));
    shoulder += 3;
    _delay(0.02);
  }
}

//어깨 내리기
void shoulder_down() {
  while(!(shoulder < 90)){
    _loop();
    servo_6.write(shoulder);
    servo_7.write((180-shoulder));
    shoulder += -3;
    _delay(0.02);
  }
}

//팔 올리기
void arm_raise() {
  while(!(arm > 180)){
    _loop();
    servo_8.write(arm);
    servo_9.write((180-arm));
    arm += 3;
    _delay(0.02);
  }

  while(!(arm < 90)){
    _loop();
    servo_8.write(arm);
    servo_9.write((180-arm));
    arm -= 3;
    _delay(0.02);
  }

}

//팔 내리기
void arm_down() {
  while(!(arm > 90)){
    _loop();
    servo_8.write(arm);
    servo_9.write((180-arm));
    arm += 3;
    _delay(0.02);
  }

  while(!(arm < 0)){
    _loop();
    servo_8.write(arm);
    servo_9.write((180-arm));
    arm -= 3;
    _delay(0.02);
  }

}

//어깨 위아래로 흔들기
void shacking_shoulder() {
  while(!(shoulder < 30)){
    _loop();
    servo_6.write(shoulder);
    servo_7.write((180-shoulder));
    shoulder -= 3;
    _delay(0.02);
  }

  while(!(shoulder > 120)){
    _loop();
    servo_6.write(shoulder);
    servo_7.write((180-shoulder));
    shoulder += 3;
    _delay(0.02);
  }

}

//팔 모았다 펴기
void arms_outstretched() {
  while(!(arm < 0)){
    _loop();
    servo_8.write(arm);
    servo_9.write((180-arm));
    arm += -3;
    _delay(0.02);
  }

  while(!(arm > 120)){
    _loop();
    servo_8.write(arm);
    servo_9.write((180-arm));
    arm += 3;
    _delay(0.02);
  }

}

//실행하기
void setup() {
  servo_6.attach(6);
  servo_7.attach(7);
  servo_8.attach(8);
  servo_9.attach(9);

  shoulder = 90;
  arm = 90;

  
  for(int count=0;count<3;count++){
    shoulder_raise();
    shoulder_down();
    arm_raise();
    arm_down();
    shacking_shoulder();
    arms_outstretched();
   }

     
  

   _loop();

}

void loop() {
  // put your main code here, to run repeatedly:

}
