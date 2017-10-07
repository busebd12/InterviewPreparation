#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfThree(int N)
{
	if(N <= 0)
	{
		return false;
	}

	while(N%3==0)
	{
		N/=3;
	}

	return N==1;
}