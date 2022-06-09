/*
 * This ino file is only used for testing purposes
 * The code in this folder might or might not be working at the time you open this
 * Test 1 = Callibration
 * RESULT = SUCCESS
 * 
 * Test 2 = MinValues = 467, MaxValues = 575
 * RESULT = FAILURE
 * 
 * Test 3 = Sensing orientation (For Some reasons the data give me above 350)
 * RESULT= FAILURE
 * 
 * Test 4 = Testing another code
 * RESULT = FAILURE
 * 
 * Test 5 = Zmin = 381, Zmax = 563, yMin = 370, yMax = 551, xMin = 371, xMax = 550
 * RESULT = SUCCESS by giving acceleration g of -1 to 1 g
 * 
 * Test 6 = The ADXL335 only giving data from -1 g to 1 g only. Need to convert it to angle for the leg
 * RESULT = X VALUE GIVING ME 360 DEGRESS (UNDEFINED)
 */
 
// Analog read pins
const int xPin = A3;
const int yPin = A2;
const int zPin = A1;

int xValue;
int yValue;
int zValue;

void setup() {
  Serial.begin(115200);
}

void loop() {

  // g values
  xValue = analogRead(xPin);
  int x = map(xValue, 371, 550, -90, 90);
  float xg = (float)x / (-100.00);
  Serial.print(xg);
  Serial.print("g \t");

  yValue = analogRead(yPin);
  int y = map(yValue, 370, 551, -100, 100);
  float yg = (float)y / (-100.00);
  Serial.print(yg);
  Serial.print("g \t");

  zValue = analogRead(zPin);
  int z = map(yValue, 381, 563, -100, 100);
  float zg = (float)z / (-100.00);
  Serial.print(zg);
  Serial.print("g \n");

  // Rotation / Angle
  Serial.print("x= ");
  float xAng = atan2(-yg, -zg) * 57.2957795 + 180;
  Serial.print(xAng);
  Serial.println(" deg");

  delay(500);
}
