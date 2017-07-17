#include <iostream>
using namespace std;

int trailingZeros(int n)
{
	int result=0;

	for(long long i=5;(n/i)>0;++i)
	{
		result+=(n/i);
	}

	return result;
}