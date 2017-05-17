/*
 * Central role example
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
  // Execute AT commands step by step
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    switch (i) {
      case 0:
        // Must reset for change role
        // Change to central role
        ble.setRole(BLEPAD_MASTER_MODE);
        ble.write("<RESET>");
        break;
      case 1:
        // Query the ROLE type, it should show central
        ble.write("<ROLETYPE>");
        break;
      case 2:
        // scan and connect to other BLEPad slave
        ble.write("<STARTSCAN>");
        break;
      case 3:
        // quit config mode and start transfer data
        ble.setConfigMode(0);
        break;
      default:
        break;
    }
    i++;
  }

  // show the response for AT command
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
