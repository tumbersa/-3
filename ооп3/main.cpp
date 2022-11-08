#include <iostream>
#include "Bankomat.h"
int main() {
	setlocale(LC_ALL,"Rus");
	Bankomat tt(2000,3501,67);
	
	cout<<tt.toString()<<endl;
	double l = 100.14;
	cout << (int)l << " " << l - (int)l<<endl;
	tt = tt + l;
	cout << tt.toString();
}