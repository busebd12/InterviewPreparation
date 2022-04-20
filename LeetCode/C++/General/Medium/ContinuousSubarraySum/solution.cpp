#include <unordered_map>
#include <vector>

/*
Solution 1: Brute force. Warning, this solution received Time Limit Exceeded when executed.

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution
{
    public:
        bool checkSubarraySum(vector<int> & nums, int k)
        {
            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
                int subarraySum=nums[i];
                
                for(int j=i+1;j<n;j++)
                {
                    subarraySum+=nums[j];
                    
                    if((subarraySum % k)==0)
                    {
                        int length=(j - i) + 1;
                        
                        if(length >= 2)
                        {
                            return true;
                        }
                    }
                }
            }
            
            return false;
        }
};

/*
Solution 2: inspired by these two posts

1. https://leetcode.com/problems/continuous-subarray-sum/discuss/474735/O(n)-solution-explained
2. https://leetcode.com/problems/continuous-subarray-sum/discuss/1374913/Easy-C%2B%2B-solution

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool checkSubarraySum(vector<int> & nums, int k)
        {
            unordered_map<int, int> hashtable;
            
            int n=nums.size();
            
            int sum=0;
            
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
                
                int remainder=sum % k;
                
                if(remainder==0 && i > 0)
                {
                    return true;
                }
                
                if(hashtable.find(remainder)!=end(hashtable))
                {
                    int length=(i - hashtable[remainder]);
                    
                    if(length >= 2)
                    {
                        return true;
                    }
                }
                else
                {
                    hashtable[remainder]=i;
                }
            }
            
            return false;
        }
};