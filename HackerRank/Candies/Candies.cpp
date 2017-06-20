#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

void candies(vector<int> Ratings)
{
	size_t ratingsSize=Ratings.size();

	if(ratingsSize==0)
	{
		cout << 1 << endl;
	}
	else
	{
		vector<int> numberOfCandies(ratingsSize, 1);

		for(int index=1;index<ratingsSize;++index)
		{
			//if the rating of the current child is greater than the rating of the child before
			if(Ratings[index] > Ratings[index-1])
			{
				//give one more candie to the current child
				numberOfCandies[index]=numberOfCandies[index-1]+1;
			}
		}

		for(int spot=ratingsSize-1;spot>0;--spot)
		{
			if(Ratings[spot-1] > Ratings[spot])
			{
				numberOfCandies[spot-1]=max(numberOfCandies[spot]+1, numberOfCandies[spot-1]);
			}
		}

		int result=0;

		for(int index=0;index<ratingsSize;++index)
		{
			result+=numberOfCandies[index];
		}

		cout << result << endl;
	}
}

int main()
{
	vector<int> ratings={1, 2, 2};

	candies(ratings);
}