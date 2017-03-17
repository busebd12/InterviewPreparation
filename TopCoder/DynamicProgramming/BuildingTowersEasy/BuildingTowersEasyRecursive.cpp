#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class BuildingTowersEasy
{
	public:
		vector<int> maxHeight(vector<int> DP, vector<int> MaxValues, int Index)
		{
			if(Index==DP.size()-1)
			{
				MaxValues.emplace_back(*(max_element(begin(DP), end(DP))));
			}
			else if(Index < DP.size()-1)
			{
				if(DP[Index]==0 && Index!=0)
				{
					if(DP[Index-1] >= 1)
					{
						vector<int> dpWithOneGreater(begin(DP), end(DP));

						dpWithOneGreater[Index]=DP[Index-1]+1;

						vector<int> dpWithSame(begin(DP), end(DP));

						dpWithSame[Index]=DP[Index-1];

						vector<int> dpWithOneLess(begin(DP), end(DP));

						dpWithOneLess[Index]=DP[Index-1]-1;

						int indexWithGreater=Index++;

						int indexWithSame=Index++;

						int indexWithLess=Index++;

						return maxHeight(dpWithOneGreater, MaxValues, indexWithGreater);

						return maxHeight(dpWithSame, MaxValues, indexWithSame);

						return maxHeight(dpWithOneLess, MaxValues, indexWithLess);
					}
					else if(DP[Index-1]==0)
					{
						vector<int> dpWithOneGreater(begin(DP), end(DP));

						dpWithOneGreater[Index]=DP[Index-1]+1;

						vector<int> dpWithSame(begin(DP), end(DP));

						dpWithSame[Index]=DP[Index-1];

						int indexWithGreater=Index++;

						int indexWithSame=Index++;

						return maxHeight(dpWithOneGreater, MaxValues, indexWithGreater);

						return maxHeight(dpWithSame, MaxValues, indexWithSame);
					}
				}
				else
				{
					Index++;

					return maxHeight(DP, MaxValues, Index);
				}
			}

			return MaxValues;
		}

		int maxHeightHelper(int NumberOfBuildings, vector<int> Buildings, vector<int> Heights)
		{
			vector<int> dp;

			dp.resize(NumberOfBuildings);

			for(int index=0;index<Buildings.size();++index)
			{
				int building=Buildings[index];

				dp[building-1]=Heights[index];
			}

			vector<int> maxValues;

			int index{};

			maxValues=maxHeight(dp, maxValues, index);

			return *(max_element(begin(maxValues), end(maxValues)));
		}
};