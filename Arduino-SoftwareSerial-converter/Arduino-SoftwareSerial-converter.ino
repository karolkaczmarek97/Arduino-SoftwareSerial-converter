#include<SoftwareSerial.h>                              //Included SoftwareSerial Library

//Remembering data
String data_sent = "";                                  //Data sent to device
String data_received = "";                              //Data received from device

//Starting mySerial SoftwareSerial
SoftwareSerial mySerial(10, 11);                        //Pin D10 as Rx, D11 as Tx

void setup() {
  //Hardware Serial: PC to Arduino as converter
  Serial.begin(9600);                                   //Pin D0 as Rx, D1 as Tx, default settings (9600 8 N 1)
  //Software Serial: Arduino as converter to connected device
  mySerial.begin(9600);                                 //Pins as described earlier, default settings (9600 8 N 1)
  Serial.println("Connected Arduino Nano compatible board (with CH340) as serial converter");
}

void loop() {
  if (Serial.available() > 0) {                         //If there is some data from PC
    data_sent = Serial.readStringUntil('\n');           //read it from USB
    mySerial.print(data_sent);                          //and send to device
    mySerial.print('\n');                               //and hit ENTER
  }
  if (mySerial.available() > 0) {                       //If there is data from connected device
    data_received = mySerial.readStringUntil('\n');     //read it from devise
    Serial.print(data_received);                        //and send to USB
    Serial.print('\n');                                 //and hit ENTER
  }
}
