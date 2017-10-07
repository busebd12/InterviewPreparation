#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfFour(int Num)
{
	if(Num <= 0)
	{
		return false;
	}

	while(Num%4==0)
	{
		Num/=4;
	}

	return Num==1;
}