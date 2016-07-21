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

  ble.setConfigMode(1);
  delay(2000);
};

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    switch (i) {
      case 0:
        Serial.print("the baud rate is: ");
        ble.write("<COMBAUD>"); //read baud rate
        break;
      case 1:
        Serial.print("the num of stopbit is: ");
        ble.write("<STOPBIT>"); //read stop bits
        break;
      case 2:
        Serial.print("the type of serial parity bit is: ");
        ble.write("<PARITY>"); 
        break;
      case 3:
        Serial.print("the broadcast status is: ");
        ble.write("<ADVSTATE>"); 
        break;
      case 4:
        Serial.print("the device name is: ");
        ble.write("<MNAME>");  //read device name
        break;
      case 5:
        Serial.print("the manufacturer name is: ");
        ble.write("<FNAME>");  
        break;
      case 6:
        Serial.print("the software version is: ");
        ble.write("<SVER>");  
        break;
      case 7:
      Serial.print("the hardware version is: ");
        ble.write("<HVER>");  
        break;
      case 8:
        Serial.print("the SN of module is: ");
        ble.write("<MSN>");  
        break;
      case 9:
        Serial.print("the time of broadcast interval is: ");
        ble.write("<AGAP>");  
        break;
      case 10:
        Serial.print("the max time of connect interval is: ");
        ble.write("<MAXCGAP>");
        break;
      case 11:
        Serial.print("the min time of connect interval is: ");
        ble.write("<MINCGAP>");
        break;
      case 12:
        Serial.print("the time of connect timeout is: ");
        ble.write("<CTIMEOUT>"); break;
      case 13:
        Serial.print("the status of BLE connected is: ");
        ble.write("<STATE>");  
        break;
      case 14:
        Serial.print("the working mode is: ");
        ble.write("<ROLETYPE>"); 
        break;
      case 15:
        Serial.print("the MAC address is: ");
        ble.write("<MAC>");  
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
