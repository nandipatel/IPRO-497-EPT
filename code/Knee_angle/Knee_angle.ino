/*
   This ino file is only used for testing purposes
   The code in this folder might or might not be working at the time you open this
   Test 1 = Callibration
   RESULT = SUCCESS

   Test 2 = MinValues = 467, MaxValues = 575
   RESULT = FAILURE

   Test 3 = Sensing orientation (For Some reasons the data give me above 350)
   RESULT= FAILURE

   Test 4 = Testing another code
   RESULT = FAILURE

   Test 5 = Zmin = 381, Zmax = 563, yMin = 370, yMax = 551, xMin = 371, xMax = 550
   RESULT = SUCCESS by giving acceleration g of -1 to 1 g

   Test 6 = The ADXL335 only giving data from -1 g to 1 g only. Need to convert it to angle for the leg
   RESULT = X VALUE GIVING ME 360 DEGRESS (UNDEFINED)

   Test 7 = The ADXL335 Seems giving a result that we might want from z values. So, we decided to use z-values
   RESULT = Z Values giving a correct values? IDK (SUCCESS)

   Test 8 = Testing the bluetooth features
   RESULT = SUCCESS
*/

#include <bluefruit.h>

// OTA DFU service
BLEDfu bledfu;

// Uart over BLE service
BLEUart bleuart;

// Function prototypes for packetparser.cpp
uint8_t readPacket (BLEUart *ble_uart, uint16_t timeout);
float   parsefloat (uint8_t *buffer);
void    printHex   (const uint8_t * data, const uint32_t numBytes);

// Packet buffer
extern uint8_t packetbuffer[];

// Analog read pins
const int xPin = A3;
const int yPin = A2;
const int zPin = A1;

const int rxPin = 21;
const int txPin = 19;

int xValue;
int yValue;
int zValue;

void setup() {
  Serial.begin(9600);

  Bluefruit.begin();
  Bluefruit.setTxPower(4);

  // To be consistent OTA DFU should be added first if it exists
  bledfu.begin();

  // Configure and start the BLE Uart service
  bleuart.begin();

  // Set up and start advertising
  startAdv();
}

void startAdv(void)
{
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  // Include the BLE UART (AKA 'NUS') 128-bit UUID
  Bluefruit.Advertising.addService(bleuart);

  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();

  /* Start Advertising
     - Enable auto advertising if disconnected
     - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
     - Timeout for fast mode is 30 seconds
     - Start(timeout) with timeout = 0 will advertise forever (until connected)

     For recommended advertising interval
     https://developer.apple.com/library/content/qa/qa1931/_index.html
  */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}

void loop() {

  bleuart.print("Position: ");
  // g values
  xValue = analogRead(xPin);
  int x = map(xValue, 371, 550, -90, 90);
  float xg = (float)x / (-100.00);
  Serial.print(xg);
  Serial.print("g \t");

  //bleuart.print(xg);
  //bleuart.print("g \t");

  yValue = analogRead(yPin);
  int y = map(yValue, 370, 551, -100, 100);
  float yg = (float)y / (-100.00);
  Serial.print(yg);
  Serial.print("g \t");

  //bleuart.print(yg);
  //bleuart.print("g \t");

  zValue = analogRead(zPin);
  int z = map(yValue, 381, 563, -100, 100);
  float zg = (float)z / (-100.00);
  Serial.print(zg);
  Serial.print("g \n");

  //bleuart.print(zg);
  //bleuart.print("g \n");

  // Rotation / Angle
  Serial.print("x= ");
  float xAng = atan2(-yg, -zg) * 57.2957795 + 180;
  delay(1);
  Serial.print(xAng);
  Serial.print(" deg \t");

  //bleuart.print(xAng);
  //bleuart.print(" deg \t");

  Serial.print("y = ");
  float yAng = atan2(-xg, -zg) * 57.2957795 + 180;
  delay(1);
  Serial.print(yAng);
  Serial.print(" deg \t");

  //bleuart.print(yAng);
  //bleuart.print(" deg \t");

  Serial.print("z = ");
  float zAng = (atan2(-yg, -xg) * 57.2957795 - 180) * -1;
  delay(1);
  Serial.print(zAng);
  Serial.print(" deg \t");

  bleuart.print(zAng);
  bleuart.print(" deg \t");

  Serial.println("\n");
  bleuart.println("\n");
  
  delay(1000);
}
