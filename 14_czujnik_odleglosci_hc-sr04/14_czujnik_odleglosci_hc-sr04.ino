#define TrigPin 11 //Definicja pinów
#define EchoPin 12

void setup() {
  Serial.begin(9600); //Inicjalizacja komunikacji UART
  pinMode(TrigPin, OUTPUT); // Ustawienie pinu Trig jako wyjście
  pinMode(EchoPin, INPUT);  // Ustawienie pinu Echo jako wejście
}

void loop() {
  // Generowanie impulsu wyzwalającego (Trig)
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  // Pomiar czasu trwania impulsu na pinie Echo
  long czas = pulseIn(EchoPin, HIGH); 

  // Przeliczenie czasu na odległość w centymetrach
  int dystans = czas / 58; 
  
  // Wypisanie odległości na komputerze
  Serial.print(dystans);
  Serial.println(" cm");
  
  delay(500);
}
