// C++ Code
//
#include <Servo.h>

//Servo Motor
Servo motor;
int position = 0;

// Button
const int BUTTON1 = 2;
const int BUTTON2 = 4;
const int BUTTON3 = 7;

// LED
const int RED = 13;
const int BLUE = 12;
const int GREEN = 8;

// Button State
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);

  // OUTPUT
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // SERVO
  motor.attach(9);
  motor.write(0);

  // Initial Light Check - time in microseconds
  digitalWrite(RED, HIGH);
  delay(500); //0.5 seconds
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  delay(500);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN,HIGH);
  delay(500);
  digitalWrite(GREEN,LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(BUTTON1); // move to 0 degree if clicked
  if(buttonState1 == HIGH) {
    digitalWrite(RED, HIGH);
    motor.write(0);
  }
  else {
    digitalWrite(RED, LOW);
  }
  
  buttonState2 = digitalRead(BUTTON2); // move to 90 degree if clicked
  if(buttonState2 == HIGH) {
    digitalWrite(BLUE, HIGH);
    motor.write(90);
  }
  else {
    digitalWrite(BLUE, LOW);
  }
  
  buttonState3 = digitalRead(BUTTON3); // move to 140 degree if clicked
  if(buttonState3 == HIGH) {
    digitalWrite(GREEN, HIGH);
    motor.write(140);
  }
  else {
    digitalWrite(GREEN,LOW); 
  }
}
