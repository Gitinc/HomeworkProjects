#ifndef _mlcgXOR_hpp_
#define _mlcgXOR_hpp_


class Mlcgxor {

	unsigned long int x, a1, a2, a3, a, c, m;

public: 
	Mlcgxor (unsigned long int b);
	unsigned long int mlcgshiften (int anzahl);
	double intervall(double obereGrenze, double untereGrenze, int wert);
	unsigned long int x_get();
	unsigned long int a1_get();
	unsigned long int a2_get();
	unsigned long int a3_get();
	unsigned long int a_get();
	unsigned long int c_get();
	unsigned long int m_get();
	unsigned long int a1_set(unsigned long int b);
	unsigned long int a2_set(unsigned long int b);
	unsigned long int a3_set(unsigned long int b);
	unsigned long int a_set(unsigned long int b);
	unsigned long int c_set(unsigned long int b);
	unsigned long int m_set(unsigned long int b);
	

};


#endif 