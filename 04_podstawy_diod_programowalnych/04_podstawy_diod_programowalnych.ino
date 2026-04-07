#include <Adafruit_NeoPixel.h> //Dołączenie biblioteki

//konfiguracja linijki
Adafruit_NeoPixel linijka = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800);

void setup() {
  linijka.begin(); //Inicjalizacja
  linijka.show();

  for(int wartosc = 0; wartosc < 8; wartosc++) //Pętla która zapala wszystkie diody na mój ulubiony kolor
    linijka.setPixelColor(wartosc, linijka.Color(0, 255, 255));
  linijka.show();
}

void loop() {

}