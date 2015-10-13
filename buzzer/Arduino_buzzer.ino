#include <CmdMessenger.h>
#include <Wire.h>

int buzz = 11;
int buzzer = 8;
byte msg = 0;


char field_separator  = ' ';
char command_separator = ';';
CmdMessenger cmdMessenger = CmdMessenger(Serial, field_separator, command_separator);


void on_buzz() {
  Serial.println("buzzing it");
  tone(buzzer, 1500);
  delay(300);
  noTone(buzzer);
  }

void setup() {
  Serial.begin(9600);
  delay(30);
  pinMode(buzzer, OUTPUT);

  cmdMessenger.attach(buzz, on_buzz);

}

void loop() {
  cmdMessenger.feedinSerialData();
//
//  if (Serial.available()) {
//    msg = Serial.read();
//    
//    if(msg == 'B') {
//      buzz();
//    }
//  }
//  delay(100);
  
}
