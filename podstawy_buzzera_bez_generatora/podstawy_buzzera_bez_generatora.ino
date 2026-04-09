void setup() {
  pinMode(A5, OUTPUT); //Konfiguaracja A5 jako wyjście
}

void loop() {
  tone(3, 1000); //Wygeneruj sygnał o częstotliwości 1000Hz na pinie A5
  delay(1000);
  noTone(A5); //Wyłącz generowanie sygnału
  delay(1000);
}
