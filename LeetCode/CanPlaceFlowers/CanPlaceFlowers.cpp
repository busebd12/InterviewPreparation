#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int> & flowerbed, int n)
{
	if(flowerbed.empty() || n < 0)
	{
		return false;
	}

	const size_t flowerbedSize=flowerbed.size();

	for(int index=0;index<flowerbedSize;++index)
	{
		if(n > 0)
		{
			if(flowerbed[index]==0)
			{
				if(index==0)
				{
					if(flowerbed[index+1]==0)
					{
						flowerbed[index]=1;

						--n;
					}
				}
				else if(index==flowerbedSize-1)
				{
					if(flowerbed[index-1]==0)
					{
						flowerbed[index]=1;

						--n;
					}
				}
				else
				{
					if(flowerbed[index-1]==0 && flowerbed[index+1]==0)
					{
						flowerbed[index]=1;

						--n;
					}
				}
			}
		}
	}

	return n==0;
}