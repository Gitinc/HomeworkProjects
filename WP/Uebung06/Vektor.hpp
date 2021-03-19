
#ifndef _Vektor_hpp_
#define _Vektor_hpp_
using namespace std;

class Vektor {
	double x, y, z;
public:
	Vektor ();
	Vektor (double a, double b, double c);	
	double betrag ();
	Vektor operator * (Vektor vek);
	Vektor operator + (Vektor vek);
	friend double spat(Vektor vek1, Vektor vek2, Vektor vek3);
	friend double skalar(Vektor vek1, Vektor vek2);
	friend ostream& operator<< (ostream& ostr, Vektor vek);
};
#endif
