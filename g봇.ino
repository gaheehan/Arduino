#include <Arduino.h>
#include <LedControl.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>

LedControl lc = LedControl(10, 12, 11, 1);

float leg_angle = 0;
float foot_angle = 0;

Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;


float getDistance(int trig, int echo) {
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo, HIGH, 30000) / 58.0;
} //초음파 센서로 거리측정


void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
} 

void _loop(){

} // empty function

//전진
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


//왼쪽으로
void turn_left() {
  while(!(leg_angle > 120)){
    _loop();
    servo_2.write(leg_angle);
    servo_3.write(leg_angle);
    leg_angle += 2;
    _delay(0.02);
  }

  while(!(foot_angle < 60)){
  _loop();
  servo_4.write((foot_angle+10));
  servo_5.write((180-foot_angle));
  foot_angle += -2;
  _delay(0.02);
  }

  while(!(leg_angle < 60)){
  _loop();
  servo_2.write(leg_angle);
  servo_3.write(leg_angle);
  leg_angle += -2;
  _delay(0.02);
  }
  
  while(!(foot_angle > 120)){
  _loop();
  servo_4.write((foot_angle+10));
  servo_5.write((180-foot_angle));
  foot_angle += 2;
  _delay(0.02);
  }
}

//입열기 표정
void mouthopen() {
  lc.setRowOrColumn(0, 1, 0, "00100100");
  lc.setRowOrColumn(0, 4, 0, "01111110");
  lc.setRowOrColumn(0, 5, 0, "10000001");
  lc.setRowOrColumn(0, 6, 0, "01111110");

}
//입닫기 표정
void mouthclose(){
  lc.setRowOrColumn(0, 1, 0, "00100100");
  lc.setRowOrColumn(0, 4, 0, "00000000");
  lc.setRowOrColumn(0, 5, 0, "11111111");
  lc.setRowOrColumn(0, 6, 0, "00000000");

}

//작은별 노래
void song1 (){
  tone(13,262,0.25*1000);
  delay(0.25*1000);
  tone(13,262,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,440,0.25*1000);
  delay(0.25*1000);
  tone(13,440,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,294,0.25*1000);
  delay(0.25*1000);
  tone(13,294,0.25*1000);
  delay(0.25*1000);
  tone(13,262,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,294,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,294,0.25*1000);
  delay(0.25*1000);
  tone(13,262,0.25*1000);
  delay(0.25*1000);
  tone(13,262,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,440,0.25*1000);
  delay(0.25*1000);
  tone(13,440,0.25*1000);
  delay(0.25*1000);
  tone(13,392,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,339,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,330,0.25*1000);
  delay(0.25*1000);
  tone(13,294,0.25*1000);
  delay(0.25*1000);
  tone(13,294,0.25*1000);
  delay(0.25*1000);
  tone(13,262,0.25*1000);
  delay(0.25*1000);

}


//징글벨 노래
void song2 (){
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,784,0.25*1000);
  delay(0.25*1000);
  tone(13,523,0.25*1000);
  delay(0.25*1000);
  tone(13,587,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,587,0.25*1000);
  delay(0.25*1000);
  tone(13,587,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,587,0.25*1000);
  delay(0.25*1000);
  tone(13,784,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,784,0.25*1000);
  delay(0.25*1000);
  tone(13,523,0.25*1000);
  delay(0.25*1000);
  tone(13,587,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,659,0.25*1000);
  delay(0.25*1000);
  tone(13,784,0.25*1000);
  delay(0.25*1000);
  tone(13,784,0.25*1000);
  delay(0.25*1000);
  tone(13,698,0.25*1000);
  delay(0.25*1000);
  tone(13,587,0.25*1000);
  delay(0.25*1000);
  tone(13,523,0.25*1000);
  delay(0.25*1000);

}
void setup() {
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  servo_2.attach(2);
  servo_3.attach(3);
  servo_4.attach(4);
  servo_5.attach(5);
  pinMode(13,OUTPUT);
   leg_angle = 90;
   foot_angle = 90;

  lc.setIntensity(0, 1);
  while(1) {
    if(getDistance(A0,A1) < 50){
      mouthopen();
      song2();
      turn_left();

    }else{
      mouthclose();
      song1();
      forward();
    }

    _loop();

  }  

}  

void loop() {

}


