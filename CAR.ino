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
int IN4 = 12; //6 par thi

//servo pin
int S1 = 11;

//speed
int Speed_m1 = 90;
int Speed_m2 = 100;
int Speed_l1 = 160;
int Speed_l2 = 170;
int Speed_h1 = 245;
int Speed_h1 = 255;

//SPEED SET OF TWO MOTOTR
int M1_s = Speed_m1;
int M2_s = Speed_m2;

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, Speed_l1);
  analogWrite(ENB, Speed_l2);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Forward");
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, Speed_l1);
  analogWrite(ENB, Speed_l2);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Backward");
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, M1_s);
  analogWrite(ENB, M2_s);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("LEFT");
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, M1_s);
  analogWrite(ENB, M2_s);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("RIGHT");
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
  Serial.begin(9600);
  Dabble.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  Dabble.processInput();
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
  if (GamePad.isSquarePressed()) {
    gripper.attach(S1);
    gripper.write(180);
    delay(1000);
    gripper.detach();
  } else {
    gripper.attach(S1);
    gripper.write(0);
    delay(1000);
    gripper.detach();
  }


  // //speed control
  if (GamePad.isStartPressed()) {
    M1_s = Speed_l;
    M2_s = Speed_l;
  } else if (GamePad.isSelectPressed()) {
    M1_s = 160;
    M2_s = 0;
  } else if (GamePad.isCrossPressed()) {
    M1_s = Speed_h;
    M2_s = Speed_h;
  }
}
