#define czerwona 3
#define zielona 5
#define niebieska 6

void setup() {
  pinMode(czerwona, OUTPUT); //Piny, podłączone do diody jako wyjścia
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
}

void loop() {
  digitalWrite(czerwona, HIGH); //Świecimy tylko na czerwono
  delay(2000);
  digitalWrite(czerwona, LOW); //Świecimy tylko na zielono
  digitalWrite(zielona, HIGH);
  delay(2000);
  digitalWrite(zielona, LOW); //Świecimy tylko na niebiesko
  digitalWrite(niebieska, HIGH);
  delay(2000);
  digitalWrite(niebieska, LOW);

  digitalWrite(czerwona, HIGH); //Świecimy każdą po kolei, bez gaszenia poprzedniej
  delay(2000);
  digitalWrite(zielona, HIGH);
  delay(2000);
  digitalWrite(niebieska, HIGH);
  delay(2000);

  digitalWrite(czerwona, LOW); //wyłączamy wszystkie diody
  digitalWrite(zielona, LOW);
  digitalWrite(niebieska, LOW);
  delay(2000);
}
