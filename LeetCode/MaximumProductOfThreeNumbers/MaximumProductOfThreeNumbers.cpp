#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int maximumProduct(vector<int> & nums)
{
	if(nums.empty())
	{
		return 0;
	}

	int max1=numeric_limits<int>::min();

	int max2=numeric_limits<int>::min();

	int max3=numeric_limits<int>::min();

	int min1=numeric_limits<int>::max();

	int min2=numeric_limits<int>::max();

	for(const auto & number : nums)
	{
		if(number > max1)
		{
			max3=max2;

			max2=max1;

			max1=number;
		}
		else if(number > max2)
		{
			max3=max2;

			max2=number;
		}
		else if(number > max3)
		{
			max3=number;
		}

		if(number < min1)
		{
			min2=min1;

			min1=number;
		}
		else if(number < min2)
		{
			min2=number;
		}
	}

	return max((max1 * max2 * max3), (max1 * min1 * min2));
}