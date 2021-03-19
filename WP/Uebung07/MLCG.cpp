#include "lgc.hpp"
using namespace std;

class MLCG{
	long int y;
	int a1,a2,a3;
	public:
	MLCG(long int j,int k,int l,int o); 
	long int rangen(long int ver);
	double Flieran(int ver2,double al,double be);
};

MLCG::MLCG(long int j,int k,int l,int o){
	y = j;
	a1 = k;
	a2 = l;
	a3 = o;
}

long int MLCG::rangen(long int ver){
	y = y^ver;
	y = y^(y>>a1);
	y = y^(y<<a2);
	y = y^(y>>a3);
	Zufall kurz(2685821657736338717,0,18446744073709551615,y);
	return kurz.erzeuge();
}

double MLCG::Flieran(int ver2,double al,double be){
	double temp2 = double(this->rangen(ver2))/9223372036854775807;
	if(temp2<0){
	temp2=temp2*(-1);
	}
	return al+temp2*(be-al);
}
