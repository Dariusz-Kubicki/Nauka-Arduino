# Lekcja 9: Przerwania

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

### Pliki w projekcie:
`09_przerwania.ino` - Kod programu
`schemat_przerwania.jpg` - Schemat połączeń (Fritzing)
`prezentacja_działania_przerwania.gif` - Prezentacja działania

### Schemat połączeń:
![Schemat projektu](schemat_przerwania.jpg)

### Prezentacja działania:
![Prezentacja działania](prezentacja_działania_przerwania.gif)