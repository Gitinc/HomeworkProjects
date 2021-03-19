#include<iostream>
#include<cmath>
#include"mlcgXOR.hpp"
using namespace std;






Mlcgxor::Mlcgxor (unsigned long int b)
{
	x = b ^ 234567895432;
	a1 = 21;
	a2 = 35;
	a3 = 4;
	a = 2685821657736338717;
	c = 0;
	m = 18446744073709551615;
}

unsigned long int Mlcgxor::mlcgshiften (int anzahl)
{
	for (int i = 0; i < anzahl; i++){
		x = (a * (x ^ ( x >> a1)) + c) % m ;
		x = (a * (x ^ ( x << a2)) + c) % m ;
		x = (a * (x ^ ( x >> a3)) + c) % m ;
	}
	return x;
}



double Mlcgxor::intervall (double obereGrenze, double untereGrenze, int wert)
{
	double temp2 = double(this->mlcgshiften(wert))/9223372036854775807.;
	temp2 = temp2 - 1;
	if (temp2 < 0){
		temp2 = temp2 * (- 1.);
		}
	return untereGrenze + temp2 *(obereGrenze - untereGrenze);
}

unsigned long int Mlcgxor::x_get()
{
	return x;
}
unsigned long int Mlcgxor::a1_get()
{
	return a1;
}

unsigned long int Mlcgxor::a2_get()
{
	return a2;
}

unsigned long int Mlcgxor::a3_get()
{
	return a3;
}

unsigned long int Mlcgxor::a_get()
{
	return a;
}

unsigned long int Mlcgxor::c_get()
{
	return c;
}

unsigned long int Mlcgxor::m_get()
{
	return m;
}

	unsigned long int Mlcgxor::a1_set(unsigned long int b)
{
	a1 = b;
	return a1;
}
	unsigned long int Mlcgxor::a2_set(unsigned long int b)
	{
		a2 = b;
	return a1;
	}
	unsigned long int Mlcgxor::a3_set(unsigned long int b)
	{
		a3 = b;
	return a3;
	}
	unsigned long int Mlcgxor::a_set(unsigned long int b)
	{
		a = b;
	return a;
	}
	unsigned long int Mlcgxor::c_set(unsigned long int b)
	{
		c = b;
	return c;
	}
	unsigned long int Mlcgxor::m_set(unsigned long int b)
	{
		m = b;
	return m;
	}