#define LED_R 10
#define LED_G 11
#define LED_B 12
#define LED_SYG 13

#define PIR 2

volatile int ileRazy = 0;

void setup() {
  pinMode(LED_R, OUTPUT); //Poszczególne piny sterujące diodą jako wyjścia
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_SYG, OUTPUT);

  pinMode(PIR, INPUT); //PIR jako wejście

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);

  attachInterrupt(digitalPinToInterrupt(PIR), alarm, RISING); //Przerwanie reagujące na zbocze
}

void loop() {
  if (ileRazy < 3) { //Akceptowalnie - kolor zielony
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  } else if (ileRazy < 6) { //Zaczyna być groźnie - kolor niebieski
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  } else { //Alarm - ponad 6 razy wykryto ruch - kolor czerwony
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  }
}

void alarm() { //Przerwane
  ileRazy++; //Wykryto kolejny alarm
}