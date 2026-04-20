#include <Adafruit_NeoPixel.h>
#include <Servo.h>

// --- KONFIGURACJA PINÓW ---
#define PIN_LED      A0    // Pin paska WS2812
#define NUM_LEDS     8    // Ilość diod w Twoim pasku
#define PIN_TRIG     2    // Pin Trig czujnika HC-SR04
#define PIN_ECHO     3    // Pin Echo czujnika HC-SR04
#define PIN_SERVO    9    // Pin sygnałowy serwa

// --- OBIEKTY ---
Adafruit_NeoPixel pixels(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);
Servo mojeServo;

void setup() {
  pixels.begin();
  pixels.setBrightness(50); // Jasność 0-255 (oszczędzaj prąd z USB!)
  
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  mojeServo.attach(PIN_SERVO);
  
  Serial.begin(9600);
}

void loop() {
  // 1. Pomiar odległości
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  long czas = pulseIn(PIN_ECHO, HIGH);
  int odleglosc = czas / 58; // Wynik w centymetrach

  // Ignoruj błędy czujnika (np. 0 lub poza zakresem)
  if (odleglosc <= 0 || odleglosc > 100) odleglosc = 100;

  // 2. Mapowanie wartości na ruch i kolory
  // Zakres reakcji: 5cm do 50cm
  int katSerwa = map(odleglosc, 5, 50, 0, 180);
  katSerwa = constrain(katSerwa, 20, 170); // Ograniczenie zakresu
  
  int intensywnoscR = map(odleglosc, 5, 50, 255, 0);   // Im bliżej, tym bardziej czerwono
  int intensywnoscG = map(odleglosc, 5, 50, 0, 255);   // Im dalej, tym bardziej zielono
  
  intensywnoscR = constrain(intensywnoscR, 0, 255);
  intensywnoscG = constrain(intensywnoscG, 0, 255);

  // 3. Sterowanie serwem
  mojeServo.write(katSerwa);

  // 4. Sterowanie diodami WS2812
int zapaloneDiody = map(odleglosc, 5, 50, NUM_LEDS, 1); 
  zapaloneDiody = constrain(zapaloneDiody, 1, NUM_LEDS);

  pixels.clear(); // Czyścimy pasek przed nowym ustawieniem

  for(int i = 0; i < zapaloneDiody; i++) {
    // Ustawiamy kolor (ten sam, który wyliczyliśmy wcześniej)
    pixels.setPixelColor(i, pixels.Color(intensywnoscR, intensywnoscG, 0));
  }
  
  pixels.show();

  delay(10); // Krótka przerwa dla stabilności
}