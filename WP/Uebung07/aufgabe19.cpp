#include "MLCG.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void histogramm(int n,char **arg,double alpha, double beta){ 
	int hi[n] = {0};
	double k2 = (beta-alpha)/double(n);
	ifstream datei;
	string s;
	datei.open(arg[1], ios::in);
	while(!datei.eof()){
		getline(datei,s);
		for(int k = 0;k<n;k++){
			if(atof(s.c_str())<=(alpha+k*k2)){
				hi[k]++;
				break;
				}
		}
	}
	datei.close();
	fstream f2;
	f2.open(arg[2],ios::out);
	for(int i =0;i<n;i++){
		f2  << hi[i] << endl;
	}
	f2.close();
}




int main(int argc, char **argv){
	fstream f;
	f.open(argv[1],ios::out);
	MLCG test(4101842887655102017,21,35,4);//hier müsste du dann halt deine Methode für Zufallszahlen angeben.
	float x,y,fx;
	for(int i = 0;i<100000;i++){
	while (1)//das ist die schleife für das verwerfungsmethode
	{
      x=test.Flieran(20090,0,1);
      y=test.Flieran(464846,0,1.5);
      fx=6.0*x*(1-x);//das ist so die Gleichung die auch auf wikipedia steht
      if (y<fx)
        {
          break;
        }
     
    }
  f << x << endl;
}
f.close();

histogramm(1000,argv,0,1);//für das histogramm an erster Stelle die Datei zum einlesen,
//und an zweiter Stelle die Datei zum einlesen
}
