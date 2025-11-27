#include <iostream>
#include <iterator>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

const long int N = 500000;

void generuj_tablice(long int n, int T[]) {
	for (int i = 0; i < n; i++)
		T[i] = rand() % 1000;
}
long int sprawdz(long int n, int T[]) {
	long int licznik = 0;
	/*for (int i = 0; i < n-1; i++) {
		for(int j=i+1; j<n; j++)
			if (T[j] < T[i]) licznik++;
	}*/
	return licznik;
}
void drukuj_tablice(int n, int A[]) {
	for (int i = 0; i < n; i++) cout << A[i] << "\t";
}

void bubleSort(long int n, int A[]) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				//cout << A[j] << " " << A[j - 1] << endl;
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
}
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
void shellsort(long int n, int* tab){
	long int inner, outer, temp, h = 1;
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
//MergeSort
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
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
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
int main() {
	int T[N] = {};
	int Twzor[N] = {};
	generuj_tablice(N, Twzor);
	cout<< "\nWskaznik inwersji: "<<(float)sprawdz(N, Twzor)/((N*(N-1))/2)<<endl;
	cout<<"| Sortowanie | Czas [s] |\n| ------- | ------- | \n";
	clock_t start, end;
	double time_taken;

	copy(Twzor, Twzor+N, T);
	start = clock();
	bubleSort(N, T);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if (!sprawdz(N, T))	cout << "| Buble | " << setprecision(3) << fixed << time_taken <<" | \n";
	else cout << "Buble: Tablica nieposortowana" << endl;

	copy(Twzor, Twzor+N, T);
	start = clock();
	insertionSort(N, T);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if (!sprawdz(N, T))	cout << "| Insertion | " << setprecision(3) << fixed << time_taken <<" | \n";
	else cout << "Insertion: Tablica nieposortowana" << endl;

	copy(Twzor, Twzor+N, T);
	start = clock();
	replaceSort(N, T);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if (!sprawdz(N, T))	cout << "| Replace | " << setprecision(3) << fixed << time_taken <<" | \n";
	else cout << "Replace: Tablica nieposortowana" << endl;

	copy(Twzor, Twzor+N, T);
	start = clock();
	shellsort(N, T);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if (!sprawdz(N, T))	cout << "| Shell | " << setprecision(3) << fixed << time_taken <<" | \n";
	else cout << "Shell: Tablica nieposortowana" << endl;

	copy(Twzor, Twzor+N, T);
	start = clock();
	MergeSort(T, 0, N-1);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if (!sprawdz(N, T))	cout << "| Merge | " << setprecision(3) << fixed << time_taken <<" | \n";
	else cout << "Merge: Tablica nieposortowana" << endl;

	copy(Twzor, Twzor+N, T);
	start = clock();
	qsort(T, 0, N-1);
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	if (!sprawdz(N, T))	cout << "| Quick | " << setprecision(3) << fixed << time_taken <<" | \n";
	else cout << "Quick: Tablica nieposortowana" << endl;



	
	cout << endl;
	
}