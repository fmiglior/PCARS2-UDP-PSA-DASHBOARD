struct can_frame canMsg1; //0x0F6
struct can_frame canMsg2; //0x036
struct can_frame canMsg3; //0x0B6
struct can_frame canMsg4; //0x128
struct can_frame canMsg5; //0x168
struct can_frame canMsg6; //0x161
struct can_frame canMsg7; //0x2E9
struct can_frame canMsg8; //0x1A1

void carregaCAN () {
  // can code 1 = adjust the dashboard bright, odometer and water temp
 
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x8E; //ignition ON
  canMsg1.data[1] = 0x80; //water temp
  canMsg1.data[2] = 0xC1; //odometer part1
  canMsg1.data[3] = 0x05; //odometer part2
  canMsg1.data[4] = 0x4A; //odometer part3
  canMsg1.data[5] = 0x10;
  canMsg1.data[6] = 0x63;
  canMsg1.data[7] = 0x20;

// can code 2 is to keep on the dashboard
  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0x00;
  canMsg2.data[1] = 0x00;
  canMsg2.data[2] = 0x00;
  canMsg2.data[3] = 0x29; 
  canMsg2.data[4] = 0x21; 
  canMsg2.data[5] = 0x00;
  canMsg2.data[6] = 0x00;
  canMsg2.data[7] = 0xA0;

// can code 3 Sends RPM and SPEED 
  canMsg3.can_id  = 0x0B6;
  canMsg3.can_dlc = 8;
  canMsg3.data[0] = 0x00; //rpm
  canMsg3.data[1] = 0x00; 
  canMsg3.data[2] = 0x00; //speed
  canMsg3.data[3] = 0x00;
  canMsg3.data[4] = 0x00;
  canMsg3.data[5] = 0x00;
  canMsg3.data[6] = 0x00;
  canMsg3.data[7] = 0xA0;

 // can code 4 dashboard lights and gear
  canMsg4.can_id  = 0x128;
  canMsg4.can_dlc = 8;
  canMsg4.data[0] = 0x00; //light
  canMsg4.data[1] = 0x00; //gear
  canMsg4.data[2] = 0x00;
  canMsg4.data[3] = 0x00;
  canMsg4.data[4] = 0x00;
  canMsg4.data[5] = 0x00; 
  canMsg4.data[6] = 0x04; //keep some can2010 screens on.
  canMsg4.data[7] = 0x00; 
  
   // can code 5 dashboard lights 2
  canMsg5.can_id  = 0x168;
  canMsg5.can_dlc = 8;
  canMsg5.data[0] = 0x00;
  canMsg5.data[1] = 0x00;
  canMsg5.data[2] = 0x00;
  canMsg5.data[3] = 0x00; //abs
  canMsg5.data[4] = 0x00;
  canMsg5.data[5] = 0x00;
  canMsg5.data[6] = 0x00;
  canMsg5.data[7] = 0x00; 
   
    // fuel
  canMsg6.can_id  = 0x161;
  canMsg6.can_dlc = 7;
  canMsg6.data[0] = 0x00;
  canMsg6.data[1] = 0x00;
  canMsg6.data[2] = 0x00;
  canMsg6.data[3] = 0x00; //fuel gauge
  canMsg6.data[4] = 0x00;
  canMsg6.data[5] = 0x00;
  canMsg6.data[6] = 0x00;

 // COR PAINEL only for 3008 dashboard.
  canMsg7.can_id = 0x2E9;
  canMsg7.can_dlc = 3;
  canMsg7.data[0] = 0x01;
  canMsg7.data[1] = 0x50; //0x50 red 0x80 gray e 0x00 blue
  canMsg7.data[2] = 0x57;

//warnings
   canMsg8.can_id  = 0x1A1;
  canMsg8.can_dlc = 8;
  canMsg8.data[0] = 0x00; //7F hide the pop up - 80 shows
  canMsg8.data[1] = 0x00; //warning 01 temp engine, 11 suspension, e0 low fuel
  canMsg8.data[2] = 0xA4;
  canMsg8.data[3] = 0x00; 
  canMsg8.data[4] = 0x00;
  canMsg8.data[5] = 0x00;
  canMsg8.data[6] = 0x00; 
  canMsg8.data[7] = 0x00;   
}
