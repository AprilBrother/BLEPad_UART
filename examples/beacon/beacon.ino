/* 
 * Demo for change iBeacon parameters
 */
 
#include "BLEPad_UART.h"

String tmp;

BLEPad_UART ble(Serial1);

byte BUFF[33]={0x00};    
byte BUFF_CMD1[7]={0x3C,0x49,0x42,0x41,0x43,0x4F,0x4E}; // Define prefix for AT command '<IBACON '
byte BUFF_HEADER[4]={0x4C,0x00,0x02,0x15};  // Define advertising data header 

// define UUID
byte BUFF_UUID[16]={0x88,0x85,0x57,0xE7,0x23,0xE4,0x4B,0xED,0x98,0x8A,0xA0,0x2F,0xE4,0x7F,0x90,0x01}; 

byte BUFF_MAJOR[2]={0x00,0x02}; //Major
byte BUFF_MINOR[2]={0x00,0x03}; //Minor
byte BUFF_RSSI_1M[1]={0xD4};    //RSSI - Measured Power
byte BUFF_CMD2[1]={0x3E};       //Define suffix for AT command ' > '

void setup(void)
{
  Serial.begin(9600);
  ble.begin(9600);

  while(!Serial);
  Serial.println("Hello");

  // Change BLE module to config mode
  ble.setConfigMode(1);
  delay(50);
  //Change iBeacon parameters
  SetBeaconIf();
  delay(300);

  //Change to tranparent data transport mode
  ble.setConfigMode(0);
  delay(50);

}

void loop(void)
{
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

void SetBeaconIf(void)
{
  int buff_j,i;
  for(i=0,buff_j=0;i<7;i++,buff_j++){
    BUFF[buff_j]=BUFF_CMD1[i];
  }
  for(i=0;i<4;i++,buff_j++){
    BUFF[buff_j]=BUFF_HEADER[i];
  }
  for(i=0;i<16;i++,buff_j++){
    BUFF[buff_j]=BUFF_UUID[i];
  }
  for(i=0;i<2;i++,buff_j++){
    BUFF[buff_j]=BUFF_MAJOR[i];
  }
  for(i=0;i<2;i++,buff_j++){
    BUFF[buff_j]=BUFF_MINOR[i];
  }
  for(i=0;i<1;i++,buff_j++){
    BUFF[buff_j]=BUFF_RSSI_1M[i];
  }
  for(i=0;i<1;i++,buff_j++){
    BUFF[buff_j]=BUFF_CMD2[i];
  }
  Serial.print("buff_j:");
  Serial.println(buff_j);
  ble.write(BUFF,buff_j);
}


