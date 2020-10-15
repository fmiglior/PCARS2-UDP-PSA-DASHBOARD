
//variables

char ssid[] = ""; // network SSID 
char pass[] = ""; // network password 
unsigned int localPort = 5606; // Pcars UDP Port
char packetBuffer[1600]; //buffer for the UPD packet
int status = WL_IDLE_STATUS;
WiFiUDP Udp;

//pacote de envio
byte D1[15];
//D1[0] = 0; //packet begin
//D1[1] = 0; //RPM 
//D1[2] = 0; //speed 
//D1[3] = 0; //gear 
//D1[4] = 0;//headlight
//D1[5] = 0; //esp and abs
//D1[6] = 0; //
//D1[7] = 0; //water temp
//d1[8] = //Water temp warning light

//size of the packets
char telemetria = 559; //  telemetry packet
//char racestatsdata = 308; // racing data packet
//char dataparticipante = 1063; // timings data
//char gamestate = 24; // Game State.


//game variables

unsigned char sCarFlags; //17 - carflags
int sSpeed; // 36 a 39 - speed
//int sBrakeBias; // 554 - brake bias
char sGearNumGears; // 45 - gear 
//byte sThrottle; // 30 - throttle pedal signal
int sRpm; // 40-41 rpm
int sMaxRpm; //42 - 43 rpm max
 
float Div;
int resultado;
float sobra;



// Timers
uint32_t D2oldtime = millis();
uint32_t D2delay = 150; // 94
unsigned long currentMillisD2 = millis();
uint32_t D3oldtime = millis();
unsigned long currentMillisD3 = millis();
uint32_t D3delay = 376; // 
