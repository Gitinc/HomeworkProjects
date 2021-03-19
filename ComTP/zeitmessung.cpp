#include <math.h>
#include <iostream>
#include <ctime>
#include <omp.h>



using namespace std;

double f(double WertX, double WertY){
	return WertX*cos(WertY)+WertY*sin(WertX)+WertX*WertX*WertY/(WertX+100);
}

double g(double WertX, double WertY){
	return sin(WertX)*cos(WertX)+exp(WertX)+(WertX+WertY)/(WertX+100);
}

int main () 
{
	double anfang,ende;
	double x,y;
	int sizeX,sizeY;
	double integralsumme;
	double integralsummeCache;
	sizeX = 1000;
	sizeY = 1000;
	anfang = 0;
	ende = 1;
	double VolumenelementX = (ende-anfang)/double(sizeX);
	double VolumenelementY = (ende-anfang)/double(sizeY);
	double a[sizeX][sizeY];
	//double b[sizeX][sizeY];
		
	for(int i=0;i<sizeX;i++){
		for(int k=0;k<sizeY;k++){
			x = (1+2*double(i))*(ende-anfang)/double(2*sizeX);
			y = (1+2*double(k))*(ende-anfang)/double(2*sizeY);
			a[i][k] = f(x,y);
		}
	}
	
	/*
	for(int i=0;i<sizeX;i++){
		for(int k=0;k<sizeY;k++){
			x = (1+2*double(i))*(ende-anfang)/double(2*sizeX);
			y = (1+2*double(k))*(ende-anfang)/double(2*sizeY);
			b[i][k] = g(x,y);
		}
	}
	*/
	integralsumme = 0;
	/*
	double test[sizeX];
	double test1[sizeX];
	
	for(int m=0;m<sizeX;m++){
		test[m] = m/sizeX;
	}
	
	for(int n=0;n<sizeX;n++){
		test1[n] = 2*n/sizeX;
	}
	
	clock_t begin = clock();
	for(int n=0;n<sizeX;n++){
		test[n] = exp(test[n]+test1[n]);
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	clock_t beginCache = clock();
	for(int n=0;n<sizeX;n++){
		test[n] = exp(test[n])+exp(test1[n]);
	}
	clock_t endCache = clock();
	*/
	
	
	clock_t begin = clock();
	for(int n=0;n<sizeX;n++){
		for(int m=0;m<sizeY;m++){
			integralsumme += (a[n][m])*VolumenelementX*VolumenelementY;
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	clock_t beginCache = clock();
	for(int n=0;n<sizeX;n++){
		for(int m=0;m<sizeY;m++){
			integralsummeCache += (a[n][m]);
		}
	}
	integralsummeCache *= VolumenelementX*VolumenelementY;
	clock_t endCache = clock();
	
	/*
	clock_t beginCache = clock();
	for(int n=0;n<sizeX;n++){
		for(int m=0;m<sizeY;m++){
			integralsummeCache += (a[n][m])*VolumenelementX*VolumenelementY;
		}
	}
	for(int n=0;n<sizeX;n++){
		for(int m=0;m<sizeY;m++){
			integralsummeCache += (b[n][m])*VolumenelementX*VolumenelementY;
		}
	}
	clock_t endCache = clock();
	*/
	double elapsed_secs_Cache = double(endCache - beginCache) / CLOCKS_PER_SEC;
	
	cout << "Wert des Integral Berechnungsmethode nur First Level Cache: " << integralsummeCache << endl;
	cout << "Zeitmessung First Level Cache: " << elapsed_secs_Cache << endl;
	cout << "Wert des Integral Berechnungsmethode großer Speicher: " << integralsumme << endl;
	cout << "Zeitmessung großer Speicher: " << elapsed_secs << endl;
}
