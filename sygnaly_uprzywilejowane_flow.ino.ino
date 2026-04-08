#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel linijka = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800);

void setup() {
  linijka.begin();
  linijka.show();
}

void loop() {
  for(int i = 0; i < 8; i++) {
    if (i < 4) {
      linijka.setPixelColor(i, linijka.Color(255,0 , 0));
    } else {
      linijka.setPixelColor(i, linijka.Color(0, 0, 255));
    }

    linijka.show();
    delay(100);
  }
  linijka.clear();
}