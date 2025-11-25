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
Dominik Wójcik


Kierunek: Inżynieria Danych

Studia: stacjonarne

***

## Wstęp teoretyczny

Celem niniejszego sprawozdania jest przedstawienie metody rozwiązywania układów równań liniowych przy użyciu metody eliminacji Gaussa. Metoda ta stanowi jedno z podstawowych narzędzi algebry liuniowej i numerycznej umożliwioające przekształcenie układu równań do postaci trójkątnej, co pozwala na łatwe wyznaczenie niewiadomych za pomocą podstawiania wstecznego.

W sprawozdaniuz zaprezentowano szczegółowy przebieg obliczeń dla układu trzech równań z trzema niewiadomymi. Każdy etap został opisany krok po kroku, z wyszczególnieniem operacji elementarnych wykonywanycg na wierszach macierzy. Celem opracowania jest nie tylko uzyskania poprawnego rozwiązania, ale również zrozumienie idei metody eliminacji Gaussa oraz jej zastosowania w praktycznych problemach obliczeniowych.


### Dany układ równań liniowych

$x_1 + 2x_2 + 3x_3 = 1$  
$2x_1 + x_2 + 3x_3 = 2$  
$3x_1 + 2x_2 +  x_3 = 0$

#### Postać macierzy rozszerzonej
```
1  2  3 | 1  
2  1  3 | 2  
3  2  1 | 0
```

### Rozwiązanie

#### Krok 1
Sprowadzamy macierz do postaci górno-trójkątnej.
W celu tym eliminujemy zmienną $x_1$ z drugiego i trzeciego wiersza, czyli od drugiego i trzeciego wiersza odejmujemy odpowiednie wielokrotności wiersza pierwszego.  

$d_{21}=\frac{a_{21}}{a_{11}}=2$  

$d_{31}=\frac{a_{31}}{a_{11}}=3$  

$`R2 - 2 R1 → R2`$

$`R3 - 3 R1 → R3`$

##### otrzymana macierz
```
1	 2	 3 |  1
0	-3	-3 |  0
0	-4	-8 | -3
```
#### Krok 2
Eliminujemy zmienną $x_2$ z trzeciego wiersza.  

$d_{32}=\frac{a_{32}}{a_{22}}=\frac{4}{3}$  

$`R3  -\frac{4}{3} R2 → R3`$
##### otrzymana macierz
```
1	 2   3 |  1
0	-3	-3 |  0
0	 0	-4 | -3
```
Otrzymana macierz ma już postać górno-trójkątną.
#### Krok 3
Wyznaczamy rozwiązanie metodą podstawień wstecznych.  

Z trzeciego wiersza wyznaczamy $x_3$  

$$  
-4x_3=-3 ⇒ x_3=\frac{3}{4}  
$$  

Z drugiego wiersza wyznaczamy $x_2$  

$$  
-3x_2-3x_3=0 ⇒ -3x_2-3⋅\frac{3}{4}=0 ⇒ x_2=-\frac{3}{4}  
$$  

Z pierwszego wiersza wyznaczamy $x_1$  

$$
x_1+2x_2+3x_3=1 ⇒ x1+2⋅-\frac{3}{4}+3⋅\frac{3}{4}=1 ⇒ x_1=\frac{1}{4}  
$$

#### Sprawdzenie przez podstawienie
$$
\begin{aligned}
\frac{1}{4} + 2⋅(-\frac{3}{4})+3⋅\frac{3}{4}=1  \\
2⋅\frac{1}{4}+(-\frac{3}{4})+3⋅\frac{3}{4}=2  \\
3⋅\frac{1}{4}+2⋅(-\frac{3}{4})+\frac{3}{4}=0  \\
\end{aligned}
$$
### Rozwiązanie
$$
\begin{aligned}
x_1 = \frac{1}{4} \\
 x_2 = -\frac{3}{4} \\
x_3 = \frac{3}{4} \\
\end{aligned}
$$
## Wnioski

Przeprowadzone obliczenia potwierdziły skuteczność metody eliminacji Gaussa w rozwiązywaniu układów równań liniowych. Dzięki systematycznemu stosowaniu operacji elementarnych na wierszach macierzy możliwe było sprowadzenie układu do postaci trójkątnej górnej, a anastępnie wyznaczenie wartości niewiadomych poprzez podstawianie wsteczne.

Uzyskane rozwiązanie spełnia wszystkie równania pierwotnego układu, co świadczy o poprawności przeprowadzonych przekształceń. Metoda ta, mimo swojej prostoty, jest podstawą wielu algorytmów obliczeniowych stosowanych w naukach technicznych, fizyce i informatyce,a jej zrozumienie stanowi istotny element wiedzy z zakresu algebry liniowej.
