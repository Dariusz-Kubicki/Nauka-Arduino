# Lekcja 12: Serwomechanizm cz. 1
Kontynuacja nauki podstaw Arduino z kursu **Forbot**. W tym projekcie napisałem podstawowy program sterujący płynnie serwomechanizmem od 0-100%, po czym serwo wraca szybko do 0%. 

### Czego się nauczyłem:
* Dowiedziałem się co to serwomechanizm i jak działa.
* Poznałem bibliotekę `Servo.h` i nauczyłem się z niej korzystać.
* poznałem komendy `.attach()` i `.write()`, które służą kolejno do przypisania pinu PWM dla serwomechanizmu oraz do ustawienia serwa na odpowiedią pozycję.

### Czym jest serwomechanizm?
Serwomechanizm modelarski to silnik prądu stałego z przkłakładnią oraz specjalnym układem sterowania, zamknięty w jednej obudowie. Serwa modelarskie są zazwyczaj niewielkich rozmiarów, mają trójprzewodowe połączenie (dwa przewody zasilające i jeden sterujący). Sterownik silnika wbudowany w serwo interpretuje sygnał PWM i doprowadza do tego, aby wał wyjściowy ustalił się we właściwym miejscu. Czujnikiem, który pozwala okreścić pozycję wału jest zwykły potencjometr. Póki co nie będę rozwijał się jaki konkretnie sygnał PWM musi być podawany na serwo bo za to odpowiada nam biblioteka `Servo.h`.
### Zasilanie serwomechanizmu
Serwo pobiera stosunkowo duży prąd rzędu 500-800mA lub więcej, standardowy port USB 2.0 dostarcza tylko 500mA,a 3.0 ok. 900mA przy czym część z tego zużywa samo Arduino. Dlatego przy zasilaniu serwa wymagane jest zasilanie zewnętrzne przez np. baterię 9V lub zasilacz 12V. Ja użyłem dodatkowo stabilizatora liniowego 7805, ale było można podpiąć serwo pod pin 5V w Arduino i wszystko powinno działać tak samo, lecz nie jest to najlepsze rozwiązanie ponieważ wtedy kożystamy z wbudowanego stabilizatora w Arduino który przy większym obciążeniem może się nagrzewać co drastycznie ogranicza dostęny prąd i może być niebezpieczne dla Arduino. Najbezpieczniejsze jest stosowanie zewnętrznego stabilizatora liniowego.

### Pliki w projekcie:
* `12_serwomechanizm_cz1.ino` - Kod programu
* `prezentacja_dzialania_serwomechanizm_cz1.gif` - Prezentacja działania
* `schemat_serwomechanizm.jpg` - Schemat połączeń (Fritzing)


### Prezentacja działania:
![GIF z działaniem](prezentacja_dzialania_serwomechanizm_cz1.gif)

### Schemat połączeń:
![Schemat projektu](schemat_serwomechanizm.jpg)
