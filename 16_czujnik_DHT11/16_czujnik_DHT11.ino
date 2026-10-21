#include "DHT.h" // Biblioteka do obsługi czujników DHT używana w kursie Forbot

#define DHT11_PIN 2 // Pin DATA czujnika DHT11

DHT dht; // Utworzenie obiektu do obsługi czujnika

void setup() {
  Serial.begin(9600); // Uruchomienie komunikacji z komputerem
  dht.setup(DHT11_PIN); // Konfiguracja czujnika podłączonego do pinu D2
}

void loop() {
  float wilgotnosc = dht.getHumidity();     // Odczyt wilgotności
  float temperatura = dht.getTemperature(); // Odczyt temperatury

  // isnan() sprawdza, czy odczyt jest nieprawidłowy (NaN - Not a Number)
  if (isnan(wilgotnosc) || isnan(temperatura)) {
    Serial.println("Blad odczytu DHT11");
    delay(dht.getMinimumSamplingPeriod());
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" *C   Wilgotnosc: ");
  Serial.print(wilgotnosc);
  Serial.println(" %RH");

  // Minimalny czas wymagany przez czujnik pomiędzy kolejnymi pomiarami
  delay(dht.getMinimumSamplingPeriod());
}
