#include <iostream>
#include <ctime>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

const long n=999999;
void insert_into_array(int arr[], int& size, int pos, int value) {
    int* newArr = new int[size +1];
    for(int i=0; i< size +1; i++) {
        if(i < pos) {
            newArr[i] = arr[i];
        } else if(i == pos) {
            newArr[i] = value;
        } else {
            newArr[i] = arr[i -1];
        }
    }
    size++;
    //delete[] arr;
    arr = newArr;  
}
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
    cout << "Czas inicjalizacji " << n <<  "-elementowej tablicy: " << setprecision(3) << time_taken*1000 << " milisekund" << endl;
    int N=n;
    start=clock();
    insert_into_array(tab, N, n/4, 123);
    insert_into_array(tab, N, n/3, 123);
    insert_into_array(tab, N, n/2, 123);
    end=clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Czas wstawiania 3 elementow do tablicy: " << setprecision(3) << time_taken*1000 << " milisekund" << endl;
}
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
    cout << "Czas inicjalizacji " << n << "-elementowej listy: " << setprecision(3) << time_taken*1000 << " milisekund" << endl;
    list<int>::iterator it;
    start = clock();
    it=l.begin();
    advance(it, n/4);
    l.insert(it, 123);
    it=l.begin();
    advance(it, n/3);
    l.insert(it, 123);
    it=l.begin();
    advance(it, n/2);
    l.insert(it, 123);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Czas wstawiania 3 elementow do listy: " << setprecision(3) << time_taken*1000 << " milisekund" << endl;
}

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
    cout<<"\n\n";
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

int main(){
    tab_init();
    list_init();
    cout<< "stos: ";
    podstawa_stos(128,2);
    cout<< "\nlista: ";
    podstawa_lista(128,2);
    cout<< "\ntablica: ";
    podstawa_tablica(128,2);
    taniec();
}