# Politechnika Świętokrzyska w Kielcach
## Wydział Zarządzania i Modelowania Komputerowego
##### Algorytmy i struktury danych
##### Laboratorium
##### Algorytmy zachłanne i dynamiczne
![](https://tu.kielce.pl/wp-content/uploads/2018/03/logo_psk.jpg)
Przygotował: Radosław Kulig  

Numer albumu: 093795  

Kierunek: Inżynieria Danych  

Studia: stacjonarne  

Numer grupy: L02  
***

## Wstęp teoretyczny  

### Algorytmy zachłanne  

Algorytmy zachłanne (ang. greedy algorithms) są klasą algorytmów, które w każdym kroku podejmują lokalnie najlepszą decyzję, mając nadzieję na uzyskanie rozwiązania globalnie optymalnego. Charakteryzują się one prostą implementacją oraz niewielką złożonością obliczeniową, co czyni je atrakcyjnymi w zastosowaniach praktycznych. Decyzje podejmowane przez algorytm zachłanny są nieodwracalne i nie uwzględniają przyszłych konsekwencji, co odróżnia je od metod dynamicznych.  

Algorytmy zachłanne dają rozwiązania optymalne tylko dla problemów spełniających określone własności, takie jak własność optymalnej podstruktury oraz własność wyboru zachłannego. W przypadku problemów, które nie spełniają tych warunków, algorytmy zachłanne stanowią heurystykę – rozwiązanie szybkie, lecz niekoniecznie optymalne. Przykładem takiego problemu jest klasyczny problem plecakowy, w którym algorytmy zachłanne nie gwarantują znalezienia rozwiązania optymalnego.  

Ze względu na swoją prostotę i efektywność, algorytmy zachłanne są często stosowane do rozwiązywania problemów decyzyjnych lub jako przybliżenie rozwiązań optymalnych w problemach optymalizacyjnych. W niniejszym sprawozdaniu przedstawiono i przeanalizowano działanie algorytmów zachłannych na przykładzie problemu plecakowego oraz porównano ich skuteczność z innymi metodami rozwiązywania tego problemu.  

### Algorytmy dynamiczne  

Programowanie dynamiczne jest techniką algorytmiczną polegającą na rozwiązywaniu problemów poprzez podział na mniejsze, powtarzające się podproblemy oraz zapamiętywanie ich wyników w celu uniknięcia wielokrotnych obliczeń. Metoda ta opiera się na dwóch kluczowych własnościach: optymalnej podstrukturze, która umożliwia złożenie rozwiązania problemu z rozwiązań podproblemów, oraz zachodzeniu podproblemów, polegającym na ich wielokrotnym występowaniu w trakcie obliczeń.  

Algorytmy dynamiczne mogą być realizowane w podejściu bottom-up lub top-down z memoizacją i są szczególnie skuteczne w rozwiązywaniu problemów optymalizacyjnych, takich jak problem plecakowy czy problem cięcia pręta. W przeciwieństwie do algorytmów zachłannych, gwarantują one znalezienie rozwiązania optymalnego, jednak kosztem większej złożoności obliczeniowej i zapotrzebowania na pamięć.  

## Implementacja algorytmu zachłannego do rozwiązania problemu plecakowego  

```cpp
struct przedmiot
{
    string nazwa;
    int cena;
    int waga;
    int numer;
};

int plecak(przedmiot tab[], int n, int pojemnosc, int m = 3)
{
    if (m == 3)
        sortuj_przedmioty3(tab, n);
    else if (m == 2)
        sortuj_przedmioty2(tab, n);
    else if (m == 1)
        sortuj_przedmioty1(tab, n);
    else
    {
        cout << "Podaj poprawną metode sortowania: 1 | 2 | 3";
        return 0;
    }
    // wypisz_przedmioty(tab,n);
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        if (pojemnosc >= tab[i].waga)
        {
            pojemnosc -= tab[i].waga;
            suma += tab[i].cena;
            cout << "Dodaje " << tab[i].nazwa << " do plecaka." << endl;
        }
        if (pojemnosc <= 0)
            break;
    }
    return suma;
}
```

Strategie działania algorytmu zależą od wybranej metody sortowania, względem ceny, wagi, lub stosunku ceny do wagi.  

```cpp
void sortuj_przedmioty1(przedmiot tab[], int n) // sortuje po cenie
{
    for (int i = 1; i < n; i++)
    {
        przedmiot temp;
        if (tab[i].cena > tab[i - 1].cena)
        {
            temp = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = temp;
            if (i > 1)
                i -= 2;
        }
    }
}
void sortuj_przedmioty2(przedmiot tab[], int n) // sortuje po wadze
{
    for (int i = 1; i < n; i++)
    {
        przedmiot temp;
        if (tab[i].waga < tab[i - 1].waga)
        {
            temp = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = temp;
            if (i > 1)
                i -= 2;
        }
    }
}
void sortuj_przedmioty3(przedmiot tab[], int n) // sortuje po stosunku cena/waga
{
    for (int i = 1; i < n; i++)
    {
        przedmiot temp;
        if ((tab[i].cena / (float)tab[i].waga) > (tab[i - 1].cena / (float)tab[i - 1].waga))
        {
            temp = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = temp;
            if (i > 1)
                i -= 2;
        }
    }
}
```

## Implementacja algorytmu zachłannego do rozwiązania problemu rozcinania pręta  

Aby zastosować algorytm zachłanny dostosowuje reprezentacja danych do problemu rozcinania pręta.  
```cpp
void czytaj_prety(int dlugosci[], int ceny[], int *n, int *p)
{
    ifstream plik;
    plik.open("prety.txt");
    plik >> *n >> *p;
    for (int i = 0; i < *n; i++)
    {
        plik >> dlugosci[i];
        plik >> ceny[i];
    }
    plik.close();
}
void prety2przedmioty(przedmiot tab[], int dlugosci[], int ceny[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i].numer = dlugosci[i];
        tab[i].nazwa = "dl:" + to_string(dlugosci[i]);
        tab[i].waga = dlugosci[i];
        tab[i].cena = ceny[i];
    }
}
```
## Implementacja algorytmu dynamicznego  

```cpp
int plecak_dynamiczny(przedmiot tab[], int n, int p)
{
    int P[n + 1][p + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= p; j++)
            P[i][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < p + 1; j++)
        {
            if (tab[i - 1].waga > j)
                P[i][j] = P[i - 1][j];
            else
                P[i][j] = P[i - 1][j] > tab[i - 1].cena + P[i - 1][j - tab[i - 1].waga] ? P[i - 1][j] : tab[i - 1].cena + P[i - 1][j - tab[i - 1].waga];
        }
    }
    int w = p;
    for (int i = n; i > 0; i--)
    {
        if (P[i][w] != P[i - 1][w])
        {
            cout << "Dodaje " << tab[i - 1].nazwa << " do plecaka." << endl;
            w -= tab[i - 1].waga;
        }
    }
    return P[n][p];
}
```
### Wyniki  

#### Dla zestawu danych 1:  

| id | nazwa    | waga | cena |
|----|----------|------|------|
| 1  | gitara   | 16   | 500  |
| 2  | PS3      | 7    | 800  |
| 3  | PSVita   | 2    | 200  |
| 4  | telefon  | 1    | 500  |
| 5  | laptop   | 8    | 900  |
| 6  | parasol  | 2    | 100  |
| 7  | trampki  | 4    | 100  |
| 8  | wino     | 2    | 100  |  

Pojemność plecaka: 15  

| algorytm            | strategia sortowania       | dodane przedmioty                                   | wartość plecaka |
|---------------------|----------------------------|-----------------------------------------------------|-----------------|
| zachłanny           | po cenie                   | laptop, PS3                                         | 1700            |
| zachłanny           | po wadze                   | telefon, PSVita, parasol, wino, trampki             | 1000            |
| zachłanny           | po stosunku cena/waga      | telefon, PS3, PSVita, parasol, wino                 | 1700            |
| dynamiczny          | —                          | wino, parasol, PSVita, laptop, telefon              | 1800            |


#### Dla zestawu danych 2:  

| id | nazwa   | waga | cena |
|----|---------|------|------|
| 1  | Koszula | 7    | 75   |
| 2  | Spodnie | 8    | 150  |
| 3  | Sweter  | 6    | 250  |
| 4  | Czapka  | 4    | 35   |
| 5  | Majtki  | 3    | 10   |
| 6  | Obuwie  | 9    | 100  |  
  
Pojemność plecaka: 10  
  
| algorytm            | strategia sortowania        | dodane przedmioty           | wartość plecaka |
|---------------------|-----------------------------|-----------------------------|-----------------|
| zachłanny           | po cenie                    | Sweter, Czapka              | 285             |
| zachłanny           | po wadze                    | Majtki, Czapka              | 45              |
| zachłanny           | po stosunku cena/waga       | Sweter, Czapka              | 285             |
| dynamiczny          | —                           | Czapka, Sweter              | 285             |




#### Dla problemu rozcinania pręta:    

Dane:  
| długość | cena |
|---------|------|
| 1       | 1    |
| 2       | 5    |
| 3       | 8    |
| 4       | 9    |
| 5       | 10   |
| 6       | 17   |
| 7       | 17   |
| 8       | 20   |
| 9       | 22   |
| 10      | 24   |  

Pojemnosc plecaka: 20  

| algorytm            | strategia sortowania       | dodane długości do plecaka      | wartość plecaka |
|---------------------|----------------------------|----------------------------------|-----------------|
| zachłanny           | po cenie                   | 10, 9, 1                         | 47              |
| zachłanny           | po wadze                   | 1, 2, 3, 4, 5                    | 33              |
| zachłanny           | po stosunku cena/waga      | 6, 3, 2, 8, 1                    | 51              |
| dynamiczny          | —                          | 9, 2, 3, 6                       | 52              |


## Rozwiązanie ploblemu plecakowego za pomocą funkcji solver programu Excel  

![excel](https://github.com/chrabek1/psk_aisd/blob/main/spr4/excel.png?raw=true)  
![solver](https://github.com/chrabek1/psk_aisd/blob/main/spr4/solver.png?raw=true)  

## Wnioski

Na podstawie przeprowadzonych eksperymentów można stwierdzić, że algorytmy zachłanne cechują się prostą implementacją oraz niewielką złożonością obliczeniową, jednak ich skuteczność w dużym stopniu zależy od przyjętej strategii wyboru elementów. Spośród analizowanych metod sortowania jedynie strategia oparta na stosunku cena/waga daje wyniki zbliżone do rozwiązania optymalnego, podczas gdy sortowanie wyłącznie po cenie lub po wadze często prowadzi do rozwiązań wyraźnie gorszych.  

Uzyskane wyniki potwierdzają tę obserwację. Dla pierwszego zestawu danych algorytmy zachłanne osiągnęły maksymalnie wartość 1700, podczas gdy algorytm dynamiczny wyznaczył rozwiązanie optymalne o wartości 1800. W drugim zestawie danych strategia cena/waga dała wynik zgodny z optimum, natomiast sortowanie po wadze okazało się najmniej efektywne. W problemie rozcinania pręta algorytm zachłanny oparty na stosunku cena/waga uzyskał wartość 51, bardzo zbliżoną do rozwiązania optymalnego wynoszącego 52.  

Algorytm dynamiczny w każdym z analizowanych przypadków zagwarantował znalezienie rozwiązania optymalnego, kosztem większego zapotrzebowania na pamięć i czasu obliczeń. Takie samo rozwiązanie optymalne zostało również uzyskane przy użyciu dodatku Solver programu Excel, który pozwolił sformułować problem plecakowy jako zadanie optymalizacji liniowej. Zastosowanie Solvera potwierdziło poprawność wyników otrzymanych metodą programowania dynamicznego.  

Podsumowując, algorytmy zachłanne mogą być stosowane jako szybkie metody przybliżone, jednak tylko strategia cena/waga ma praktyczne uzasadnienie. W zadaniach wymagających gwarancji optymalności najlepszym wyborem pozostają algorytmy dynamiczne lub narzędzia optymalizacyjne, takie jak Solver, które zapewniają poprawność rozwiązania.  


