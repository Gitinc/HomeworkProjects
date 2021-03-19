#include <iostream>
#include <fstream>
#include "lgc.hpp"
using namespace std;

int main(int argc, char **argv){
	fstream f;
	f.open(argv[1],ios::out);
	Zufall test(4,0,200,1);//gibt man für test mehr als 10 Werte aus wiederholen sich diese
	Zufall RANDU(65539,0,2147483648,1);//dies tut es bei RANDU wahrscheinlich auch wobei die
	//Periode weitaus höher ist
	for(int i = 0;i<30000;i++){
	f << RANDU.erzeuge() << "\t" << RANDU.erzeuge() << "\t" << RANDU.erzeuge() << endl; //durch den Plot sind
	//Hypereben zu sehen in denen sich die Zahlen befinden. Es ist nicht wirklich random
}
f.close();
}
