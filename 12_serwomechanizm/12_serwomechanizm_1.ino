#include <Servo.h>

Servo serwomechanizm;
int pozycja = 180;
int zmiana = 6;

void setup() {
  serwomechanizm.attach(9);
}

void loop() {
  if (pozycja > 0) {
    serwomechanizm.write(pozycja);
  } else {
    pozycja = 180;
  }

  pozycja = pozycja - zmiana;
  delay(200);
}
