#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;


double* feld (int a) //dynamische Speicherbereitstellung
{
	double* array = new double[a];
	for (int i = 0; i < a; i++){
		array[i] = 0;
	}
	return array;
}


int main(int argc, char** argv)
{


	ifstream datei;
	string zeile;
	int zeilenanzahl = 0;
	double* arrayptr = 0;


	if(argc == 2){
	
	datei.open(argv[1], ios::in);	
	
	if(datei.is_open()){
		while (getline(datei, zeile)){ //Bestimmung der Zeilenanzahl fuer arraygroesse
				zeilenanzahl ++;
			}

	arrayptr = feld(zeilenanzahl); //uebergabe des arrays an ptr
	datei.close();

	datei.open(argv[1], ios::in); //Datei zweites mal oeffnen um wieder am Anfang zu sein
	while (getline(datei, zeile)){ //Zeilen in array schreiben und ausgeben
			
			int i = 0;
			arrayptr[i] = atof(zeile.c_str());
			arrayptr = &arrayptr[i];
			
			cout << *(arrayptr)<< endl;
			i++;
			
	}
	}
	else { //Datei wurde falsch angegeben
		cout << "Die Datei ist nicht vorhanden. Bitte ueberpruefen Sie ihre Eingabe (Muster: ./aufgabe16 Datei.txt)" << endl;
	}
	datei.close();
	delete[] arrayptr; //Loeschung des dynamischen Speichers
	}
	else{ //Fall fuer falsche Dateiangabe
		cout << "Bitte geben sie nach der zu ausfuehrenden Datei die zu lesende Datei ein. Muster: ./aufgabe16 Datei.txt"<< endl;
	}
	
}


