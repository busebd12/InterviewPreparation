#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/discuss/1959067/C%2B%2B-solution

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(s) [where s is the total number of prefix sums]
*/

class Solution
{
    public:
        int maxSubArrayLen(vector<int> & nums, int k)
        {
            int result=0;
            
            size_t n=nums.size();
            
            unordered_map<size_t, size_t> sumToIndex;
            
            size_t sum=0;
            
            for(size_t i=0;i<n;i++)
            {
                sum+=nums[i];
                
                if(sum==k)
                {
                    result=i + 1;
                }
                else
                {
                    size_t remaining=sum - k;
                    
                    if(sumToIndex.find(remaining)!=end(sumToIndex))
                    {
                        int length=(i - (sumToIndex[remaining] + 1)) + 1;
                        
                        result=max(result, length);
                    }
                }
                
                if(sumToIndex.find(sum)==end(sumToIndex))
                {
                    sumToIndex[sum]=i;
                }
            }
            
            return result;
        }
};