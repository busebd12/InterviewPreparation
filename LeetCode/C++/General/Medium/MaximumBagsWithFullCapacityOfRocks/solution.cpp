#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (n * log(n))) [where n is the length of capacity and rocks]
Space complexity: O(n + log(n)) [std::sort uses log(n) space]
*/

class Solution
{
    public:
        int maximumBags(vector<int> & capacity, vector<int> & rocks, int additionalRocks)
        {
            int result=0;

            int n=capacity.size();

            vector<pair<int, int>> pairs;

            for(int i=0;i<n;i++)
            {
                int remainingCapacity=capacity[i] - rocks[i];

                pairs.emplace_back(remainingCapacity, i);
            }

            sort(pairs.begin(), pairs.end(), less<pair<int, int>>());

            for(auto & [remainingCapacity, index] : pairs)
            {
                if(additionalRocks >= remainingCapacity)
                {
                    additionalRocks-=remainingCapacity;
                    
                    remainingCapacity-=remainingCapacity;
                }
            }

            for(auto & [remainingCapacity, index] : pairs)
            {   
                if(remainingCapacity==0)
                {
                    result+=1;
                }
            }

            return result;
        }
};