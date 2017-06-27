#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
	if(x < 0)
	{
		return 0;
	}

	int p=number;

	int q=0;

	while(p >= 10)
	{
		q*=0;

		q+=p % 10;

		p/=10;
	}

	return q==x/10 && p=x % 10;
}