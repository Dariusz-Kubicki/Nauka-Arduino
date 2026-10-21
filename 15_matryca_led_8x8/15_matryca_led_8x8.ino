// Lekcja 15: Matryca LED 8x8 - wyświetlanie serca
// Matryca 1088BS podłączona bez dodatkowego sterownika

const byte rows[8] = {
  9, 4, A4, 6, 10, A3, 11, A1
};

const byte cols[8] = {
  5, 12, A0, 8, A2, 7, 3, 2
};

// Obraz serca
// 1 = dioda świeci
// 0 = dioda jest zgaszona
const byte serce[8][8] = {
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

void setup() {
  for (byte i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);

    // Stan początkowy - wszystkie diody wyłączone
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}

void loop() {
  wyswietlSerce();
}

void wyswietlSerce() {
  for (byte r = 0; r < 8; r++) {
    for (byte c = 0; c < 8; c++) {

      if (serce[r][c] == 1) {
        // Zapalenie pojedynczej diody
        digitalWrite(cols[c], LOW);
        digitalWrite(rows[r], HIGH);

        delayMicroseconds(150);

        // Zgaszenie diody przed przejściem do następnej
        digitalWrite(rows[r], LOW);
        digitalWrite(cols[c], HIGH);
      }
    }
  }
}
