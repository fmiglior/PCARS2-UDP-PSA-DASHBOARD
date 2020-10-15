union {
  byte uBytes[4];
  float uFloat;
  long uLong;
} uData;

union {
  byte sBytes[4];
  float sFloat;
  long sLong;
} sData;

 void convertFloatU(int startByte) {

  uData.uBytes[0] = packetBuffer[startByte];
  uData.uBytes[1] = packetBuffer[(startByte+1)];
  uData.uBytes[2] = packetBuffer[(startByte+2)];
  uData.uBytes[3] = packetBuffer[(startByte+3)];


 }

  void convertFloatS(int startByte) {

  uData.uBytes[0] = packetBuffer[startByte];
  uData.uBytes[1] = packetBuffer[(startByte+1)];
  uData.uBytes[2] = packetBuffer[(startByte+2)];
  uData.uBytes[3] = packetBuffer[(startByte+3)];


 }
