#include <Dabble.h>
int M1_EN = 5;
int M1_IN1 = 8;
int M1_IN2 = 9;

int M2_EN = 6;
int M2_IN3 = 10;
int M2_IN4 = 11;

int speed_M1 = 105;
int speed_M2 = 110;

void setup() {

Dabble.begin(9600);

  pinMode(M1_EN, OUTPUT);
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_EN, OUTPUT);
  pinMode(M2_IN3, OUTPUT);
  pinMode(M2_IN4, OUTPUT);
}

void loop() 
{
  Dabble.processInput();

  if (GamePad.isPressed(0)) 
  {
    analogWrite(M1_EN, speed_M1);
    digitalWrite(M1_IN1, HIGH);
    digitalWrite(M1_IN2, LOW);
    analogWrite(M2_EN, speed_M2);
    digitalWrite(M2_IN3, HIGH);
    digitalWrite(M2_IN4, LOW);
  } else if (GamePad.isPressed(1)) 
  {
    analogWrite(M1_EN, speed_M1);
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, HIGH);
    analogWrite(M2_EN, speed_M2);
    digitalWrite(M2_IN3, LOW);
    digitalWrite(M2_IN4, HIGH);
  } else if (GamePad.isPressed(2))
  {
    analogWrite(M1_EN, speed_M1);
    digitalWrite(M1_IN1, HIGH);
    digitalWrite(M1_IN2, LOW);
    analogWrite(M2_EN, speed_M2);
    digitalWrite(M2_IN3, LOW);
    digitalWrite(M2_IN4, HIGH);
  }
  else if (GamePad.isPressed(3))
  {
    analogWrite(M1_EN, speed_M1);
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, HIGH);
    analogWrite(M2_EN, speed_M2);
    digitalWrite(M2_IN3, HIGH);
    digitalWrite(M2_IN4, LOW);
  }
  else if (GamePad.isPressed(8))
  {
    analogWrite(M1_EN, 0);
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, LOW);
    analogWrite(M2_EN, 0);
    digitalWrite(M2_IN3, LOW);
    digitalWrite(M2_IN4, LOW);
  }

  else{
    analogWrite(M1_EN, 0);
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, LOW);
    analogWrite(M2_EN, 0);
    digitalWrite(M2_IN3, LOW);
    digitalWrite(M2_IN4, LOW);
  }
}