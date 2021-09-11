#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach: First we need to sort the heaters array. We need to check the position of the house in the heater array,
which can be done by binary search. In this process, we can get the minimum radius needed for this house.
Then for all the houses, we pick the largest minimum radius such that this radius can cover all the houses.

Time complexity: O(n log n + m log m) [where n is the size of the heaters vector and m is the size of the houses vector]
Space complexity: O(1)
*/

int findMinimumRadius(vector<int> & heaters, int house)
{
    int result=numeric_limits<int>::max();

    int low=0;

    int high=int(heaters.size())-1;

    while(low <= high)
    {
        int middle=(low + ((high - low)/2));

        if(heaters[middle]==house)
        {
            return 0;
        }
        else if(heaters[middle] > house)
        {
            result=min(result, heaters[middle]-house);

            high=middle-1;
        }
        else
        {
            result=min(result, house-heaters[middle]);

            low=middle+1;
        }
    }

    return result;
}

int findRadius(vector<int> & houses, vector<int> & heaters)
{
    if(houses.empty() || heaters.empty())
    {
        return 0;
    }

    sort(heaters.begin(), heaters.end());

    int result=0;

    for(int house : houses)
    {
        result=max(result, findMinimumRadius(heaters, house));
    }

    return result;
}