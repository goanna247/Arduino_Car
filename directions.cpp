#include "header.h"

DriveBase _driveBase;


void forwards (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, HIGH);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, HIGH);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(waitTime);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);

  Serial.write("forwards");
}

void backwards (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, LOW);
  digitalWrite(_driveBase.IN2, HIGH);
  digitalWrite(_driveBase.IN3, LOW);
  digitalWrite(_driveBase.IN4, HIGH);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);

  Serial.write("backwards");
}

void oneWheelRight (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, HIGH);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, LOW);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  Serial.write("oneWheelRight");
}

void twoWheelRight (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, HIGH);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, LOW);
  digitalWrite(_driveBase.IN4, HIGH);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  Serial.write("twoWheelRight");
}

void oneWheelLeft (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, LOW);
  digitalWrite(_driveBase.IN2, LOW);
  digitalWrite(_driveBase.IN3, HIGH);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
Serial.write("oneWheelLeft");
}

void twoWheelLeft (int speed, int waitTime) {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
  digitalWrite(_driveBase.IN1, LOW);
  digitalWrite(_driveBase.IN2, HIGH);
  digitalWrite(_driveBase.IN3, HIGH);
  digitalWrite(_driveBase.IN4, LOW);
  analogWrite(_driveBase.ENA, speed);
  analogWrite(_driveBase.ENB, speed);

  delay(100);

  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
Serial.write("twoWheelLeft");
}

void breaking() {
  analogWrite(_driveBase.ENA, 0);
  analogWrite(_driveBase.ENB, 0);
}

void LEDROn() {
  //Red for speeeeeeeeeeed
  RGB_colour(255, 0, 0);
}

void LEDOff() {
  RGB_colour(0, 0, 0);
}

void RGB_colour(int LEDR_value, int LEDG_value, int LEDB_value) {
  analogWrite(_driveBase.LEDR, LEDR_value);
  analogWrite(_driveBase.LEDG, LEDG_value);
  analogWrite(_driveBase.LEDB, LEDB_value);
}