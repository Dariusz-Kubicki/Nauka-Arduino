#include <LiquidCrystal.h>
#include <DHT.h>

// LCD 16x2: pin D2 zostal zamieniony na D9, aby zwolnic D2 dla PIR.
LiquidCrystal lcd(9, 3, 4, 5, 6, 7);

// Dioda RGB ze wspolna anoda (LOW = swieci, HIGH = nie swieci).
#define LED_B A0
#define LED_R A2
#define LED_G A1

#define DHT11 8
#define PIR 2

#define TrigPin 10
#define EchoPin 11

DHT dht;

// Zmienna modyfikowana przez przerwanie musi byc volatile.
volatile byte stanPIR = LOW;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Pomiar z");
  lcd.setCursor(0, 1);
  lcd.print("czujnika DHT11");

  dht.setup(DHT11);

  pinMode(PIR, INPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // Przy wspolnej anodzie wartosc 255 wylacza dany kolor.
  analogWrite(LED_G, 255);
  analogWrite(LED_R, 255);
  analogWrite(LED_B, 255);

  // Odczyt poczatkowego stanu, zanim wlaczymy przerwanie.
  stanPIR = digitalRead(PIR);

  pinMode(TrigPin, OUTPUT); // Ustawienie pinu Trig jako wyjscie
  pinMode(EchoPin, INPUT);  // Ustawienie pinu Echo jako wejscie

  // Arduino UNO: przerwanie zewnetrzne na D2; CHANGE wykrywa
  // zarowno pojawienie sie ruchu (HIGH), jak i koniec sygnalu (LOW).
  attachInterrupt(digitalPinToInterrupt(PIR), pir, CHANGE);
}

// Funkcja przerwania: tylko zapisuje stan czujnika.
// Nie wykonujemy tutaj obslugi LCD ani innych dlugich operacji.
void pir() {
  stanPIR = digitalRead(PIR);
}

// Wyswietlanie pomiarow w monitorze portu szeregowego.
void serialDHT(float temperatura, float wilgotnosc) {
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" C Wilgotnosc: ");
  Serial.print(wilgotnosc);
  Serial.println(" %RH");
}

// Wyswietlanie temperatury i wilgotnosci na LCD.
void lcdDHT(float temperatura, float wilgotnosc) {
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print((char)223); // Znak stopnia w typowym LCD HD44780.
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(wilgotnosc);
  lcd.print("%  ");
}

int hcsr04() {
  // Generowanie impulsu wyzwalajacego (Trig)
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // Pomiar czasu trwania impulsu na pinie Echo
  long czas = pulseIn(EchoPin, HIGH);

  // Przeliczenie czasu na odleglosc w centymetrach
  int dystans = czas / 58;

  // Wypisanie odleglosci na komputerze
  Serial.print(dystans);
  Serial.println(" cm");
  delay(50);

  return dystans;
}

void loop() {
  // Diodami sterujemy poza przerwaniem.
  // Typowy PIR: LOW = brak ruchu, HIGH = wykryto ruch.
  if (stanPIR == LOW) {
    digitalWrite(LED_R, HIGH); // Czerwona wylaczona.
    digitalWrite(LED_G, LOW);  // Zielona wlaczona (stan OK).
  } else {
    digitalWrite(LED_R, LOW);  // Czerwona wlaczona (alarm).
    digitalWrite(LED_G, HIGH); // Zielona wylaczona.
  }

  float wilgotnosc = dht.getHumidity();
  float temperatura = dht.getTemperature();

  if (isnan(wilgotnosc) || isnan(temperatura)) {
    Serial.println("Blad odczytu DHT11");
    delay(dht.getMinimumSamplingPeriod());
    return;
  }

  serialDHT(temperatura, wilgotnosc);
  lcdDHT(temperatura, wilgotnosc);

  if (hcsr04() < 101) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Prosze odejsc");
    lcd.setCursor(0, 1);
    lcd.print(hcsr04());
    lcd.print("cm");
  }

  // Opoznienie dotyczy wyswietlania i odczytu DHT.
  // Przerwanie dalej zapamietuje stan PIR, ale kolor LED
  // moze zareagowac z opoznieniem do okolo 1 sekundy.
  delay(1000);
}
