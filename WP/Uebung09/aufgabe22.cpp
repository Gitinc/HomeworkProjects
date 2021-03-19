#include <boost/random.hpp>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

boost::mt19937 rng;

double rangDou(int k1,int k2){//auslagerung des erstellen der random Zahlen auf eine Funktion
	boost::uniform_real<> dist(k1,k2);//somit wird nicht jedesmal ein neuer generator erstellt
	return dist(rng);//sondern einfach nur die Distribution verändert
	
}

double MCI(int durchlaufe){
	int dri = 0;
	for(int i = 0;i<=durchlaufe;i++){
		double x = rangDou(1,4);
		double y = rangDou(-2,3);//Haben versucht Intervall möglichst klein zu machen
		double z = rangDou(-1,1);//Damit weniger Zufallszahlen erstellt werden müssen
		double temp = z*z+(sqrt(x*x+y*y)-3)*(sqrt(x*x+y*y)-3);//Möglichst geringer Zugriff auf cmath
		if (0.25 <= temp && temp <= 1){
			dri++;
		}
	}
	return double(dri)/durchlaufe;
}

int main() {
	fstream datei;
	datei.open("Integration.txt", ios::out);
	datei << "10^3 Iterationen:" << MCI(1000)<< endl;
	datei << "10^5 Iterationen:" << MCI(100000)<< endl;
	datei << "10^7 Iterationen:" << MCI(10000000)<< endl;
	datei << "2^28 Iterationen:" << MCI(268435456)<< endl;
	datei.close();
}
