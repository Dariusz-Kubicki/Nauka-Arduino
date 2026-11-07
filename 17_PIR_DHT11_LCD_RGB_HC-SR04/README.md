# Lekcja 17: Połączenie PIR, DHT11, LCD, RGB i HC-SR04

Ćwiczenie wykonane podczas pracowni zawodowej **28 października 2026 r.**

W tym projekcie połączyłem w jeden układ kilka elementów, które wcześniej były przerabiane osobno: **PIR, DHT11, LCD 16x2, diodę RGB oraz HC-SR04**.

Nie był to już projekt polegający na poznaniu pojedynczego czujnika, tylko na połączeniu kilku wcześniejszych lekcji w jeden działający program.

### Czego się nauczyłem:
* Łączenia kilku wcześniej poznanych modułów w jednym projekcie.
* Dzielenia programu na mniejsze funkcje zamiast umieszczania całej logiki w `loop()`.
* Wykorzystania przerwania PIR razem z innymi, wolniejszymi elementami programu.
* Rozdzielenia informacji pomiędzy LCD, Monitor portu szeregowego i diodę RGB.
* Tworzenia prostych trybów działania układu zależnych od danych z czujników.

## Jak działa projekt?

Układ zbiera informacje z trzech czujników:

* **DHT11** – temperatura i wilgotność,
* **PIR** – wykrycie ruchu,
* **HC-SR04** – odległość od obiektu.

Następnie wykorzystuje dwa elementy wyjściowe:

* **LCD 16x2** – pokazuje wyniki i komunikaty,
* **diodę RGB** – sygnalizuje stan czujnika PIR.

W normalnym stanie na wyświetlaczu widoczna jest temperatura i wilgotność:

```text
Temp: 21.00°C
Humidity: 36.00%
```

Jeżeli HC-SR04 wykryje obiekt znajdujący się wystarczająco blisko, LCD przechodzi w tryb ostrzegawczy:

```text
Prosze odejsc
XXcm
```

Jednocześnie PIR działa niezależnie i zmienia kolor diody RGB:

* **zielony** – brak wykrytego ruchu,
* **czerwony** – wykryto ruch.

## Wykorzystanie wcześniejszych lekcji

Ten projekt łączy rozwiązania, które wcześniej pojawiły się już w repozytorium:

* **PIR** – lekcja 8,
* **przerwania** – lekcje 9 i 10,
* **HC-SR04** – lekcja 14,
* **DHT11** – lekcja 16.

Dlatego nie opisuję tutaj ponownie działania tych elementów od podstaw. Ta lekcja skupia się na tym, jak zostały połączone w jeden większy program.

## Organizacja kodu

Żeby `loop()` nie stał się jedną długą sekcją kodu, część zadań została przeniesiona do własnych funkcji.

### `serialDHT()`

```C++
void serialDHT(float temperatura, float wilgotnosc)
```

Odpowiada za wypisywanie temperatury i wilgotności w Monitorze portu szeregowego.

### `lcdDHT()`

```C++
void lcdDHT(float temperatura, float wilgotnosc)
```

Wyświetla te same dane na LCD.

### `hcsr04()`

```C++
int hcsr04()
```

Wykonuje pomiar odległości i zwraca wynik w centymetrach.

Dzięki temu w głównej pętli można użyć prostego warunku:

```C++
if (hcsr04() < 101)
```

zamiast umieszczać cały kod pomiaru HC-SR04 bezpośrednio w `loop()`.

## PIR i przerwanie w większym programie

PIR jest podłączony do pinu **D2**, który w Arduino UNO może obsługiwać przerwanie zewnętrzne.

```C++
attachInterrupt(digitalPinToInterrupt(PIR), pir, CHANGE);
```

Sama funkcja przerwania pozostaje bardzo krótka:

```C++
void pir() {
  stanPIR = digitalRead(PIR);
}
```

To było tutaj szczególnie ważne, ponieważ pozostała część programu wykonuje pomiary, obsługuje LCD i zawiera opóźnienia.

Przerwanie nie wykonuje tych operacji bezpośrednio. Zapisuje tylko aktualny stan PIR, a właściwa reakcja następuje później w `loop()`.

## Dioda RGB jako sygnalizacja stanu

W projekcie wykorzystałem diodę RGB ze wspólną anodą:

```C++
#define LED_B A0
#define LED_R A2
#define LED_G A1
```

Stan PIR jest zamieniany na prosty sygnał wizualny:

```C++
if (stanPIR == LOW) {
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, LOW);
} else {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
}
```

Dzięki temu nie trzeba patrzeć na Monitor portu szeregowego, aby wiedzieć, czy PIR wykrył ruch.

## LCD jako wspólny interfejs

LCD pełni w projekcie dwie role.

W normalnym trybie pokazuje dane z DHT11:

```C++
lcdDHT(temperatura, wilgotnosc);
```

Po wykryciu obiektu przez HC-SR04 ekran zostaje chwilowo wykorzystany do pokazania ostrzeżenia i zmierzonej odległości:

```C++
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Prosze odejsc");
```

Jeden wyświetlacz jest więc używany przez dwie różne części programu zależnie od aktualnej sytuacji.

## Biblioteki

W projekcie wykorzystałem:

```C++
#include <LiquidCrystal.h>
#include <DHT.h>
```

`LiquidCrystal.h` obsługuje LCD 16x2.

Do DHT11 wykorzystana została ta sama biblioteka co w poprzedniej lekcji:

[markruys/arduino-DHT](https://github.com/markruys/arduino-DHT)

## Najważniejsze przypisania pinów

```C++
LiquidCrystal lcd(9, 3, 4, 5, 6, 7);

#define LED_B A0
#define LED_R A2
#define LED_G A1

#define DHT11 8
#define PIR 2

#define TrigPin 10
#define EchoPin 11
```

Pin D2 został przeznaczony dla PIR, ponieważ jest wykorzystywany do przerwania zewnętrznego.

## Dwa tryby działania

### Tryb ostrzegawczy

Gdy HC-SR04 wykryje obiekt znajdujący się blisko czujnika, LCD przestaje chwilowo wyświetlać temperaturę i wilgotność, a zamiast tego pokazuje komunikat ostrzegawczy oraz odległość.

![Tryb ostrzegawczy](zdjecie_projektu.jpg)

### Tryb pomiaru temperatury i wilgotności

W normalnym trybie LCD pokazuje aktualną temperaturę oraz wilgotność zmierzoną przez DHT11.

![Tryb pomiaru temperatury i wilgotności](zdjecie_dzialania.jpg)

## Pliki w projekcie

* `17_PIR_DHT11_LCD_RGB_HC-SR04.ino` – kod programu,
* `zdjecie_projektu.jpg` – zdjęcie trybu ostrzegawczego,
* `zdjecie_dzialania.jpg` – zdjęcie trybu pomiaru temperatury i wilgotności,
* `schemat_projektu.jpg` – schemat połączeń wykonany we Fritzing,
* `prezentacja_dzialania.gif` – prezentacja działania całego układu.

## Schemat połączeń

![Schemat projektu](schemat_projektu.jpg)

## Prezentacja działania

![Prezentacja działania](prezentacja_dzialania.gif)
