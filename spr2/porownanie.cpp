#include <iostream>
#include <ctime>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

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

void podstawa_stos(int n,int  b) {
    stack<int> stos;
    stack<int> stos2;
    while(n!=0) {
        stos.push(n%b);
        n=n/b;
    } 
    while(!stos.empty()) {
        cout<<stos.top()<<"_";
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
        cout<<lista.back()<<"_";
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
        cout<<tab[i]<<"_";
    }
}
void taniec() {
    string line;
    queue<string> panowie;
    queue<string> panie;
    fstream file("dane.txt");
    while(getline (file,line)) {
        if(line[0] == 'M') {
            panowie.push(line);
        }
        else panie.push(line);
    }
}

int main(){
    /*tab_init();
    list_init();
    cout<< "stos: ";
    podstawa_stos(100,8);
    cout<< "\nlista: ";
    podstawa_lista(100,8);
    cout<< "\ntablica: ";
    podstawa_tablica(100,8);*/
}