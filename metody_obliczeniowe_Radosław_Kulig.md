# Politechnika Świętokrzyska w Kielcach
## Wydział Zarządzania i Modelowania Komputerowego
##### Metody Obliczeniowe
##### Ćwiczenia
#### Metoda eliminacji Gaussa
![](https://tu.kielce.pl/wp-content/uploads/2018/03/logo_psk.jpg)
Przygotował: 
Radosław Kulig
Łukasz Siudak
Jakub Piskulak
Natalia Starzyk
Maciej Krawczyk
Piotr Łukawski


Kierunek: Inżynieria Danych

Studia: stacjonarne

***

## Wstęp teoretyczny

Celem niniejszego sprawozdania jest przedstawienie metody rozwiązywania układów równań liniowych przy użyciu metody eliminacji Gaussa. Metoda ta stanowi jedno z podstawowych narzędzi algebry liuniowej i numerycznej umożliwioające przekształcenie układu równań do postaci trójkątnej, co pozwala na łatwe wyznaczenie niewiadomych za pomocą podstawiania wstecznego.

W sprawozdaniuz zaprezentowano szczegółowy przebieg obliczeń dla układu trzech równań z trzema niewiadomymi. Każdy etap został opisany krok po kroku, z wyszczególnieniem operacji elementarnych wykonywanycg na wierszach macierzy. Celem opracowania jest nie tylko uzyskania poprawnego rozwiązania, ale również zrozumienie idei metody eliminacji Gaussa oraz jej zastosowania w praktycznych problemach obliczeniowych.


### dana macierz

```
 x1 + 2x2 + 3x3 = 1
2x1 +  x2 + 3x3 = 2
3x1 + 2x2 +  x3 = 0
```

### Rozwiązanie

#### Krok 1
R2 - 2 R1 → R2 (multiply 1 row by 2 and subtract it from 2 row); R3 - 3 R1 → R3 (multiply 1 row by 3 and subtract it from 3 row)

```
1	2	3	1
0	-3	-3	0
0	-4	-8	-3
```
#### Krok 2
R2 / -3 → R2 (divide the 2 row by -3)
```
1	2	3	1
0	1	1	0
0	-4	-8	-3
```
#### Krok 3
R1 - 2 R2 → R1 (multiply 2 row by 2 and subtract it from 1 row); R3 + 4 R2 → R3 (multiply 2 row by 4 and add it to 3 row)
```
1	0	1	1
0	1	1	0
0	0	-4	-3
```
#### Krok 4

R3 / -4 → R3 (divide the 3 row by -4)
```
1	0	1	1
0	1	1	0
0	0	1	0.75
```
#### Krok 5

R1 - 1 R3 → R1 (multiply 3 row by 1 and subtract it from 1 row); R2 - 1 R3 → R2 (multiply 3 row by 1 and subtract it from 2 row)
```
1	0	0	0.25
0	1	0	-0.75
0	0	1	0.75
```
#### Podstawienie wsteczne
```
 0.25 + 2·(-0.75) + 3·0.75 = 0.25 - 1.5 + 2.25 = 1
2·0.25 + (-0.75) + 3·0.75 = 0.5 - 0.75 + 2.25 = 2
3·0.25 + 2·(-0.75) + 0.75 = 0.75 - 1.5 + 0.75 = 0
```
### Rozwiązanie
```
x1 = 0.25
x2 = -0.75
x3 = 0.75
```
## Wnioski

Przeprowadzone obliczenia potwierdziły skuteczność metody eliminacji Gaussa w rozwiązywaniu układów równań liniowych. Dzięki systematycznemu stosowaniu operacji elementarnych na wierszach macierzy możliwe było sprowadzenie układu do postaci trójkątnej górnej, a anastępnie wyznaczenie wartości niewiadomych poprzez podstawianie wsteczne.

Uzyskane rozwiązanie spełnia wszystkie równania pierwotnego układu, co świadczy o poprawności przeprowadzonych przekształceń. Metoda ta, mimo swojej prostoty, jest podstawą wielu algorytmów obliczeniowych stosowanych w naukach technicznych, fizyce i informatyce,a jej zrozumienie stanowi istotny element wiedzy z zakresu algebry liniowej.
