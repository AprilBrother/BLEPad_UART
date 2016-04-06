#include "BLEPad_UART.h"


String tmp; 

int wakeup_pin = 8;
int config_pin = 5;
int change_pin = 11;

BLEPad_UART ble(&Serial1);

void setup() {
  Serial.begin(19200);
  Serial1.begin(19200);

  while (!Serial);
  Serial.println("hello!");
  
  pinMode(wakeup_pin, OUTPUT);
  pinMode(config_pin, OUTPUT);
  pinMode(change_pin, OUTPUT);
  
  digitalWrite(wakeup_pin, LOW);
  digitalWrite(config_pin, HIGH);
  digitalWrite(change_pin, LOW);
};

void loop() {

  while (Serial1.available() > 0)  {
    tmp += char(Serial1.read());
    delay(2);
  }

  if(tmp.length() > 0) {
    Serial.println(tmp);
    tmp = "";
  }

  if (Serial.available()) {
    Serial1.write(Serial.read());
  }

}