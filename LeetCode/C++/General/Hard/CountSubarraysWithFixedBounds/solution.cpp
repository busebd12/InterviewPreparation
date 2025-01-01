#include <algorithm>
#include <deque>
using namespace std;

/*
Solution: inspired by this explanation --> https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/2763355/queue-approach-o-n-easy-intuition/

Time complexity: O(n) [where n=length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long countSubarrays(vector<int> & nums, int minK, int maxK)
        {
            long long result=0;

            deque<int> queue;

            int minKIndex=-1;

            int maxKIndex=-1;

            for(int number : nums)
            {
                if(minK <= number and number <= maxK)
                {
                    queue.push_back(number);

                    if(number==minK)
                    {
                        minKIndex=queue.size();
                    }

                    if(number==maxK)
                    {
                        maxKIndex=queue.size();
                    }

                    if(minKIndex!=-1 and maxKIndex!=-1)
                    {
                        result+=min(minKIndex, maxKIndex);
                    }
                }
                else
                {
                    queue.clear();

                    minKIndex=-1;

                    maxKIndex=-1;
                }
            }

            return result;
        }
};