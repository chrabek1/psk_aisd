

#include <iostream>
#include <ctime>
//#include <unistd.h>
#include <iomanip>
using namespace std;
 
double vel(double c) {
    double g = 9.81, m = 68.1, t = 10;
    double result;
    result = g * m / c * (1 - exp(-(c / m) * t)) - 40;
    return result;
}
double vel_der(double x) {
    double result = exp(-0.146843 * x) * (4.16764 * pow(10, -16) * x - 668.061 * exp(0.146843 * x) + 2.83816 * pow(10, -15)) / pow(x, 2);
    return result;
}
void newtonRaphson() {
    double e = 0.01;
    double x = 20;
    double temp;
    double der = vel_der(x);
    cout << " | " << "x" << " | " << "|vel(x)|" << " | " << "\n";
    cout << " | " << x << " | " << abs(vel(x)) << " | " << "\n";
    do {
        temp = x - vel(x) / der;
        x = temp;
        der = vel_der(x);
        cout << " | " << x << " | " << abs(vel(x)) << " | " << "\n";
    } while (abs(vel(x)) > e);
    cout << "Wynik algorytmu metody Newtona-Raphsona: " << x << "\n";
}
 
 
void bisekcja() {
    double XL = 12, XR = 16, e = 0.1;
    double TEMP = XL;
    double MID = (XL + XR) / 2;
    double epsilon = 1;
    cout << " | " << "XL" << " | " << "XR" << " | " << "MID" << " | " << "EPS" << " | " << "\n";
    cout << " | " << XL << " | " << XR << " | " << MID << " | " << "---" << " | " << "\n";
    while (epsilon > e) {
 
        TEMP = MID;
        if (vel(XL) * vel(MID) < 0) XR = MID; else XL = MID;
        MID = (XL + XR) / 2;
        epsilon = abs((MID - TEMP) / MID) * 100;
        cout << " | " << XL << " | " << XR << " | " << MID << " | " << epsilon << " | " << "\n";
    }
    cout << "Wynik algorytmy metody bisekcji: " << MID << "\n\n";
}
 
int main(int argc, char** argv) {
    bisekcja();
    newtonRaphson();
};