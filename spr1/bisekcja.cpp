#include <iostream>
#include <ctime>
//#include <unistd.h>
#include <iomanip>
using namespace std;

double vel(float c) {
	float g = 9.81, m = 68.1, t = 10;
	double result;
	result = g * m / c * (1 - exp(-(c / m) * t)) - 40;
	//cout << result<<"\n";
	return result;

}
double f_new(double x) {
	return exp(-x) - x;
}
double f_new_der(double x) {
	return -exp(-x) - 1;
}
void newtonRaphson() {
	float e = 0.0001;
	float x = 5;
	double temp;
	do {
		temp = x - f_new(x) / f_new_der(x);
		x = temp;
	} while (abs(f_new(x)) < e);
	cout << "Wynik Newtona-Raphsona " << x;
}
void bisekcja() {
	double XL = 12, XR = 16, e = 0.1;
	double TEMP = XL;
	double MID = (XL + XR) / 2;
	double epsilon = 0;
	cout << "XL" << "\t" << "XR" << "\t" << "MID" << "\t" << "EPS" << "\n";
	do {
		cout << XL << "\t" << XR << "\t" << MID << "\t" << epsilon << "\n";
		TEMP = MID;
		if (vel(XL) * vel(MID) < 0) XR = MID; else XL = MID;
		MID = (XL + XR) / 2;
		epsilon = abs((MID - TEMP) / MID) * 100;
	} while (epsilon < e);
	cout << "\nWYNIK" << MID;
}

int main(int argc, char** argv) {
	//bisekcja();
	newtonRaphson();

};