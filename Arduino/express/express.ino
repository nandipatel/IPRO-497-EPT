#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

// Servo
Servo motor;
int position = 0;

// Buttons
const int BUTTON1 = A1;

// Button State
int buttonState1 = 0;

// Neo-pixel
uint8_t pixeln = 0;

void setup() {
  if (!CircuitPlayground.begin()) {
    pinMode(13, OUTPUT);
    while (1) {
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
    }
  }
  motor.attach(A2);
  motor.write(0);

  // Initial Test the Neo Pixel
  for (pixeln = 0; pixeln <= 9; pixeln++) {
    CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    delay(150);
  }
  CircuitPlayground.clearPixels();

  // Set pixeln to 0
  pixeln = 0;

  // INPUT
  pinMode(BUTTON1, INPUT);
}
void loop() {
  if (CircuitPlayground.leftButton()) {
    CircuitPlayground.redLED(HIGH);
    motor.write(20);

    for (pixeln = 0; pixeln < 1; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
      delay(150);
    }

    delay(3000);
    motor.write(0);

    CircuitPlayground.clearPixels();
  } else {
    CircuitPlayground.redLED(LOW);
  }

  if (CircuitPlayground.rightButton()) {
    CircuitPlayground.redLED(HIGH);
    motor.write(45);

    for (pixeln = 0; pixeln < 3; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
      delay(150);
    }

    delay(3000);
    motor.write(0);

    CircuitPlayground.clearPixels();
  } else {
    CircuitPlayground.redLED(LOW);
  }

  /*if(CircuitPlayground.slideSwitch()) { // Will change it button 3
    CircuitPlayground.redLED(HIGH);
    motor.write(90);

    for(pixeln =0; pixeln < 5; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    delay(150);
    }
    delay(3000);
    motor.write(0);

    CircuitPlayground.clearPixels();
    } else {
    CircuitPlayground.redLED(LOW);
    } */

  buttonState1 = digitalRead(BUTTON1);
  if (buttonState1 == HIGH) {
    CircuitPlayground.redLED(HIGH);
    motor.write(140);

    for (pixeln = 0; pixeln < 5; pixeln++) {
      CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
      delay(150);
    }
    
    delay(3000);
    
    motor.write(0);
    CircuitPlayground.clearPixels();
  } else {
    CircuitPlayground.redLED(LOW);
  }

  delay(100);
}
