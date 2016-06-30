#include "BLEPad_UART.h"


String tmp; 

int config_pin = 5;
int change_pin = 11;

BLEPad_UART ble(Serial1);

void setup() {
  Serial.begin(9600);
  ble.begin(9600);

  while (!Serial);
  Serial.println("hello!");
  
  pinMode(config_pin, OUTPUT);
  pinMode(change_pin, OUTPUT);
  
  digitalWrite(config_pin, HIGH);
  digitalWrite(change_pin, LOW);
};

void loop() {

  while (ble.available() > 0)  {
    tmp += char(ble.read());
    delay(2);
  }

  if(tmp.length() > 0) {
    Serial.println(tmp);
    tmp = "";
  }

  if (Serial.available()) {
    ble.write(Serial.read());
  }

}
