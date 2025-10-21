# Politechnika Świętokrzyska w Kielcach
## Wydział Zarządzania i Modelowania Komputerowego
##### Algorytmy i struktury danych
##### Laboratorium
##### Struktury danych C++
![](https://tu.kielce.pl/wp-content/uploads/2018/03/logo_psk.jpg)
Przygotował: Radosław Kulig

Numer albumu: 093795

Kierunek: Inżynieria Danych

Studia: stacjonarne

Numer grupy: L02
***

## Porównanie efektywności czasowych algorytmów inicjalizacji dla struktur typu: tablica i lista.

Tablica i lista to podstawowe struktury danych służące do przechowywania zbioru elementów tego samego typu, jednak różnią się sposobem organizacji danych w pamięci oraz możliwościami operacyjnymi.

Tablica to struktura o stałej długości, w której elementy są rozmieszczone w pamięci w sposób ciągły. Dzięki temu dostęp do elementu o danym indeksie jest bardzo szybki (operacja w czasie stałym, `O(1)`), lecz modyfikacja rozmiaru tablicy lub wstawianie elementów w środku jest kosztowne, ponieważ wymaga przesunięcia pozostałych danych. Tablice są więc efektywne, gdy rozmiar zbioru jest znany i rzadko się zmienia.

Lista (np. `std::list` w C++ to struktura dynamiczna, w której każdy element (węzeł) przechowuje wartość oraz wskaźniki do sąsiednich elementów. Umożliwia to szybkie wstawianie i usuwanie danych w dowolnym miejscu (`O(1)` po uzyskaniu dostępu do elementu), ale utrudnia bezpośredni dostęp do konkretnego indeksu, ponieważ wymaga przeszukiwania listy od początku (`O(n)`).


### Implementacja algorytmu inicjalizacji tablicy

```cpp
const long n=999999;
void tab_init() {
    clock_t start,end;
    double time_taken;
    start=clock();
    int tab[n];
    for(int i=0;i<n;i++){
        tab[i]=i;
    }
    end=clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Czas inicjalizacji " << n <<  "-elementowej tablicy: " << fixed << time_taken << setprecision(3) << " sekund" << endl;
}
```

### Implementacja algorytmu inicjalizacji listy

```cpp
const long n=999999;
void list_init() {
    clock_t start,end;
    double time_taken;
    start = clock();
    list<int> l;
    for(int i=0;i<n;i++) {
        l.push_back(i);
    }
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Czas inicjalizacji " << n <<  "-elementowej listy: " << fixed << time_taken << setprecision(3) << " sekund" << endl;
}
```
### Wyniki
|Rozmiar | Tablica | Lista |
| ------ | ------ | ------ | 
| 999999 | 1.389 ms | 63 ms |
| 99999 | 0.215 ms | 7 ms |
| 9999 | 0.011 ms | 1 ms |

Inicjalizacja tablicy zajmuje około 50 krotnie mnniej czasu od inicjalizacji listy o tym samym rozmiarze.

## Implementacja algorytmu wyznaczenia reprezentacji liczby w systemie liczbowym o zadanej podstawie

Implementacja algorytmu wyznaczania reprezentacji liczby w systemie o zadanej podstawie polega na iteracyjnym dzieleniu liczby przez tę podstawę i zapisywaniu reszt z kolejnych operacji. Otrzymane reszty odpowiadają kolejnym cyfrom liczby w nowym systemie, od najmniej znaczącej do najbardziej znaczącej. Po odwróceniu kolejności reszt uzyskuje się pełną reprezentację liczby w żądanym systemie liczbowym.

### Z użyciem struktury stosu
```cpp
void podstawa_stos(int n,int  b) {
    stack<int> stos;
    stack<int> stos2;
    while(n!=0) {
        stos.push(n%b);
        n=n/b;
    } 
    while(!stos.empty()) {
        cout<<stos.top()<<"-";
        stos.pop();
    }
}
```
### Z użyciem struktury listy
```cpp
void podstawa_lista(int n, int b) {
    list<int> lista;
    while(n!=0) {
        lista.push_back(n%b);
        n=n/b;
    } 
    while(!lista.empty()) {
        cout<<lista.back()<<"-";
        lista.pop_back();
    }
}
```
### Z użyciem struktury tablicy
```cpp
void podstawa_tablica(int n, int b) {
    int tab[10];
    int i=-1;
    while(n!=0) {
        i++;
        tab[i]=n%b;
        n=n/b;
    } 
    for(;i>=0;i--) {
        cout<<tab[i]<<"-";
    }
}
```
### Wyniki działania algorytmów

- dla `n=100`, `b=8`
  - stos: 1-4-4-
  - lista: 1-4-4-
  - tablica: 1-4-4-
- dla `n=50`, `b=3`
  - stos: 1-2-1-2-
  - lista: 1-2-1-2-
  - tablica: 1-2-1-2-

- dla `n=128`, `b=2`
  - stos: 1-0-0-0-0-0-0-0-
  - lista: 1-0-0-0-0-0-0-0-
  - tablica: 1-0-0-0-0-0-0-0-

## Implementacja algorytmu tworzącego kolejki osób z podziałem na płeć
Program realizuje zadanie tworzenia par tanecznych na podstawie danych odczytanych z pliku tekstowego. Wczytane osoby są rozdzielane do dwóch kolejek według płci – osobno dla mężczyzn i kobiet. Następnie algorytm w iteracyjnym procesie dobiera po jednej osobie z każdej kolejki, tworząc pary i umieszczając je w kolejce par znajdujących się aktualnie na parkiecie. W przypadku, gdy na parkiecie znajduje się maksymalna liczba czterech par, najstarsza para schodzi, a jej uczestnicy ponownie trafiają do odpowiednich kolejek. Program w sposób sekwencyjny wypisuje komunikaty o wchodzących i schodzących parach, ilustrując dynamiczne zarządzanie kolejkami uczestników tańca.

```cpp
void taniec(int k=5) {
    string line;
    queue<string> panowie;
    queue<string> panie;
    queue<array<string, 2>> pary;
    fstream file("dane.txt");
    while(getline (file,line)) {
        if(line[0] == 'M') {
            panowie.push(line);
        }
        else panie.push(line);
    }
    while(k>0) {
        if(pary.size()>=4) {
            cout <<"Schodzi para: " << pary.front()[0] << " i " << pary.front()[1] << "\n";
            panowie.push(pary.front()[0]);
            panie.push(pary.front()[1]);
            pary.pop();
            k--;
        }
        if(!panowie.empty() && !panie.empty()) {
            pary.push({panowie.front(), panie.front()});
            cout <<"Wchodzi para: " << pary.back()[0] << " i " << pary.back()[1] << "\n";
            panowie.pop();
            panie.pop();
        }
        cout<< "\n";
    }
}
```
### Wynik działania algorytmu dla 5 zmian

```
Wchodzi para: M Frank Opitz i F Jennifer Ingram

Wchodzi para: M Terrill Beckerman i F Beata Lovelace

Wchodzi para: M Mike Dahly i F Shirley Yaw

Wchodzi para: M Raymond Williams i F Bernica Tackett

Schodzi para: M Frank Opitz i F Jennifer Ingram
Wchodzi para: M Don Gundolf i F Nikki Feldman

Schodzi para: M Terrill Beckerman i F Beata Lovelace
Wchodzi para: M David Durr i F Jennifer Ingram

Schodzi para: M Mike Dahly i F Shirley Yaw
Wchodzi para: M Mike McMillan i F Beata Lovelace

Schodzi para: M Raymond Williams i F Bernica Tackett
Wchodzi para: M Frank Opitz i F Shirley Yaw

Schodzi para: M Don Gundolf i F Nikki Feldman
Wchodzi para: M Terrill Beckerman i F Bernica Tackett
```

## Wnioski

Przeprowadzone eksperymenty potwierdzają, że wybór odpowiedniej struktury danych ma istotny wpływ na efektywność działania programu. Tablica, dzięki ciągłemu rozmieszczeniu elementów w pamięci, cechuje się najwyższą szybkością inicjalizacji i dostępu, co czyni ją najbardziej wydajną w operacjach o stałym rozmiarze danych. Lista, mimo większych kosztów czasowych inicjalizacji, zapewnia większą elastyczność przy dynamicznych modyfikacjach zawartości.

W przypadku algorytmu konwersji liczby na system o zadanej podstawie, wszystkie implementacje – oparte na stosie, liście i tablicy – zwracają identyczne wyniki, różniąc się jedynie organizacją pamięci i sposobem odczytu danych. Implementacja algorytmu tworzenia kolejek tanecznych natomiast ilustruje praktyczne wykorzystanie struktur dynamicznych, umożliwiających równoczesne zarządzanie wieloma zbiorami danych oraz ich cykliczne przetwarzanie w sposób uporządkowany i kontrolowany.

Wnioskiem końcowym jest to, że dobór struktury danych powinien być uzależniony od charakteru problemu — tablice są optymalne dla danych statycznych i dużych zbiorów o niezmiennym rozmiarze, natomiast listy i kolejki znajdują zastosowanie w zadaniach wymagających dynamicznego przydzielania, przesuwania lub rotacji elementów.
