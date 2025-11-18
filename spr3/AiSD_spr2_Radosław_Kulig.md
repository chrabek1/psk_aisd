# Politechnika Świętokrzyska w Kielcach
## Wydział Zarządzania i Modelowania Komputerowego
##### Algorytmy i struktury danych
##### Laboratorium
#### Struktury danych C++
![](https://tu.kielce.pl/wp-content/uploads/2018/03/logo_psk.jpg)
Przygotował: Radosław Kulig

Numer albumu: 093795

Kierunek: Inżynieria Danych

Studia: stacjonarne

Numer grupy: L02
***

## Porównanie czasu wykonania algorytmów sortujących na różnych zestawach danych wejściowych
Tablica i lista to podstawowe struktury danych służące do przechowywania zbioru elementów tego samego typu, jednak różnią się sposobem organizacji danych w pamięci oraz możliwościami operacyjnymi.

Tablica to struktura o stałej długości, w której elementy są rozmieszczone w pamięci w sposób ciągły. Dzięki temu dostęp do elementu o danym indeksie jest bardzo szybki (operacja w czasie stałym, `O(1)`), lecz modyfikacja rozmiaru tablicy lub wstawianie elementów w środku jest kosztowne, ponieważ wymaga przesunięcia pozostałych danych. Tablice są więc efektywne, gdy rozmiar zbioru jest znany i rzadko się zmienia.

Lista (np. `std::list` w C++ to struktura dynamiczna, w której każdy element (węzeł) przechowuje wartość oraz wskaźniki do sąsiednich elementów. Umożliwia to szybkie wstawianie i usuwanie danych w dowolnym miejscu (`O(1)` po uzyskaniu dostępu do elementu), ale utrudnia bezpośredni dostęp do konkretnego indeksu, ponieważ wymaga przeszukiwania listy od początku (`O(n)`).


### Implementacja metody bąbelkowej

```cpp
void bubleSort(long int n, int A[]) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
}
```

### Implementacja metody przez wstawianie

```cpp
void insertionSort(long int n, int A[]) {
	int key = 0, i = 0;
	for (int j = 1; j < n; j++) {
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}
```

### Implementacja metody przez wybór

```cpp
void replaceSort(long int n, int A[]) {
	int min = 0, k = 0;
	for (int i = 0; i < n-1 ; i++) {
		k=0;
		min = A[i];
		for (int j = i+1; j < n; j++) {
			if (min > A[j]) {
				min = A[j];
				k = j;
			}
		}
		if(k){
			min = A[i];//wykorzystuje min jako temp
			A[i] = A[k];
			A[k] = min;
		}
	}
}
```

### Implementacja metody Shell sort

```cpp
void shellsort(long int n, int* tab){
	int inner, outer, temp, h = 1;
	while (h <= n / 3)
		h = h * 3 + 1;
	while (h > 0) {

		for (outer = h; outer < n; outer++) {
			temp = tab[outer];
			inner = outer;
			while (inner > h - 1 && tab[inner - h] >= temp) {
				tab[inner] = tab[inner - h];
				inner = inner - h;
			}
			tab[inner] = temp;
		}
		h = (h - 1) / 3;
	}
}
```
### Implementacja metody Merge sort

```cpp
void Scalaj(int T[], long int p, long int mid, long int k) {
	int T2[N];
	long int p1 = p, k1 = mid;
	long int p2 = mid + 1, k2 = k;

	long int i = p1;

	while ((p1 <= k1) && (p2 <= k2)) {
		if (T[p1] < T[p2]) {
			T2[i] = T[p1];
			p1++;
		}
		else {
			T2[i] = T[p2];
			p2++;
		}
		i++;
	}
	while (p1 <= k1) {
		T2[i] = T[p1];
		p1++;
		i++;
	}
	while (p2 <= k2) {
		T2[i] = T[p2];
		p2++;
		i++;
	}
	for (i = p; i <= k; i++)
		T[i] = T2[i];
}
void MergeSort(int T[], long int p, long int k) {
	if (p < k) {
		long int mid = (p + k) / 2;
		MergeSort(T, p, mid);
		MergeSort(T, mid + 1, k);
		Scalaj(T, p, mid, k);
	}
}
```
### Implementacja metody Quick sort

```cpp
void qsort(int* tab, long int left, long int right) {
	if (left < right) {
		long int m = left;
		for (long int i = left + 1; i <= right; i++)
			if (tab[i] < tab[left])
				swap(tab[++m], tab[i]);
		swap(tab[left], tab[m]);
		qsort(tab, left, m - 1);
		qsort(tab, m + 1, right);
	}
}
```

### Generowanie tablicy danych i sprawdzanie poprawności sortowania

```cpp
void generuj_tablice(long int n, int T[]) {
	for (int i = 0; i < n; i++)
		T[i] = rand() % 1000;
}
bool sprawdz(long int n, int T[]) {
	for (int i = 1; i < n; i++) {
		if (T[i] < T[i - 1]) return false;
	}
	return true;
}
```
## Wyniki
dla n=10000  
| Sortowanie | Czas [s] |
| ------- | ------- | 
| Buble | 0.249 | 
| Insertion | 0.034 | 
| Replace | 0.063 | 
| Shell | 0.001 | 
| Merge | 0.001 | 
| Quick | 0.001 |   

n=100000
| Sortowanie | Czas [s] |
| ------- | ------- | 
| Buble | 24.887 | 
| Insertion | 3.476 | 
| Replace | 6.260 | 
| Shell | 0.027 | 
| Merge | 0.010 | 
| Quick | 0.013 | 

dla n=1000000

## Wnioski

Przeprowadzone eksperymenty potwierdzają, że wybór odpowiedniej struktury danych ma istotny wpływ na efektywność działania programu. Tablica, dzięki ciągłemu rozmieszczeniu elementów w pamięci, cechuje się najwyższą szybkością inicjalizacji i dostępu, co czyni ją najbardziej wydajną w operacjach o stałym rozmiarze danych. Lista, mimo większych kosztów czasowych inicjalizacji, zapewnia większą elastyczność przy dynamicznych modyfikacjach zawartości.

W przypadku algorytmu konwersji liczby na system o zadanej podstawie, wszystkie implementacje – oparte na stosie, liście i tablicy – zwracają identyczne wyniki, różniąc się jedynie organizacją pamięci i sposobem odczytu danych. Implementacja algorytmu tworzenia kolejek tanecznych natomiast ilustruje praktyczne wykorzystanie struktur dynamicznych, umożliwiających równoczesne zarządzanie wieloma zbiorami danych oraz ich cykliczne przetwarzanie w sposób uporządkowany i kontrolowany.

Wnioskiem końcowym jest to, że dobór struktury danych powinien być uzależniony od charakteru problemu — tablice są optymalne dla danych statycznych i dużych zbiorów o niezmiennym rozmiarze, natomiast listy i kolejki znajdują zastosowanie w zadaniach wymagających dynamicznego przydzielania, przesuwania lub rotacji elementów.
