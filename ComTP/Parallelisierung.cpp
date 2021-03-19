#include <math.h>
#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

double f(double WertX, double WertY){
	return WertX*WertX*WertY*WertY;
}

int main () 
{
	double anfang,ende;
	double x,y;
	int sizeX,sizeY;
	double integralsummeCache;
	sizeX = 1000;
	sizeY = 1000;
	anfang = 0;
	ende = 10;
	double VolumenelementX = (ende-anfang)/double(sizeX);
	double VolumenelementY = (ende-anfang)/double(sizeY);
	
	clock_t beginCache = clock();
	#pragma parallel for
	for(int i=0;i<sizeX;i++){
		for(int k=0;k<sizeY;k++){
			x = (1+2*double(i))*(ende-anfang)/double(2*sizeX);
			y = (1+2*double(k))*(ende-anfang)/double(2*sizeY);
			integralsummeCache += f(x,y)*VolumenelementY*VolumenelementX;
		}
	}
	clock_t endCache = clock();
	double elapsed_secs_Cache = double(endCache - beginCache) / CLOCKS_PER_SEC;
	
	cout << "Wert des Integral Berechnungsmethode nur First Level Cache: " << integralsummeCache << endl;
	cout << "Zeitmessung First Level Cache: " << elapsed_secs_Cache << endl;
}
