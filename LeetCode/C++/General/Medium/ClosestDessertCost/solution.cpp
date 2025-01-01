#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/*
Time complexity: O(n * 3^m) [where n is the length of baseCosts and m is the length of toppingCosts]
Space complexity: O(m)
*/

class Solution
{
    public:
        int closestCost(vector<int> & baseCosts, vector<int> & toppingCosts, int target)
        {
            int result=0;

            int m=toppingCosts.size();

            for(int baseCost : baseCosts)
            {
                int cost=baseCost;

                int index=0;
                
                int costWithCurrentBase=helper(toppingCosts, m, target, cost, index);

                result=closest(target, result, costWithCurrentBase);
            }

            return result;
        }

        int helper(vector<int> & toppingCosts, int m, int target, int cost, int index)
        {
            if(index==m)
            {
                return cost;
            }

            int subproblemSolution=0;

            //Pick one of the current topping
            int pickOne=helper(toppingCosts, m, target, cost + toppingCosts[index], index + 1);

            //Pick two of the current topping
            int pickTwo=helper(toppingCosts, m, target, cost + (toppingCosts[index] * 2), index + 1);

            //Skip the current topping
            int pickNone=helper(toppingCosts, m, target, cost, index + 1);

            //Find the closest cost out of all three options for the current topping
            subproblemSolution=closest(target, pickOne, closest(target, pickTwo, pickNone));

            return subproblemSolution;
        }

        int closest(int target, int cost1, int cost2)
        {
            if(cost1==0)
            {
                return cost2;
            }

            if(cost2==0)
            {
                return cost1;
            }

            int closestCost=0;

            int cost1Difference=abs(target - cost1);

            int cost2Difference=abs(target - cost2);

            if(cost1Difference==cost2Difference)
            {
                closestCost=min(cost1, cost2);
            }
            else
            {
                if(cost1Difference > cost2Difference)
                {
                    closestCost=cost2;
                }
                else
                {
                    closestCost=cost1;
                }
            }

            return closestCost;
        }
};