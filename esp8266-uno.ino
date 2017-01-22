#include <SoftwareSerial.h>

//using software serial ESP8266rx-UNOpin3 ESP8266tx-UNOpin2
SoftwareSerial mySerial(2, 3); 

String WiFiSSID = "LiCL";
String WiFiPASSWORD = "030150230";
String nodenum="01";
int i=0;
void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  
  Serial.println("initial start");
  //ESP8266通电启动等待
  delay(5000);
  //如果是透传模式，退出透传
  Serial.println("exit pass-through mode");
  mySerial.print("+++");
  delay(1000);
  mySerial.print("AT\r\n");
  delay(1000);
  printmssage();
  //关闭命令回显
  Serial.println("Close command echo");
  mySerial.print("ATE0\r\n");
  delay(1000);
  printmssage();
  //设置WiFi应用模式为Station
  Serial.println("choose station mode");
  mySerial.print("AT+CWMODE=1\r\n");  
  delay(1000);
  printmssage();
  //connect wifi
  Serial.println("connect wireless router");
  mySerial.print("AT+CWJAP=\"");
  mySerial.print(WiFiSSID);
  mySerial.print("\",\"");
  mySerial.print(WiFiPASSWORD);
  mySerial.print("\"\r\n");
  delay(8000);
  printmssage();
  Serial.println("connecting remote server");
  mySerial.print("AT+CIPSTART=\"TCP\",\"192.168.199.160\",9999\r\n");
  delay(4000);
  printmssage();
  //start pass-through
  Serial.println("choose pass-through mode");
  mySerial.print("AT+CIPMODE=1\r\n");
  delay(3000);
  printmssage();
  Serial.println("enter pass-through mode");
  mySerial.print("AT+CIPSEND\r\n");
  Serial.println("prepare send");
  delay(1000);
  printmssage();
  mySerial.print(nodenum);
  mySerial.print(" online\r\n");
  Serial.println("sended");
  delay(1000);
  Serial.println("setting over");
  printmssage();
  //exit pass-through mode
  /*Serial.println("exit pass-through mode");
  mySerial.print("+++");
  delay(600);
  mySerial.print("\r\n");
  delay(1000);
  printmssage();*/
  
  //close socket
  //Serial.println("closing socket");
  //mySerial.print("AT+CIPCLOSE\r\n");
  //delay(2000);

  //mySerial.print("AT+RST\r\n");

}

void loop(){
  Serial.println(i);
  delay(1000);
  /*mySerial.print("AT+CIPMODE=1\r\n");
  delay(1000);
  printmssage();
  mySerial.print("AT+CIPSEND\r\n");
  delay(1000);*/
  printmssage();
  mySerial.print(i);
  mySerial.print("foo\r\n");
  delay(1000);
  printmssage();
  /*mySerial.print("+++");
  delay(600);
  mySerial.print("\r\n");
  printmssage();*/
  i=i+1;
}
void printmssage(){
  if (mySerial.available()){
      mySerial.readStringUntil('\n');
      //Serial.println(mySerial.readStringUntil('\n'));
  }
}

