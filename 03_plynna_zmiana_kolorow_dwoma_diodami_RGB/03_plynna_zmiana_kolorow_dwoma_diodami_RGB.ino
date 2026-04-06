#define czerwona 6 //definicja pierwszej diody
#define zielona 5
#define niebieska 3

#define czerwona2 11 //definicja drugiej diody
#define zielona2 10
#define niebieska2 9

void setup() {
  pinMode(czerwona, OUTPUT); //konfiguracja wyprowadzeń jako wyjścia
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
  pinMode(czerwona2, OUTPUT);
  pinMode(zielona2, OUTPUT);
  pinMode(niebieska2, OUTPUT);

  randomSeed(analogRead(A5)); //ziarno dla generatora liczb losowych
}

void loop() {
  int zmianaLosowa = random(255);
  int zmiana = 0;

  for (zmiana = 0; zmiana < 255; zmiana++) { //płynna zmiana kolorów
    analogWrite(czerwona, zmianaLosowa);
    analogWrite(zielona, zmiana);
    analogWrite(niebieska, 255 - zmiana);

    analogWrite(czerwona2, zmiana);
    analogWrite(zielona2, 255 - zmiana);
    analogWrite(niebieska2, zmianaLosowa);

    delay(10); //krótkie opóźnienie, aby efekt był widoczny dla ludzkiego oka
  }

    for (zmiana = 255; zmiana > 0; zmiana--) { //płynna zmiana kolorów wstecz
    analogWrite(czerwona, zmianaLosowa);
    analogWrite(zielona, zmiana);
    analogWrite(niebieska, 255 - zmiana);

    analogWrite(czerwona2, zmiana);
    analogWrite(zielona2, 255 - zmiana);
    analogWrite(niebieska2, zmianaLosowa);

    delay(10); //krótkie opóźnienie, aby efekt był widoczny dla ludzkiego oka
  }
}