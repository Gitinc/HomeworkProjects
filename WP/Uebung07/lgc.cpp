class Zufall{
	long int x,a,c;
	unsigned long int m;
	public:
	Zufall(long int u,long int v,unsigned long int w,long int y);
	long int erzeuge();
};

Zufall::Zufall(long int u,long int v,unsigned long int w,long int y){
	a = u;
	c = v;
	m = w;
	x = y;
}

long int Zufall::erzeuge(){
	x = ((a*x)+c) % m;
	return x;
}

