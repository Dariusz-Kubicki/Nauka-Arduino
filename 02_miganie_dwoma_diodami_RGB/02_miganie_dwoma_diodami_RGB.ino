//definicja wyprowadzeń pierwszej diody
#define czerwona 3
#define zielona 5
#define niebieska 6

//definicja wyprowadzeń drugiej diody
#define czerwona2 9
#define zielona2 10
#define niebieska2 11

void setup() {
  pinMode(czerwona, OUTPUT); //konfiguracja wyprowadzeń jako wyjścia
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
  pinMode(czerwona2, OUTPUT);
  pinMode(zielona2, OUTPUT);
  pinMode(niebieska2, OUTPUT);
}

void loop() {
  digitalWrite(czerwona, HIGH); //miganie diodami, z użyciem różnych kolorów
  digitalWrite(zielona2, HIGH);
  delay(1000);
  digitalWrite(czerwona, LOW);
  digitalWrite(zielona2, LOW);
  digitalWrite(niebieska, HIGH);
  digitalWrite(czerwona2, HIGH);
  delay(1000);
  digitalWrite(niebieska, LOW);
  digitalWrite(czerwona2, LOW);
}