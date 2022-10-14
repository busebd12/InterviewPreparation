#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int partitionDisjoint(vector<int> & nums)
        {
            int result=-1;

            int n=nums.size();

            vector<int> maxToTheLeft(n, 0);

            maxToTheLeft[0]=nums[0];

            for(int i=1;i<n;i++)
            {
                int currentMax=max(maxToTheLeft[i - 1], nums[i]);

                maxToTheLeft[i]=currentMax;
            }

            vector<int> minToTheRight(n, 0);

            minToTheRight[n - 1]=nums[n - 1];

            for(int i=n-2;i>=0;i--)
            {
                int currentMin=min(minToTheRight[i + 1], nums[i]);

                minToTheRight[i]=currentMin;
            }

            int i=0;

            while(i < n-1 and maxToTheLeft[i] > minToTheRight[i + 1])
            {
                i+=1;
            }

            result=i + 1;

            return result;
        }
};