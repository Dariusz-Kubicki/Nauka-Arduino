# Lekjca 10: Przerwania cz. 2
Kontynuacja przerwań z kursu **Arduino cz. 2** od **Forbot**. Na podstawie projektu z poprzedniej lekcji zrobiłem nowy który delikatnie poszerza temat.

### Czego się nauczyłem:
* Poznałem przedrostek `volatile` i dowiedziałem się jak go stosować.
* wykorzystałem poprzedni projekt do przedstawienia zastosowania przedrostka `volatile`.

### `volatile` - Czym tak właściwie to jest?\
Podczas pracy z przerwaniami w Arduino prendzej czy później będzie trzeba skorzystać z przedrostka `volatile` przed zdeklarowaną zmienną. Jest on niezbędny aby program działał stabilnie i przewidywalnie.

### Jaki problem rozwiązuje `volatile`
