#include <iostream>
#include <string>
using namespace std;


string bitmuster (unsigned char test)
{
	unsigned int bit = 1;
	string muster;
	for (int i = 1; i <= 8; i++){
			
		
			if ((test & bit) == 0) {
				muster.insert(0, "0");
			}
			else {
				muster.insert(0 ,"1");
			}
	bit = bit << 1;
	}
	return muster;
}
