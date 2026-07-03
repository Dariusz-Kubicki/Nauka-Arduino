#define TrigPin 11 //Definicja pinów
#define EchoPin 12

void setup() {
  Serial.begin(9600); //Inicjalizacja komunikacji UART
  pinMode(TrigPin, OUTPUT); //Ustawienie pinu Trig na wyjście
  pinMode(EchoPin, INPUT); //Ustawienie pinu Echo na wejście 
}

void loop() {
  digitalWrite(TrigPin, LOW); //Wykonanie pomiaru
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  long czas = pulseIn(EchoPin, HIGH); //Zmierzenie czasu trwania impulsu na pinie Echo
  int dystans = czas / 58; //Przekonwertowanie wyniku na centymetry

  Serial.print(dystans); //Wypisanie odległości na komputerze
  Serial.println(" cm");
  
  delay(500);
}