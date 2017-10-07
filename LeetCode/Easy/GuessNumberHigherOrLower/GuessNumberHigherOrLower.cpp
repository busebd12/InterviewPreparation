#include <iostream>
using namespace std;

int guessNumber(int n)
{
	int start=1;

	int end=n;

	while(start <= end)
	{
		int value=start + (end-start)/2;

		int guessResult=guess(value);

		if(guessResult==0)
		{
			return value;
		}
		else if(guessResult==-1)
		{
			end=value;
		}
		else
		{
			start=value+1;
		}
	}

	return -1;
}