# Punkty brzegowe i wewnętrzne
Prosta próbka kodu. Bez historii w git.
## Opis
Dany jest zbiór n punktów na płaszczyźnie określony przy pomocy tablicy P z permutacją liczb z zakresu 1..n.
Punkty mają współrzędne (i, P[i-1]) dla i = 1, ..., n (obydwie współrzędne są zatem z zakresu 1..n).
Każdy punkt p = (x,y) płaszczyzny wyznacza 4 kwadranty: sw(p), nw(p), ne(p), se(p) odpowiadające sektorom wg róży wiatrów (SW: sektor południowo zachodni, ..., SE: południowo wschodni).
Punkty w sektorach spełniają odpowiednie ostre nierówności względem punktu p; np. punkty q w sektorze nw(p) spełniają warunek: q.x<p.x && q.y>p.y.
## Zasady działania
- Punkt p zbioru P nazywamy wewnętrznym, jeżeli w każdym sektorze sw(p), nw(p), ne(p), se(p) znajduje się przynajmniej jeden punkt; w przeciwnym przypadku punkt p nazywamy brzegowym. Program klasyfikuje punkty zbioru P na te dwie kategorie.
- Tablica P (permutacja 1..n) jest generowana losowo albo wprowadzana z klawiatury.
- Program prezentuje konfigurację punktów pseudograficznie zaznaczając odpowiednio punkty brzegowe ('B') i wewnętrzne ('W').
- W jednej aktywacji można zbadać dowolną liczbę instancji problemu; n<=0 lub n>MAX_N kończy program.
