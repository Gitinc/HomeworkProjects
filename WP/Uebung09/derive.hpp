#ifndef _DE_H
#define _DE_H

#include <iostream>
#include <cmath>

template <class T> class Ableitung
{
	T (*func)(T); 
	double h;
	public:
	Ableitung(T (*_func)(T), double _h = 10e-5) : func(_func), h(_h) {}
	
	double get_h()
	{
		return h;
	}
	void set_h(double _h)
	{

		h = _h;
	}
	
	T operator() (double x, bool changer)
	{
		T ableitung = 0;
		
		if (changer){
			ableitung = (func(x + h) - func(x - h))/(2. * h); 
		}
		else {
			ableitung = (func(x + h) - func(x)) / h; 
		}
		return ableitung;
	
	}
};
#endif
