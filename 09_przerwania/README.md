# Lekcja 9: Przerwania
Podstawowe ćwiczenie z kursu **Arduino cz. 2** od **Forbot**. Dzisiaj przyjrzałem się przerwanią w Arduino oraz zbudowałem projekt stosując wcześniej wspomniane przerwania oraz czujnik ruchu PIR z wcześniejszych lekcji.

### Czego się nauczyłem:
* Co to przerwania i jak je stosować.
* Poznałem funkcję `attachInterrupt()`.
* Poznałem funkcję `digitalPinToInterrupt()`

### Co to przerwania?
Przedstawię to na przykładzie z życia wziętym.
Wyobraź sobie, że czytasz książkęi czekasz na kuriera. Możesz co minutę wstawać i zaglądać przez okno, czy już podjechał (to jest tzw. polling, czyli sprawdzanie stanu w pętli loop), ale to strata czasu i energii, plus nadal jest ryzyko, że kurier podjedzie w momencie w którym nas nie będzie przy oknie.
Dużo lepiej jest kupić dzwonek i po porostu czytać dalej, a dzwonek powiadomi nas kiedy kurier przyjedzie. Ten dzwonek to właśnie jest przerwanie.

**Jak to działa w kodzie?**
* Procesor wykonuje swój główny program (czyta książkę).
* Nagle na konkretnym pinie pojawia się sygnał (dzwoni dzwonek).
* Procesor natychmiast przerywa to, co robił i przeskakuje do specjalnej funkcji (idzie odebrać paczkę).
* Po załatwieniu sprawy wraca dokładnie do momentuw książke, w którym skończył.

**Dlaczego warto jej używać?**
* Błyskawiczna reakcja: Arduino nie musi czekać, aż skończy się `delay()` lub długa pętla, żeby zauważyć np. naciśnięcie przycisku awaryjnego.
* Oszczędzanie zasobów: Procesor może zajmować się obliczeniami, a nie ciągłym sprawdzaniem pinu.

**Uwaga:** Funkcja która wykonuje przerwanie, musi być bardzo krótka (zmienienie flagi lub stanu, a nie skomplikowne obliczenia) oraz nie może mieć w sobie `delay()` czy innych funkcji opóźnienia.

### Funkcja `attachInterupt()`
Aby uruchomić przerwanie w kodzie, używamy funkcji `attachInterrupt()`, która przyjmuje trzy prametry `attachInterrupt(digitalPinTpInterrupt(pin), funkcja_ISR, tryb`:
* digitalPinInterrupt(pin): Wskazuje pin, który ma "nasłuchiwać" (W Arduino Uno najczęściej piny 2 i 3).
* funkcja_ISR: Nazwa funkcji która Arduino ma wykonać natychmiast po wykryciu sygnału. Musi być krótka i nie może zawierać `delay()`.
* tryb: Określa, na jaki sygnał elektryczny reagujemy:
    * LOW - wywołanie przerwania zawsze, gdy na wejściu panuje stan niski.
    * CHANGE - wywołanie przy zmianie wartości na pinie (z wysokiego na niski i odwrotnie).
    * RISING - wywołanie, gdy następuje zmiana wartości ze stanu niskiego na wysoki.
    * FALLING - wywołanie, gdy następuje zmiana wartości ze stanu wysokiego na niski.

### Pliki w projekcie:
`09_przerwania.ino` - Kod programu
`schemat_przerwania.jpg` - Schemat połączeń (Fritzing)
`prezentacja_działania_przerwania.gif` - Prezentacja działania

### Schemat połączeń:
![Schemat projektu](schemat_przerwania.jpg)

### Prezentacja działania:
![Prezentacja działania](prezentacja_działania_przerwania.gif)
