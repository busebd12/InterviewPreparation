#include <unordered_map>
#include <vector>

/*
Solution: see comments

Time complexity: O(n + u) [where n is the length of nums and u is the number of unique numbers in nums]
Space complexity: O(u)
*/

class Solution
{
    public:
        int findPairs(vector<int> & nums, int k)
        {
            int result=0;
            
            //Map each number to its frequency
            unordered_map<int, int> hashtable;
            
            int n=nums.size();
            
            //Create frequency mappings
            for(int i=0;i<n;i++)
            {
                int value=nums[i];
                
                hashtable[value]+=1;
            }
            
            for(auto & [key, frequency] : hashtable)
            {
                //If k is zero, then we need at least two of the current number
                if(k==0)
                {
                    if(frequency > 1)
                    {
                        result+=1;
                    }
                }
                else
                {
                    
                    //In order to for a number x to form a valid pair, both x and x+k must be in the array
                    int target=key + k;
                    
                    //if target is in the hashtable
                    if(hashtable.count(target))
                    {
                        result+=1;
                    }
                }
            }
            
            return result;
        }
};