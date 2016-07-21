/* 这个程序主要是用于进行批量的修改你想要修改的参数，
 * 不需要修改的参数直接注释掉就OK了
 * 也可以在串口工具里面逐条指令的修改
 * 修改的参数如下
 * .设置波特率
 * <BAUD4800>、<BAUD9600>、<BAUD19200>、<BAUD38400>、<BAUD57600>、
 * <BAUD115200>、<BAUD256000>
 * .设置串口位停止个数
 * <1SB> -- 1个停止位  <2SB> -- 2个停止位
 * .设置串口校验位类型
 * <PEVEN> -- 偶校验  <PODD> -- 奇校验 <PNO> -- 无校验
 * .设置广播启动和停止
 * <STOPADV> -- 关闭模块广播  <STARTADV> -- 打开模块广播(默认打开)
 * .设置设备名称
 * <NAMExxxxx> -- 名称最长18个字节的字符数据
 * .设置厂家名称
 * <FACxxxxx> -- 名称最长18个字节的字符数据
 * .设置软件版本
 * <SOFTxxxxx> -- 最长为18个字节的字符数据
 * .设置硬件版本
 * <HARDxxxxx> -- 最长为18个字节的字符数据
 * .设置模块SN号
 * <SNxxxxx> -- 最长为18个字节的字符数据
 * .设置广播间隙
 * <ADVGAP32> ~~ <ADVGAP16000>  对应时间20ms ~~ 10s
 * .设置最大连接间隙
 * <CONMAX6> ~~ <CONMAX3200>  对应时间7.5ms ~~ 4s
 * .设置最小连接间隙
 * <CONMIN6> ~~ <CONMIN3200>  对应时间7.5ms ~~ 4s
 * 注:最大连接间隙要大于或等于最小连接间隙
 * .设置连接超时时间
 * <TIMEOUT10> ~~ <TIMEOUT3200> 对应时间为100ms ~~ 32s
 * .立即断开当前连接
 * <DISCONNECT> -- 连接状态下，立即断开连接，非连接状态下返回<DISCONNECTED>
 * 提示处于断开状态
 * 
 * :在修改的过程可能会出现错误，重新烧写一下即可
 * 
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

  ble.setConfigMode(1);
  delay(2000);
};

void loop() {
  /*此处用于设置各种参数可以将你想要设置的参数填写到下面 一次性修改完成
   * 或在串口工具里面每条指令单独修改 
  */  

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    switch (i){   
     //设置波特率
      case 0:
        Serial.print("set baudrate is: ");
  //    Serial.println(4800);
  //    ble.write("<BAUD4800>"); 
        Serial.println(9600);
        ble.write("<BAUD9600>");
  //    Serial.println(19200);
  //    ble.write("<BAUD19200>");
  //    Serial.println(38400);
  //    ble.write("<BAUD38400>");
  //    Serial.println(57600);
  //    ble.write("<BAUD57600>");
  //    Serial.println(115200);
  //    ble.write("<BAUD115200>");
  //    Serial.println(256000);
  //    ble.write("<BAUD256000>");
        break;
      //设置停止位个数
      case 1:
        Serial.print("set num of stopbit is: ");
        Serial.println("1bit");      
        ble.write("<1SB>");
  //    Serial.println("2bit");
  //    ble.write("<2SB>"); 
        break;
      //设置串口校验位类型
      case 2:
        Serial.print("set type of serial parity bit is: ");
  //    Serial.println("Even-parity check"); 
  //    ble.write("<PEVEN>");
  //    Serial.println("Odd-parity check");
  //    ble.write("<PODD>");
        Serial.println("No-parity check");
        ble.write("<PNO>");
        break;
      //设置当前广播启停状态
      case 3:
        Serial.print("set broadcast status is: ");
        Serial.println("STOP");
        ble.write("<STOPADV>"); 
  //    Serial.println("START");
  //    ble.write("<STARTADV>");
        break;
      //设置设备名称
      case 4:
        Serial.print("set device name is: ");
        Serial.println("hello");
        ble.write("<NAMEhello>");  
        break;
      //设置厂家名称
      case 5:
        Serial.print("set manufacturer name is: ");
        Serial.println("siyue");
        ble.write("<FACsiyue>");  
        break;
      //设置软件版本
      case 6:
        Serial.print("set software version is: ");
        Serial.println(4.9);
        ble.write("<SOFT4.9>");  
        break;
      //设置硬件版本
      case 7:
      Serial.print("set hardware version is: ");
        Serial.println(6.1);
        ble.write("<HARD6.1>");
        break;
      //设置模块SN
      case 8:
        Serial.print("set SN of module is: ");
        Serial.println(6.2);
        ble.write("<SN6.2>"); 
        break;
      //设置广播间隙
      case 9:
        Serial.print("set time of broadcast interval is: ");
        Serial.println(300);
        ble.write("<ADVGAP300>");  
        break;
      //设置最大连接间隙
      case 10:
        Serial.print("set max time of connect interval is: ");
        Serial.println(20);
        ble.write("<CONMAX20>");  
        break;
      //设置最小连接间隙
      case 11:
        Serial.print("set min time of connect interval is: ");
        Serial.println(6);
        ble.write("<CONMIN6>"); 
        break;
       //设置连接超时时间
      case 12:
        Serial.print("set time of connect timeout is: ");
        Serial.println(50);
        ble.write("<TIMEOUT50>");
        break;
      case 13:
        Serial.print("Disconnect from the host: ");
        ble.write("<DISCONNECT>");
      default:
        break;
    }
    i++;
  }
  /*
  //20s后修改为透传模式
  if(i>200){
    ble.setConfigMode(0);
  }
  */
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
