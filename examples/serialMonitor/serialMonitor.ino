#include "BLEPad_UART.h"


String tmp; 
BLEPad_UART ble(Serial1);

void setup() {
  Serial.begin(9600);
  ble.begin(9600);

  while (!Serial);
  Serial.println("hello!");
  
  ble.setConfigMode(0);
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
