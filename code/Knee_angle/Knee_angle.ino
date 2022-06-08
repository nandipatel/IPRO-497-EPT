#include <bluefruit.h>
#include <math.h>       /* atan2 */


const int xInput = A0;
const int yInput = A1;
const int zInput = A2;

int RawMin = 0;
int RawMax = 1023;

const int sampleSize = 10;

double roll = 0.00, pitch = 0.00, pitch2 = 0.00;
void setup()
{
  Serial.begin(9600); 
  Serial.println("Knee Brace Callibration test"); 
}

void loop()
{
  // Read raw values
  double xRaw = ReadAxis(xInput);
  double yRaw = ReadAxis(yInput);
  double zRaw = ReadAxis(yInput);

  /* Convert raw values to 'milli-Gs"
  long xScaled = map(xRaw, RawMin, RawMax, -100, 100);
  long yScaled = map(yRaw, RawMin, RawMax, -100, 100);
  long zScaled = map(zRaw, RawMin, RawMax, -100, 100);

  // re-scale to fractional Gs
  float xAccel = xScaled / 1000.0;
  float yAccel = yScaled / 1000.0;
  float zAccel = zScaled / 1000.0; */

  roll = atan2(yRaw, zRaw) * 57.3;
  pitch = atan2((xRaw) , sqrt(yRaw * yRaw + zRaw * zRaw)) * 57.3;
  pitch2 = atan2((yRaw) , sqrt(xRaw * xRaw + zRaw * zRaw)) * 57.3;
  
  
  Serial.print(roll);
  Serial.print(" deg,");
  Serial.print(pitch);
  Serial.print(" deg, ");
  Serial.print(pitch2);
  Serial.println(" deg");
  
  delay(200);
}

int ReadAxis(int axisPin)
{
  long reading = 0;
  analogRead(axisPin);
  
  delay(1);
  
  for(int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(axisPin);
  }
  return reading / sampleSize;
}
