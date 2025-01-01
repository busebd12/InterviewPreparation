#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(c log c) [where c is the length of costs]
Space complexity: O(sort) [where sort=recursive stack space needed for the sorting algorithm]
*/

class Solution
{
    public:
        int maxIceCream(vector<int> & costs, int coins)
        {
            int result=0;

            //Sort costs in increasing order
            sort(costs.begin(), costs.end());

            //If the lowest cost is too expensive, then we can't buy any ice cream :(
            if(costs[0] > coins)
            {
                return result;
            }

            //Iterate through costs
            for(int cost : costs)
            {
                //If we can afford this ice cream
                if(cost <= coins)
                {
                    coins-=cost;

                    result+=1;
                }
                //Can't affort this ice cream so break :(
                else
                {
                    break;
                }
            }

            return result;
        }
};