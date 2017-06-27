#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int N)
{
	if(N <= 0)
	{
		return false;
	}

	while(N%2==0)
	{
		return true;
	}

	return N==1;
}