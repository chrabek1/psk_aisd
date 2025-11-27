#include <iostream>
using namespace std;
void zad1(int a, int b, int h){
    if(a<=b){
        cout<<a<<endl;
        zad1(a+h,b,h);
    }   
}
int zad2(int tab[], int n, int x){
    if(tab[n]==x) return n;
    else if(n==0) return -1;
    else return zad2(tab,n-1,x);
}
int zad3(char *n, int k){
    if(*n=='.') 
        return k;
    else
        if (*n=='x') k++;
    return zad3((n+1),k);
}
int zad4(int n){
    if(n==1) return 3;
    return pow(2,n-1)*zad4(n-1)-4;

}
int main(){
    int tab[]={2,4,7,4,1,5};
    cout<<"zad1"<<endl;
    zad1(2,5,1);
    cout<<"zad2"<<endl;
    cout<< zad2(tab,6,5)<<endl;
    cout<<"zad3"<<endl;
    char tekst[]="xrerrxox.x";
    cout<<zad3(tekst,0)<<endl;
    cout<<"zad4"<<endl;
    cout<<zad4(4)<<endl;
}