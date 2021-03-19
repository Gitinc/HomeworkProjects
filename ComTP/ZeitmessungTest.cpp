#include <math.h>
#include <iostream>
#include <ctime>
#include <omp.h>



using namespace std;

double f(double WertX, double WertY,double WertZ){
	return WertX*cos(WertY)+WertY*sin(WertX)+WertX*WertX*WertY/(WertX+100)+WertZ;
}

double g(double WertX, double WertY){
	return sin(WertX)*cos(WertX)+exp(WertX)+(WertX+WertY)/(WertX+100);
}

int main () 
{
	double anfang,ende;
	int sizeX,sizeY,sizeZ;
	double integralsumme;
	double integralsummeCache;
	sizeX = 100;
	sizeY = 100;
	sizeZ = 100;
	anfang = 0;
	ende = 1;
	double VolumenelementX = (ende-anfang)/double(sizeX);
	double VolumenelementY = (ende-anfang)/double(sizeY);
	double VolumenelementZ = (ende-anfang)/double(sizeZ);
	double Funktionswert[sizeX][sizeY][sizeZ];
	double xArr[sizeX];
	double yArr[sizeY];
	double zArr[sizeZ];
	integralsumme = 0;
	integralsummeCache = 0;

	
	for(int k=0;k<sizeY;k++){ 
		yArr[k] = (1+2*double(k))*(ende-anfang)/double(2*sizeY);
	}	
	for(int i=0;i<sizeX;i++){
		xArr[i] = (1+2*double(i))*(ende-anfang)/double(2*sizeX);
	}
	for(int i=0;i<sizeZ;i++){
		zArr[i] = (1+2*double(i))*(ende-anfang)/double(2*sizeZ);
	}
	
	clock_t begin = clock();
	for(int n=0;n<sizeX;n++){
		for(int m=0;m<sizeY;m++){
			for(int i=0;i<sizeZ;i++){
				Funktionswert[n][m][i] = f(xArr[n],yArr[m],zArr[i]);
				integralsumme += (Funktionswert[n][m][i])*VolumenelementX*VolumenelementY*VolumenelementZ;
			}
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	clock_t beginCache = clock();
	for(int n=0;n<sizeX;n++){
		for(int m=0;m<sizeY;m++){
			for(int i=0;i<sizeZ;i++){
				integralsummeCache += f(xArr[n],yArr[m],zArr[i]);
			}
		}
	}
	integralsummeCache *= VolumenelementX*VolumenelementY*VolumenelementZ;
	clock_t endCache = clock();
	
	double elapsed_secs_Cache = double(endCache - beginCache) / CLOCKS_PER_SEC;
	
	cout << "Wert des Integral Berechnungsmethode nur First Level Cache: " << integralsummeCache << endl;
	cout << "Zeitmessung First Level Cache: " << elapsed_secs_Cache << endl;
	cout << "Wert des Integral Berechnungsmethode großer Speicher: " << integralsumme << endl;
	cout << "Zeitmessung großer Speicher: " << elapsed_secs << endl;
}
