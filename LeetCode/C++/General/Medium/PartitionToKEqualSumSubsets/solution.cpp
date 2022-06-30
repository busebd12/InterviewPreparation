#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/1020520/Java-A-Thorough-Summary%3A-Two-DFS-and-one-DPBFS-solutions
*/

class Solution
{
    public:
        int dfs(vector<int> & nums, vector<int> & buckets, int targetSum, int index)
        {
            if(index < 0)
            {
                return true;
            }
            
            int number=nums[index];
            
            bool alreadyFilledABucket=false;
            
            for(int i=0;i<buckets.size();i++)
            {
                if(buckets[i] + number <= targetSum)
                {
                    alreadyFilledABucket=true;
                    
                    buckets[i]+=number;
                    
                    if(dfs(nums, buckets, targetSum, index - 1)==true)
                    {
                        return true;
                    }
                    
                    buckets[i]-=number;
                }
                
                if(buckets[i]==0 && alreadyFilledABucket==true)
                {
                    break;
                }
            }
            
            return false;
        }
    
        bool canPartitionKSubsets(vector<int> & nums, int k)
        {
            int n=nums.size();
            
            int total=accumulate(begin(nums), end(nums), 0);
            
            sort(begin(nums), end(nums));
            
            if((total % k)!=0)
            {
                return false;
            }
            
            int targetSum=total / k;
            
            if(targetSum < nums[0])
            {
                return false;
            }
            
            vector<int> buckets(k, 0);
            
            int index=n - 1;
            
            return dfs(nums, buckets, targetSum, index);
        }
};