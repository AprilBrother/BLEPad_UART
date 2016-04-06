String tmp; 

int wakeup_pin =8;
int config_pin =5;
int change_pin =11;
void setup() {
  Serial.begin(19200);
  Serial1.begin(19200);

  while (!Serial);
  Serial.println("hello!");
  
  pinMode(wakeup_pin, OUTPUT);
  pinMode(config_pin, OUTPUT);
  pinMode(change_pin, OUTPUT);
  
  digitalWrite(wakeup_pin, LOW);
  //delay(50);
  digitalWrite(config_pin, HIGH);
  //delay(50);
  digitalWrite(change_pin, LOW);
};

void loop() {

  while (Serial1.available() > 0)  {
    tmp += char(Serial1.read());
    delay(2);
  }

  if(tmp.length() > 0) {
    Serial.println(tmp);
  //  Serial.println("\r\n");
    tmp = "";
  }

  if (Serial.available()) {
    Serial1.write(Serial.read());
  }

}
