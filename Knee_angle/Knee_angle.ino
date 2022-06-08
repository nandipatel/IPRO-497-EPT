#include <bluefruit.h>

const int xInput = A0;
const int yInput = A1;
const int zInput = A2;

int xRawMin = 512;
int xRawMax = 512;

int yRawMin = 512;
int yRawMax = 512;

int zRawMin = 512;
int zRawMax = 512;

const int sampleSize = 10;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{

}
