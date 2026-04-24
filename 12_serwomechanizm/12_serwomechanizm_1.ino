#include <Servo.h> //Biblioteka odpowiedzialna za serwa

Servo serwomechanizm; //Tworzenie obiektu, dzięki któremu możemy odwołać się do serwa
int pozycja = 180; //Atualna pozycja serwa (u mnie serwo działa w przeciwną stronę do wskazówek zegara)
int zmiana = 6; //Co ile ma się zmieniać pozycja serwa

void setup() {
  serwomechanizm.attach(9); //Serwomechanizm podłączony do pinu 9
}

void loop() {
  if (pozycja > 0) { //Jeśli pozycja mieści się w zakresie
    serwomechanizm.write(pozycja); //Wykonaj ruch
  } else { //Jeśli nie, to powrót na początek
    pozycja = 180;
  }

  pozycja = pozycja - zmiana; //Zwiększenie aktualnej pozycji serwa
  delay(200); //Opóźnienie dla lepszego efektu
}
