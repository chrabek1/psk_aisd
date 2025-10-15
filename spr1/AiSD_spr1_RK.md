# Politechnika Świętokrzyska w Kielcach
## Wydział Zarządzania i Modelowania Komputerowego
##### Algorytmy i struktury danych
##### Laboratorium
##### Algorytmy numeryczne

![](https://tu.kielce.pl/wp-content/uploads/2018/03/logo_psk.jpg)


Przygotował: Radosław Kulig

Kierunek: Inżynieria Danych

Studia: stacjonarne

Numer grupy: L02

***
## Wyznaczanie miejsca zerowego funkcji metodą bisekcji

Metoda bisekcji ( ang. bisection method ), zwana również metodą połowienia lub wyszukiwaniem binarnym pozwala stosunkowo szybko znaleźć pierwiastek dowolnej funkcji w zadanym przedziale poszukiwań `[a,b]`. Aby można było zastosować metodę bisekcji, funkcja musi spełniać kilka warunków początkowych:

- Funkcja musi być określona w przedziale `[a,b]`
- Funkcja musi być ciągła w przedziale `[a,b]`
- Na krańcach przedziału `[a,b]` funkcja musi mieć różne znaki

Rozwiązanie znajdowane jest za pomocą kolejnych przybliżeń. Z tego powodu należy określić dokładność, z którą chcemy otrzymać pierwiastek funkcji oraz dokładność wyznaczania samej funkcji.
W każdym przybliżeniu algorytm wyznacza środek `MID` przedziału `[XL,XR]` jako średnią arytmetyczną krańców. Następnie sprawdzane jest, czy różnica pomiędzy środkami z kolejnych iteracji jest mniejsza od założonej dokładności wyliczania pierwiastka. Jeśli tak, to algorytm kończy pracę z wynikiem w MID. 
W przeciwnym razie punkt `MID` dzieli przedział `[XL,XR]` na dwie równe połowy: `[XL,MID]` i `[MID,XR]`. Algorytm za nowy przedział `[XL,XR]` przyjmuję tę połówkę, w której funkcja zmienia znak na krańcach i kontynuuje wyznaczanie pierwiastka funkcji.

![](https://github.com/chrabek1/psk_aisd/blob/main/spr1/schemat_bisekcja.png?raw=true)
## Implementacja algorytmu bisekcji
```cpp

double vel(float c) {
	float g = 9.81, m = 68.1, t = 10;
	double result;
	result = g * m / c * (1 - exp(-(c / m) * t)) - 40;
	return result;

}
void bisekcja() {
	double XL = 12, XR = 16, e = 0.1;
	double TEMP = XL;
	double MID = (XL + XR) / 2;
	double epsilon = 1;
	cout << " | " << "XL" << " | " << "XR" << " | " << "MID" << " | " << "EPS" << " | " <<"\n";
	cout  << " | "  << XL << " | " << XR << " | " << MID << " | " << "---"  << " | " << "\n";
	while (epsilon > e) {
		
		TEMP = MID;
		if (vel(XL) * vel(MID) < 0) XR = MID; else XL = MID;
		MID = (XL + XR) / 2;
		epsilon = abs((MID - TEMP) / MID) * 100;
		cout  << " | "  << XL << " | " << XR << " | " << MID << " | " << epsilon  << " | " << "\n";
	} 
	cout << "Wynik algorytmy metody bisekcji: " << MID << "\n\n";
}

```

## Wyznaczanie miejsca zerowego funkcji metodą Newtona-Raphsona

Metoda Newtona-Raphsona, nazywana również metodą stycznych, jest jedną z najczęściej stosowanych metod numerycznych do wyznaczania miejsc zerowych funkcji. Polega ona na iteracyjnym przybliżaniu pierwiastka poprzez wykorzystanie wartości funkcji oraz jej pochodnej w danym punkcie. W każdym kroku obliczane jest nowe przybliżenie zgodnie ze wzorem:

![](https://github.com/chrabek1/psk_aisd/blob/main/spr1/newton_wzor.png?raw=true)


Założenia:

- W przedziale `[a,b]` znajduje się dokładnie jeden pierwiastek funkcji `f`.
- Funkcja ma różne znaki na krańcach przedziału, tj. `f(a) ⋅ f( b) < 0`.
- Pierwsza i druga pochodna funkcji mają stały znak w tym przedziale.

Metoda Newtona-Raphsona jest metodą o zbieżności kwadratowej – rząd zbieżności wynosi `2` (wyjątkiem są zera wielokrotne, dla których zbieżność jest liniowa i wynosi `1`), zaś współczynnik zbieżności `M/2m`. Oznacza to, iż przy spełnionych założeniach błąd maleje kwadratowo wraz z ilością iteracji. 

![](https://github.com/chrabek1/psk_aisd/blob/main/spr1/Methode_Newton.svg.png?raw=true)
## Implementacja algorytmu metody Newtona-Raphsona

```cpp
double f(double x) {
	return exp(-x) - x;
}
double f_der(double x) {
	return -exp(-x) - 1;
}
void newtonRaphson() {
	double e = 0.0001;
	double x = 10;
	double temp;
	double der = f_der(x);
	cout << " | " << "x" << " | " << "abs(f(x))"<< " | " << "\n";
	cout << " | " << x << " | " << abs(f(x)) << " | " << "\n";
	do {
		temp = x - f(x) / der;
		x = temp;
		der=f_der(x);
		cout << " | " << x << " | " << abs(f(x)) << " | " << "\n";
	} while (abs(f(x)) > e);
	cout << "Wynik algorytmu metody Newtona-Raphsona: " << x << "\n";
}
```

## Wyniki 
### Algorytm bisekcji
 | XL | XR | MID | EPS | 
 | ------ | ------ | ------ | ------ |
 | 12 | 16 | 14 | --- | 
 | 14 | 16 | 15 | 6.66667 | 
 | 14 | 15 | 14.5 | 3.44828 | 
 | 14.5 | 15 | 14.75 | 1.69492 | 
 | 14.75 | 15 | 14.875 | 0.840336 | 
 | 14.75 | 14.875 | 14.8125 | 0.421941 | 
 | 14.75 | 14.8125 | 14.7812 | 0.211416 | 
 | 14.7812 | 14.8125 | 14.7969 | 0.105597 | 
 | 14.7969 | 14.8125 | 14.8047 | 0.0527704 | 
 
##### Wynik algorytmy metody bisekcji: `14.8047`.
### Algorytm Newtona-Raphsona
 | x | \|f(x)\| | 
 | ------ | ------ |
 | 10 | 9.99995 | 
 | 0.000499377 | 0.999001 | 
 | 0.500125 | 0.10633 | 
 | 0.566314 | 0.00129962 | 
 | 0.567143 | 1.9501e-07 | 
##### Wynik algorytmu metody Newtona-Raphsona: `0.567143`.
&nbsp;
## Wykres
![](https://github.com/chrabek1/psk_aisd/blob/main/spr1/wykres.png?raw=true)

Wielkości wartości ε na wykresie powyżej są zależne od zadanych parametrów - przedziału `[XL,XL]` w metodzie bisekcji i wartości `x` w metodzie Newtona-Raphsona. Z punktu widzenia naszego ćwiczenia istotny jest jedynie kształt linii na wykresie, który odzwierciedla tempa zbieżności porównywanych metod.
## Wnioski

W przeprowadzonych ćwiczeniach zaimplementowano i porównano dwie metody numeryczne służące do wyznaczania miejsc zerowych funkcji: metodę bisekcji oraz metodę Newtona-Raphsona. Obie metody pozwalają skutecznie znaleźć przybliżone rozwiązanie równania nieliniowego, jednak różnią się zasadą działania, szybkością zbieżności oraz wymaganiami wobec funkcji.

Metoda bisekcji okazała się prosta w implementacji i bardzo stabilna, ponieważ zawsze prowadzi do rozwiązania, o ile funkcja spełnia warunki ciągłości i zmiany znaku na krańcach przedziału. Jej główną wadą jest stosunkowo wolna zbieżność liniowa(co widać na wykresie), co sprawia, że do osiągnięcia wysokiej dokładności wymagane jest wiele iteracji.

Z kolei metoda Newtona-Raphsona cechuje się zbieżnością kwadratową, co oznacza, że przy spełnionych założeniach (ciągłość funkcji oraz dostępność jej pochodnej) osiąga rozwiązanie znacznie szybciej(co widać na wykresie) niż metoda bisekcji. Wadą jest jednak to, że metoda może nie zbiegać, jeśli punkt startowy zostanie dobrany niewłaściwie lub jeśli funkcja nie spełnia warunków gładkości.
Podsumowując:

- Metoda bisekcji zapewnia pewność zbieżności, lecz jest wolniejsza.
- Metoda Newtona-Raphsona jest szybsza, ale wymaga znajomości funkcji pochodnej.
- W praktyce wybór metody zależy od charakteru funkcji oraz wymaganej dokładności obliczeń.
