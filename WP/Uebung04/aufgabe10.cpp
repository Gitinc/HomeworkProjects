#include<iostream>
#include"swap.hpp"

using namespace std;



	int main()
	{

		int eingabe1;
		int eingabe2;
		int speicherEing1;
		int speicherEing2;
		cout << "Bitte geben Sie hier eine Ganze Zahl ein: " << endl;
		cin >> eingabe1;
		cout << "Bitte geben Sie hier eine zweite Ganze Zahl ein: " << endl;
		cin >> eingabe2;
		speicherEing1 = eingabe1;
		speicherEing2 = eingabe2;
		cout << "Sie haben die Zahl: " << eingabe1 << eingabe2 << " eingeben." << endl;
		swap_ref(eingabe1, eingabe2);
		cout <<"Tauscher mit Referenzen: " << eingabe1 << eingabe2 << endl;
		eingabe1 = speicherEing1;
		eingabe2 = speicherEing2;
		cout << "Hier nochmal Ihre eingebene Zahl: " << eingabe1 << eingabe2 << endl;
		swap_ptr(&eingabe1, &eingabe2);
		cout << "Tauscher mit Zeigern:  " << eingabe1 << eingabe2 << endl;


	}
	
	
