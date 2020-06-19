#include <iostream>
#include <vector>

/*
 * Solution: for each index i in the cost vector where cost[i] is less than the amount of gas, gas[i], we choose
 * this index as our starting spot and try to move in a circle back to this starting spot. If any of these indices
 * allow us to do this, that particular index is our answer. If none do, then we return -1.
 *
 * Time complexity: O(n^2) [where n is the size of the gas and cost vectors]
 * Space complexity: O(n) [recursive stack space]
 */

class Solution
{
    public:

        bool dfs(std::vector<int> & gas, std::vector<int> & cost, int n, int tank, bool flag, int start, int index)
        {
            if(cost[index] > tank)
            {
                return false;
            }

            if(index==start && flag)
            {
                return true;
            }

            if(!flag)
            {
                flag=true;
            }

            tank-=cost[index];

            if(index + 1 < n)
            {
                tank+=gas[index + 1];

                index+=1;
            }
            else
            {
                tank+=gas[0];

                index=0;
            }

            return dfs(gas, cost, n, tank, flag, start, index);
        }

        int canCompleteCircuit(std::vector<int> & gas, std::vector<int> & cost)
        {
            int n=int(gas.size());

            if(n==1)
            {
                if(gas[0] < cost[0])
                {
                    return -1;
                }
                else
                {
                    return 0;
                }
            }

            for(int i=0;i<n;i++)
            {
                if(cost[i] < gas[i])
                {
                    int index=i;

                    bool flag=false;

                    int tank=gas[i];

                    if(dfs(gas, cost, n, tank, flag, i, index))
                    {
                        return i;
                    }
                }
            }

            return -1;
        }
};