#include <iostream>
#include <cmath>
using namespace std;

 
template <class T> class Ableitung
{
	T (*func)(T); //Funktionenzeiger, damit lassen sich die Funktionen übergeben, z.B T = double  und *func = sin, 
	// dann ergibt sich double (sin)(double), die normale sinus definition.
	double h;
	
	public:
	Ableitung(T (*_func)(T), double _h = 10e-5) : func(_func), h(_h) {}
	
	//hiermit lässt sich h anzeigen
	double get_h()
	{
		return h;
	}
	// hiermit lässt sich h verändern
	void set_h(double _h)
	{

		h = _h;
	}
	
	T operator() (double x, bool changer)
	{
		T ableitung = 0;
		
		if (changer){
			ableitung = (func(x + h) - func(x - h))/(2. * h); 
			 // durch Funktionenzeigen sieht er die Klammer bei func() wirklich als Variablen zuweisung
			// wie bei f(x).
		}
		else {
			ableitung = (func(x + h) - func(x)) / h;
		}
		return ableitung;
	}

};
