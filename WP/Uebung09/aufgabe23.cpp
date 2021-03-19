
#include <iostream>
#include <cmath>
#include "derive.hpp"
using namespace std;


int main()
{
	

 Ableitung<double> a(sin);
cout << a(3.14/2., 0) << endl;
cout << a(3.14/2., 1) << endl; // die erste Ziffer ist die Stelle an der abgeleitet werden soll 
// die zweite stelle gibt die ableitungsmethode
// 0 ist der normale diff-quotient, 1 ist der symmetrische

 a.set_h(0.00001); // h = 0.1 setzen
 
cout << a(3.14/2., 0) << endl;
cout << a(3.14/2., 1) << endl;

}
