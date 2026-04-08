#include <Adafruit_NeoPixel.h> //dołączanie biblioteki

Adafruit_NeoPixel linijka = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800); //konfiguracja linijki

void setup() {
  linijka.begin(); //inicjalizacja
  linijka.show();
}

void loop() {
  for(int i = 0; i < 8; i++)
  linijka.setPixelColor(i, linijka.Color(255, 0, 0)); //dioda nr i świeci na wybrany kolor
  linijka.show();

  delay(250);

  for(int i = 0; i < 8; i++)
  linijka.setPixelColor(i, linijka.Color(0, 0, 255)); //dioda nr i świeci na wybrany kolor
  linijka.show();

  delay(250);
}