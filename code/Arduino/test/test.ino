// This ino file is only used for testing purposes
// The code in this folder might or might not be working at the time you open this
// Test 1 = Callibration
// Test 2 = MinValues = 467, MaxValues = 575
// Test 3 = Sensing orientation (For Some reasons the data give me above 350)
// Test 4 = Testing another code
// Test 5 = Zmin = 381, Zmax = 563, yMin = 370, yMax = 551, xMin = 371, xMax = 550

// Analog read pins
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

int xValue;
int yValue;
int zValue;

void setup() {
  Serial.begin(9600);
}

void loop() {

  xValue = analogRead(xPin);
  int x = map(xValue, 371, 550, -100, 100);
  float xg = (float)x/(-100.00);
  Serial.print(xg);
  Serial.print("g \t");

  yValue = analogRead(yPin);
  int y = map(yValue, 370, 551, -100, 100);
  float yg = (float)y/(-100.00);
  Serial.print(yg);
  Serial.print("g \t");

  zValue = analogRead(zPin);
  int z = map(yValue, 381, 563, -100, 100);
  float zg = (float)z/(-100.00);
  Serial.print(zg);
  Serial.print("g \n");

  delay(100);
}
