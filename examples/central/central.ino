/*
 * Examples for AT command
 */
 
#include "BLEPad_UART.h"

String tmp;

BLEPad_UART ble(Serial1);

unsigned long previousMillis = 0;
const long interval = 2000;
int i = 0;

void setup() {
  Serial.begin(9600);
  ble.begin(9600);

  while (!Serial);
  Serial.println("hello!");
  
  // Change BLE module to config mode
  ble.setConfigMode(1);
  delay(2000);
  
};

void loop() {
  // Examples for AT commands
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    switch (i) {
      case 0:
        // Must reset for change role
        ble.setRole(BLEPAD_MASTER_MODE);
        ble.write("<RESET>");
        break;
      case 1:
        ble.write("<ROLETYPE>");
        break;
      case 2:
        // scan and connect to other BLEPad slave
        ble.write("<STARTSCAN>");
        break;
      default:
        break;
    }
    i++;
  }

  while (ble.available() > 0)  {
    tmp += char(ble.read());
    delay(2);
  }

  if (tmp.length() > 0) {
    Serial.println(tmp);
    tmp = "";
  }

  if (Serial.available()) {
    ble.write(Serial.read());
  }
}
