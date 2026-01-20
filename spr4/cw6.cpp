#include <iostream>
#include <fstream>
using namespace std;

struct przedmiot
{
    string nazwa;
    int cena;
    int waga;
    int numer;
};

void czytaj_przedmioty(przedmiot tab[], int *n, int *p)
{
    ifstream plik;
    plik.open("p1.txt");
    plik >> *n >> *p;
    for (int i = 0; i < *n; i++)
    {
        plik >> tab[i].numer;
        plik >> tab[i].nazwa;
        plik >> tab[i].waga;
        plik >> tab[i].cena;
    }
    plik.close();
}
void wypisz_przedmioty(przedmiot tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i].numer << " " << tab[i].nazwa << " waga: " << tab[i].waga << " cena: " << tab[i].cena << endl;
    }
}
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
void sortuj_przedmioty3(przedmiot tab[], int n) // stosuje po stosunku cena/waga
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
            // s+=tab[i-1].cena;

            w -= tab[i - 1].waga;
            // cout<<p<<endl;
        }
    }
    return P[n][p];
}
int main()
{
    przedmiot przedmioty[10];
    int n = 0;
    int pojemnoscPlecaka = 0;
    czytaj_przedmioty(przedmioty, &n, &pojemnoscPlecaka);
    int dlugosci[10];
    int ceny[10];
    // czytaj_prety(dlugosci,ceny,&n,&pojemnoscPlecaka);
    // prety2przedmioty(przedmioty,dlugosci,ceny,n);
    cout << "Algorytm zachlanny: " << endl
         << plecak(przedmioty, n, pojemnoscPlecaka) << endl;
    cout << "Algorytm dynamiczny: " << endl
         << plecak_dynamiczny(przedmioty, n, pojemnoscPlecaka);
}