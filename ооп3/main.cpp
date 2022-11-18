#include <iostream>
#include "Bankomat.h"
int main() {
	setlocale(LC_ALL,"Rus");
	Money m(156,77);
	Money m1(2, 24);
	Bankomat b(5,600,22);
	Bankomat f(b-m);
	f = b - m;
	cout<<(b-m).toString();
}