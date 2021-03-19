#include <iostream>
#include "Vektor.hpp"
#include <cmath>
using namespace std;

	Vektor::Vektor ():x(0), y(0), z(0) {};
	Vektor::Vektor (double a, double b, double c): x(a), y(b), z(c){};	
	double Vektor::betrag (){
		return sqrt( x * x + y * y + z * z);
	}
	Vektor Vektor::operator * (Vektor vek){
		return Vektor(y * vek.z - z * vek.y, z * vek.x - x * vek.z, x * vek.y - y *vek.x);
	}
	Vektor Vektor::operator + (Vektor vek){
		return Vektor(x + vek.x, y + vek.y, z + vek.z);
	}
	double spat(Vektor vek1, Vektor vek2, Vektor vek3){
		return skalar(vek1 * vek2, vek3);
	}
	double skalar(Vektor vek1, Vektor vek2){
		return vek1.x * vek2.x + vek1.y * vek2.y + vek1.z * vek2.z;
	}	
	 ostream& operator<< (ostream& ostr, Vektor vek){					 // der << Operator erwartet einen ostream (cout) und normalerweise einen Datentyp wie int, double usw.
		ostr << "[" << vek.x << ", " << vek.y << ", " << vek.z << "]"; // für selbstdefinierte Typen muss der Operator so überladen werden, dass er den ostream und den selbstdefinierten Typ erwartet.
		return ostr;													// Die Referenz wird benötigt, da der ostreams oft aus vielen Daten besteht und diese für die Ausgabe verändert werden müssen.
	}	// Die ostream-Referenz ist gleichzeitig auch der Rückgabetyp, wie beim Standardoperator <<.
		// In der Funktion selbst, wird der Standardoperator << genutzt um die double Werte des jeweiligen Vektors und die anderen Zeichen, auszugeben.
		// Dadurch das der Operator auf die privaten Variabeln der Klasse Vektor zugreifen muss, wird er in der .hpp Datei als friend von Vektor deklariert.
		// In der Anwendung der überladen Operators wird nun ein ostream, hier cout und ein Typ der Klasse Vektor erwartet. 

