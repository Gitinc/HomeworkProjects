#include <math.h>
#include <iostream>
#include <vector>

typedef std::vector<double> vec;

vec operator+(vec x, vec y){
	vec ergebnis(x.size());
	for(int i = 0;i<int(x.size());i++){
		ergebnis[i] = x[i]+y[i];
	}
	return ergebnis;
}

vec operator*(double lambda, vec x){
	vec ergebnis(x.size());
	for(int i = 0;i<int(x.size());i++){
		ergebnis[i] = lambda*x[i];
	}
	return ergebnis;
}

vec f(vec x){
	 const double rho = 28;
	 const double beta = 8/3;
	 const double sigma = 10;
	 
	 vec abl(3,0);
	 
	 abl[0] = sigma * (x[1] - x[0]);
	 abl[1] = x[0] * (rho - x[2]) - x[1];
	 abl[2] = (x[1] * x[0]) - (beta * x[2]);
	 
	 return abl;
}


vec g(vec x){
	 const double r = 1;
	 const double k = 8;
	 
	 vec abl(2,0);
	 
	 abl[0] = x[1];
	 abl[1] = -r*x[1]-k*x[0];
	 
	 return abl;
}


void UpSolution(vec &a,/*vec (*f)(vec),*/double h = 0.1){
	
	vec k1(a.size());
	vec k2(a.size());
	vec k3(a.size());
	vec k4(a.size());

/*	
	k1 = h * f(a);
	
	k2 = h * f(a + (0.5 * k1));
	
	k3 = h * f(a + (0.5 * k2));
	
	k4 = h * f(a + k3);
	
	a = a + (1.0/6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4);
*/
k1 = h * g(a);
	
	k2 = h * g(a + (0.5 * k1));
	
	k3 = h * g(a + (0.5 * k2));
	
	k4 = h * g(a + k3);
	
	a = a + (1.0/6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4);
	
}





int main () 
{
	/*
	vec a(3);
	a[0] = 1;
	a[1] =10;
	a[2] = 1;

	
	for(int i = 0; i < 1000; i++){
		std::cout << a[0] << ";" << a[1] << ";" << a[2] << std::endl;
		UpSolution(a);
		}
	*/
	vec a(2);
	a[0] = 1;
	a[1] = 0;

	for(int i = 0; i < 1000; i++){
		std::cout << a[0] << ";" << a[1] << std::endl;
		UpSolution(a);
		}
}
