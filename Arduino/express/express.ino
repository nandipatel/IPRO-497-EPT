// SPDX-FileCopyrightText: 2017 Limor Fried for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

// Servo
Servo motor;
int position = 0;
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

  for (pixeln = 0; pixeln <= 9; pixeln++) {
    CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel(25 * pixeln));
    delay(150);
  }
  CircuitPlayground.clearPixels();
}
void loop() {
  if (CircuitPlayground.leftButton()) {
    CircuitPlayground.redLED(HIGH);
    motor.write(20);
    delay(3000);
    motor.write(0);
  } else {
    CircuitPlayground.redLED(LOW);
  }

  if (CircuitPlayground.rightButton()) {
    CircuitPlayground.redLED(HIGH);
    motor.write(45);
    delay(3000);
    motor.write(0);
  }

  if(CircuitPlayground.slideSwitch()) { // Will change it button 3
    CircuitPlayground.redLED(HIGH);
    motor.write(90);
    delay(3000);
    motor.write(0);
  }

  delay(100);
}
