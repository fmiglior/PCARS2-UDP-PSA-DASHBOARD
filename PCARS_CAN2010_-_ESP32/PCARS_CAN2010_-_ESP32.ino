//Code for ESP32 using th WIFI to read the UPD data of pcars2 and automobilista 2 game.
#include "SPI.h"


// ESP32 Wifi
#include <WiFi.h>

// Standard Wifi UDP Lib
#include <WiFiUdp.h>


#include "variaveis.h" //variables
#include "convertfloat.h" //code to convert





void setup() {
  
delay(1000);
Serial.begin(115200);
while (!Serial) {; 
}

// conect wifi
while ( status != WL_CONNECTED) {
 
status = WiFi.begin(ssid, pass);

delay(2500);
}

  Serial.println("Starting PCARS UDP");
  Udp.begin(localPort);
  delay(2000);

}

void loop() {

//Recive packet
int packetSize = Udp.parsePacket();
if (packetSize) {
//Serial.print("Received packet of size "); 
//Serial.println(packetSize);
//Serial.print("From ");
IPAddress remoteIp = Udp.remoteIP();
Udp.read(packetBuffer, 1600);


if (packetSize == 559){ //telemetry packet 

 //read the gear
sGearNumGears = packetBuffer[45] & 0xf;
if (sGearNumGears == 15){
  D1[3] = 16; //  Reverse
  }
 else if (sGearNumGears == 0){
  D1[3] = 32; //N
 }
  else if (sGearNumGears == 1){
  D1[3] = 144; //1 gear
 }
  else if (sGearNumGears == 2){
  D1[3] = 128; //2 gear
 }
 else if (sGearNumGears == 3){
  D1[3] = 112; //3 gear
 }
  else if (sGearNumGears == 4){
  D1[3] = 96; //4 gear
 }
  else if (sGearNumGears == 5){
  D1[3] = 80; //5 gear
 }
  else if (sGearNumGears == 6){
  D1[3] = 64; //6 gear
 }
else{
  D1[3] = 1 ;   
}

//convert the value to Km/h 
convertFloatU(36);
sSpeed = (uData.uFloat) *3.6;  //change this value to use MPH
if (sSpeed >= 240){ //change here to the max value of your speedometer 
 D1[2] = 240 ;
}
else{
 D1[2] = sSpeed * 0.386364; //this value is to convert the km/h speed to my speedometer CAN input
}
//Serial.print("speed: ");Serial.println(sSpeed);

//RPM
sRpm = word(packetBuffer[41],packetBuffer[40]);
//sMaxRpm = (word(packetBuffer[43],packetBuffer[42]))*0.97;
if (sRpm >=7600 ){ //max rpm of the dashboard
D1[1] = 238;
}
else{
D1[1] = sRpm * 0.031429; //value to convert the RPM value to CAN HEX of the dasboard
}
//headlight
if (bitRead(packetBuffer[17],0) == 1 ){
D1[4] = 192;
}
else   {
D1[4] = 01;
}
//ABS signal
if (bitRead(packetBuffer[17],4) == 1 ){
D1[5] = 32;
}
else   {
D1[5] = 01;
}
//water temp warning light
if (bitRead(packetBuffer[17],2) == 1 ){
D1[8] = 80;
}
else   {
D1[8] = 01;
}
//engine stoped
if (bitRead(packetBuffer[17],1) == 1 ){
D1[9] = 40;
}
else   {
D1[9] = 01;
}

//fuel 
convertFloatU(32);
D1[6] = (uData.uFloat)*100;
D1[10] = 10;

//water Temp
D1[7] = (packetBuffer[22]+51);

//Car odometer
convertFloatU(48);
Div = uData.uFloat;
resultado = Div / 6553.5;
D1[11] = resultado;
sobra = Div - resultado;
resultado = sobra / 25.6;
D1[12] = resultado;
sobra = sobra - resultado;
resultado = sobra / 0.104;
D1[13] = resultado; 


//send packtet to the arduino
D1[0] = 60; //begin
D1[14] = 62; //end
Serial.write(D1,15);


}
if (packetSize != 599) {
 // Serial.write(D1,15);
  //delay(1);
}
}
}
