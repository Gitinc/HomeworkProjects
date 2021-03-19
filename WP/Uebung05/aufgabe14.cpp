#include <iostream>

using namespace std;

class Polynom{
	float a0,a1,a2,a3,a4,a5;
	public:
	Polynom(double a = 0,double b = 0,double c = 0,double d = 0,double e = 0,double f = 0);
	Polynom ableiten();
	void ausgeben();
	double operator() (float x);
	
};

Polynom::Polynom(double a,double b,double c,double d, double e, double f){
	a0 = a;
	a1 = b;
	a2 = c;
	a3 = d;
	a4 = e;
	a5 = f;
}

void Polynom::ausgeben(){ //Funktion um zu testen ob Polynom richtig initialisiert wurde
	cout << a0 << endl;
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
	cout << a5 << endl;
}

double Polynom::operator() (float x)  {
	double k = a0+a1*x+a2*x*x+a3*x*x*x+a4*x*x*x*x+a5*x*x*x*x*x;
	return k;
}


Polynom Polynom::ableiten(){
	Polynom h(a1,2*a2,3*a3,4*a4,5*a5);
	return h;
}

int main(){
	Polynom f(1,0,1);
	Polynom g(0,1,0,2,0,3);
	cout << "x:" << "\t" << "f(x)" << "\t" << "g(x)" << ends;
	cout << "\t" << "f'(x)" << "\t" << "g'(x)" << endl;
	for(double i = -2;i<=2;i=i+0.01){
	cout << i << "\t" << f(i) << "\t" << g(i) << "\t" << ends; 
	cout << f.ableiten()(i) << "\t" <<	g.ableiten()(i)<< endl; //Zeilen sind nicht immer so schön...
	}
	
}
