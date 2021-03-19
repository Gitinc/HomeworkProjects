#include <iostream>
#include <string>
#include "bitmuster.hpp"
using namespace std;

int main()
{
	char a;
	for (int i = 33; i <= 126; i++){
	a = i;
	cout << a << "\t" << dec << i << "\t" << hex << i <<"\t" << bitmuster(i)<< endl;	
	}
}
