#include <iostream>
#include "MLCG.hpp"
#include <fstream>

using namespace std;


int main(int argc, char **argv){
	long int ver1;
	double al1, be1;
	int tempo = 0;
	cout << "Bitte geben sie zuerst Bitverschiebungszahl, dann die untere Intervallgrenze, die obere Intervallgrenze und Anzahl der double Zufallszahlen ein" << endl;
	cin >> ver1;
	cin >> al1;
	cin >> be1;
	cin >> tempo;
	fstream f;
	f.open(argv[1],ios::out);
	MLCG test(4101842887655102017,21,35,4);
	for(int i = 0;i<15000;i++){
	f << test.rangen(ver1) <<  endl;
}
f.close();
for(int i =0;i<=tempo;i++){
cout << test.Flieran(ver1,al1,be1)<< endl;
}//Im Vergleich mit RANDU sind keine Hyperebenen mehr zu sehen
}//Die erzeugten Zahlen sind gleichverteilt
