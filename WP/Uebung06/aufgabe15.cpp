#include <iostream>
#include "Vektor.hpp"
#include <cmath>

using namespace std;

int main() {

	// Vektoren initialisieren
	Vektor a;
	Vektor b (1,2,3);
	Vektor c (-1,2,-2);
	Vektor d (1,0,0);

	cout << "Vektor a: " << a << endl;
	cout << "Vektor b: " << b << endl;
	cout << "Vektor c: " << c << endl;
	cout << "Vektor d: " << d << endl;

	// Betrag
	cout << "|a| = " << a.betrag() << " = 0" << endl;
	cout << "|c| = " << c.betrag() << " = 3" << endl;

	// Kreuzprodukt
	cout << "b x c = " << b * c << " = (-10 -1 4)T" << endl;
	cout << "c x b = " << c * b << " = -(b x c)" << endl;


	 //Addition
	cout << "a + b = " << a + b << " = " << b + a << " = b + a = (1 2 3)T" << endl;
	cout << "c + c = " << c + c << " = (-2 4 -4)T" << endl;

	//Skalarpodukt
	cout << "<a,b> = " << skalar(a,b) << " = 0" << endl;
	cout << "<c,b> = " << skalar(c,b) << " = " << skalar(b,c) << " = <b,c> = -3" << endl;

	 //Spatprodukt

	// Addition
	cout << "a + b = " << a + b << " = " << b + a << " = b + a = (1 2 3)T" << endl;
	cout << "c + c = " << c + c << " = (-2 4 -4)T" << endl;

	// Skalarpodukt
	cout << "<a,b> = " << skalar(a,b) << " = 0" << endl;
	cout << "<c,b> = " << skalar(c,b) << " = " << skalar(b,c) << " = <b,c> = -3" << endl;

	// Spatprodukt

	cout << "(a x b) * c = " << spat(a,b,c) << " = 0" << endl;
	cout << "(b x c) * d = " << spat(b,c,d) << " = -10" << endl;
}
