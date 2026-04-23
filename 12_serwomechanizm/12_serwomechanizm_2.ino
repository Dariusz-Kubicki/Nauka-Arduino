#include <Servo.h> //Biblioteka odpowiedzialna za serwa
#define pinServo 9
Servo serwomechanizm; //Tworzenie obiektu dzięki któremu można się odwołać do serwa
String odebraneDane = ""; //Odebrane dane String z UART
int daneInt = 0; //Przekształcone odebrane dane String z UART na dane int

void setup() {
  serwomechanizm.attach(pinServo); //Podłączenie serwomechanizmu do pinu pinServo
  Serial.begin(9600); //Inicjalizacja protokołu komunikacji UART
  Serial.println("Wpisz liczbę od 0-100");
}

void loop() {
  if (Serial.available() > 0) { //Czy Arduino odebrało dane
    odebraneDane = Serial.readStringUntil('\n'); //Jeśli tak to zapisz odebrane dane do zmiennej
    daneInt = odebraneDane.toInt(); // i zamień te dane na zmienną int
      if (daneInt <= 100 && daneInt >= 0) {
        byte pozycja = map(daneInt, 0, 100, 170, 27); //Skalowanie danych na gotową pozycję dla serwa dostosowaną do liczb na tarczy wskaźnika
        serwomechanizm.write(pozycja); //Ustawienie serwa na pozycję
      } else {
        Serial.println("Wpisz wartość od 0-100"); //Jeżeli nie wyślij komunikat
      }
  }    
    delay(30); // opóźnienie dla stabilności
}