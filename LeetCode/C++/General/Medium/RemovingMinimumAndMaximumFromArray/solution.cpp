#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minimumDeletions(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int minIndex=getMinIndex(nums, n);

            int maxIndex=getMaxIndex(nums, n);

            int smallerIndex=min(minIndex, maxIndex);

            int largerIndex=max(minIndex, maxIndex);

            int removeFromFront=(largerIndex - 0) + 1;

            int removeFromBack=(n - 1 - smallerIndex) + 1;

            int removeSmallerFromFront=(smallerIndex - 0) + 1;

            int removeLargerFromBack=(n - 1 - largerIndex) + 1;

            int removeFromBackAndFront=removeSmallerFromFront + removeLargerFromBack;

            result=min(min(removeFromFront, removeFromBack), removeFromBackAndFront);

            return result;
        }

        int getMinIndex(vector<int> & nums, int n)
        {
            int minValue=nums[0];

            int minIndex=0;

            for(int i=1;i<n;i++)
            {
                if(nums[i] < minValue)
                {
                    minValue=nums[i];

                    minIndex=i;
                }
            }

            return minIndex;
        }

        int getMaxIndex(vector<int> & nums, int n)
        {
            int maxValue=nums[0];

            int maxIndex=0;

            for(int i=1;i<n;i++)
            {
                if(nums[i] > maxValue)
                {
                    maxValue=nums[i];

                    maxIndex=i;
                }
            }

            return maxIndex;
        }
};