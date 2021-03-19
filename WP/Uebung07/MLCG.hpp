#ifndef _MLCG_H
#define _MLCG_H

#include "lgc.hpp"

class MLCG{
	long int y;
	int a1,a2,a3;
	public:
	MLCG(long int j,int k,int l,int o); 
	long int rangen(long int ver);
	double Flieran(int ver2,double al,double be);
};

#endif
