#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

bool isHappy(int n)
{
	int number=n;

	unordered_set<int> previousSums;

	bool result=false;

	while(true)
	{
		int sum{};

		while(number >= 10)
		{
			int digit=number % 10;

			sum+=pow(digit, 2);

			number/=10;
		}

		sum+=pow(number, 2);

		number=sum;

		if(number==1)
		{
			result=true;

			break;
		}
		else
		{
			if(previousSums.find(sum)==end(previousSums))
			{
				previousSums.insert(sum);
			}
			else
			{
				result=false;

				break;
			}
		}
	}

	return result;
}