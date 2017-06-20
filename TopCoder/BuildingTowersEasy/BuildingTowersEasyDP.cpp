#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class BuildingTowersEasy
{
	public:

		int maxHeight(vector<int> Buildings, vector<int> Heights, int NumberOfBuildings)
		{
			vector<int> dp;

			dp.resize(NumberOfBuildings);

			if(!Heights.empty() && !Buildings.empty())
			{
				for(int index=0;index<Buildings.size();++index)
				{
					int building=Buildings[index];

					dp[building-1]=Heights[index];
				}
			}

			size_t dpSize=dp.size();

			for(int index=0;index<dpSize;++index)
			{
				if(index==0 || dp[index] >= 1)
				{
					continue;
				}
				else
				{
					if(dp[index-1] >= 1)
					{
						dp[index]=max(max(dp[index-1]+1, dp[index-1]), max(dp[index-1], dp[index-1]-1));
					}
					else if(dp[index-1]==0)
					{
						dp[index]=max(dp[index-1]+1, dp[index-1]);
					}
				}
			}

			return *(max_element(begin(dp), end(dp)));
		}
};