#include <iostream>
#include <cmath>
using namespace std;

double polynom(double x,double a = 0, double b = 0,double c = 0, double d = 0, double e = 0, double f = 0){
	double k = 0;
	k = a+b*x+c*x*x+d*x*x*x+e*x*x*x*x+f*x*x*x*x*x;
	return k;
}


int main()
{
	cout << "x: \t" << "y1: \t" << "y2:" << endl;
	for (double i = -2;i<=2;i=i+0.01){
		cout << i << "\t" << polynom(i,1,2) << "\t" << polynom(i,1,0,1,0,1,0) << endl; //Null würd nicht richtig dargestellt, weil Rundung...
	}
	
	}
