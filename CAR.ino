#include <Dabble.h>
#include <Servo.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

Servo gripper;

//MOTOR 1
int ENA = 6;
int IN1 = 4;
int IN2 = 8;

//MOTOR2
int ENB = 5;
int IN3 = 7;
int IN4 = 12;  //6 par thi

//servo pin
int S1 = 11;

//speed
int Speed_m1 = 160;
int Speed_m2 = 170;
int Speed_l1 = 90;
int Speed_l2 = 90;
int Speed_h1 = 200;
int Speed_h2 = 200;


int toggle = 0;
//SPEED SET OF TWO MOTOTR
int M1_s = Speed_m1;
int M2_s = Speed_m2;
void delay_forward(){
  forward();
  delay(500);
  stop();
}

void delay_left(){
  left();
  delay(500);
  stop();
}
void delay_right(){
  right();
  delay(500);
  stop();
}
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 140);
  analogWrite(ENB, 140);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 130);
  analogWrite(ENB, 145);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, Speed_l1);
  analogWrite(ENB, Speed_l2);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, Speed_l1);
  analogWrite(ENB, Speed_l2);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void setup() {
  Dabble.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);

  pinMode(IN4, OUTPUT);
}

void set_toggle(){
  if (toggle == 0){
    toggle = 1;
  }else{
    toggle = 0;
  }
}

void loop() {

  Dabble.processInput();
  if (GamePad.isCirclePressed()){
    set_toggle();
  }


  if (GamePad.isUpPressed()) {
    forward();
  } else if (GamePad.isDownPressed()) {
    backward();
  } else if (GamePad.isLeftPressed()) {
    left();
  } else if (GamePad.isRightPressed()) {
    right();
  } else {
    stop();
  }

  //GRIPPER CONTROL
  if (GamePad.isSelectPressed()) {
    gripper.attach(S1);
    gripper.write(0);
    delay(1000);
    gripper.detach();
  } else if (GamePad.isStartPressed()) {
    gripper.attach(S1);
    gripper.write(150);
    delay(1000);
    gripper.detach();
  }

  if (GamePad.isCrossPressed()) {
    stop();
  }

}
