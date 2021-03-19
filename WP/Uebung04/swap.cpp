#include<iostream>

using namespace std;


void swap_ref(int& ref1, int& ref2)
{
	int eingabe1 = ref1;
	int eingabe2 = ref2;
	ref2 = eingabe1;
	ref1 = eingabe2;

}


void swap_ptr(int* zeiger1, int* zeiger2)
{
	int eingabe1 = *zeiger1;
	int eingabe2 = *zeiger2;

	*zeiger2 = eingabe1;
	*zeiger1 = eingabe2;

}
