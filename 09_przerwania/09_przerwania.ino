#define LED_R 10
#define LED_G 11
#define LED_B 12
#define LED_SYG 13

#define PIR 2

void setup() {
  pinMode(LED_R, OUTPUT); //Poszczególne piny sterujące diodą jako wyjścia
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_SYG, OUTPUT);

  pinMode(PIR, INPUT); //PIR jako wejście

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, LOW);

  attachInterrupt(digitalPinToInterrupt(PIR), alarm, RISING); //Przerwanie reagujące na zbocze
}

void loop() {
  digitalWrite(LED_SYG, HIGH);
  delay(1000);
  digitalWrite(LED_SYG, LOW);
  delay(1000);
}

void alarm() {
  digitalWrite(LED_R, HIGH); //Stan ALARM - dioda czerwona
  digitalWrite(LED_G, LOW);
}