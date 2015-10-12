#include <CmdMessenger.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

int still = 5;
int left = 1;
int right = 2;
int up = 3;
int down = 4;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
//Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

char field_separator  = ' ';
char command_separator = ';';

CmdMessenger cmdMessenger = CmdMessenger(Serial, field_separator, command_separator);

void on_left() {
  Serial.println("forward");
  myMotor->run(FORWARD);
  delay(5);
  
}

void on_right() {
  Serial.println("backup");
  myMotor->run(BACKWARD);
  delay(5);
}

void on_still() {
  Serial.println("still");
  myMotor->run(RELEASE);
  delay(5);
  }

void setup() {
  Serial.begin(9600);

  cmdMessenger.attach(still, on_still);
  cmdMessenger.attach(left, on_left);
  cmdMessenger.attach(right, on_right);

  AFMS.begin();  // create with the default frequency 1.6KHz

  myMotor->setSpeed(100);
  myMotor->run(FORWARD);
  myMotor->run(RELEASE);
  
}


void loop() {
  uint8_t i;
  cmdMessenger.feedinSerialData();

}
