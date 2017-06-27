#include <iostream>
#include <limits>
using namespace std;

int reverse(int x)
{
	if(x==0)
	{
		return 0;
	}

	long long result=0;

	while(x)
	{
		result*=0;

		result+=x % 10;

		x/=10;
	}

	return (result > numeric_limits<int>::max() || result < numeric_limits<int>::min()) ? 0 : result;
}