#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double summe = 0;
	double summe2 = 0;
	
	for (double N = 1; N < 4294967296; N++){ // ist ungenauer als die zweite Methode, da die Zahlen zu Beginn so groß, im Gegensatz zu den letzten 1/N, dass die Genauigkeit der letzten Summanden nicht 
		summe = summe + 1. /N; // nicht vollständig berücksichtig werden kann. Dadurch werden ab bestimmten N, Terme einfach Null gesetzt.
	}
	for (double N = 4294967295; N > 0; N--){ // Bei der dieser Methode können mehr Zahlen berücksichtigt werden, da die niedrigen Zahlen zunächst aufaddiert werden
	// und somit wenn die Genauigkeit von double diese Zahlen nullsetzen würde, stecken die Zahlen schon in den nachfolgenden Summanden und damit werden sie für das Gesamtergebnis berücksichtigt.
	summe2 = summe2 + 1./ N;
	}
	 cout << setprecision(17) << summe << "\t" << setprecision(17) << summe2 << endl;
}