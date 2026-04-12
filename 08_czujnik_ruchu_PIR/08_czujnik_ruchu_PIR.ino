#define LED_R 10
#define LED_G 11
#define LED_B 12

#define PIR 2
#define BUZZER 1

void setup() {
  pinMode(LED_R, OUTPUT); //Poszczególne piny sterujące diodą jako wyjścia
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  pinMode(BUZZER, OUTPUT); //Buzzer jako wyjście
  pinMode(PIR, INPUT); //PIR jako wejście

  digitalWrite(LED_R, LOW); //Dioda wyłączona
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}

void loop() {
  if (digitalRead(PIR) == LOW) { //Jeśli wykryto ruch
    digitalWrite(LED_R, LOW); //Stan OK - dioda zielona 
    digitalWrite(LED_G, HIGH);
    noTone(BUZZER);
  } else {
    digitalWrite(LED_R, HIGH); //Stan ALARM - dioda czerwona
    digitalWrite(LED_G, LOW);
    tone(BUZZER, 392, 150); //Melodyjka sygnalizacyjna ruch
    delay(200);
    tone(BUZZER, 523, 150);
    delay(200);
    tone(BUZZER, 659, 200);
    delay(250);
    noTone(BUZZER);
  }
}