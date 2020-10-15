//code for arduino and mcp2515

#include <SPI.h>
#include <mcp2515.h>
#include "cancode.h"


MCP2515 mcp2515(10);

byte received[20];
byte fimpacote = 62;
int rpm;


    // Timers
uint32_t D2oldtime = millis();
uint32_t D2delay = 5000; // 


void setup() {


  
  while (!Serial);
  Serial.begin(115200);
  SPI.begin();
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();

  
  //Serial.println("Teste");

carregaCAN();
}

void loop() {
  
mcp2515.sendMessage(&canMsg2);
  
if (Serial.available() > 0){
  Serial.readBytesUntil(fimpacote,received,128); //recive the pack and convert to can layout
  //Serial.print("recebi!");
  if (received[0] == 60) {

//RPM
canMsg3.data[0] = (received[1] & 0xFF);

//speed
canMsg3.data[2] = (received[2] & 0xFF);

//gear
canMsg4.data[1] = (received[3] & 0xFF);

//light
canMsg4.data[0] = (received[4] & 0xFF);

//abs
canMsg5.data[3] = (received[5] & 0xFF);

//fuel
canMsg6.data[3] = (received[6] & 0xFF);

//water temp
canMsg1.data[1] = (received[7] & 0xFF);

//if  (received[8] == 80) {
//canMsg8.data[1] = 0x01;
//canMsg8.data[0] = 0x80;
//}
//else {
 //canMsg8.data[0] = 0x7F;
//}

//odometer
canMsg1.data[2] = (received[11] & 0xFF);
canMsg1.data[3] = (received[12] & 0xFF);
canMsg1.data[4] = (received[13] & 0xFF);
}
else {
  Serial.println("recebi pacote errado");     
}

}
Serial.println(received[7]);
Serial.println(received[2]);
mcp2515.sendMessage(&canMsg2);
mcp2515.sendMessage(&canMsg3);
mcp2515.sendMessage(&canMsg4);
mcp2515.sendMessage(&canMsg5);
mcp2515.sendMessage(&canMsg6);
mcp2515.sendMessage(&canMsg1);
mcp2515.sendMessage(&canMsg7);


}
