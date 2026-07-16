#include <Stepper.h>

#define STEPS 32

const int buttonPin1 = 12;
const int buttonPin2 = 13;
const int LED1 = 6;
const int LED2 = 7;

Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  stepper.setSpeed(500);
}

void loop() {
  int btn1 = digitalRead(buttonPin1);
  int btn2 = digitalRead(buttonPin2);

  if (btn1 == LOW) {
    digitalWrite(LED1, HIGH);
    stepper.step(50);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (btn2 == LOW) {
    digitalWrite(LED2, HIGH);
    stepper.step(-50);
  } else {
    digitalWrite(LED2, LOW);
  }
}
