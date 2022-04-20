#include <vector>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int findDuplicate(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            //Keep track of whether we've seen the number already
            vector<bool> seen(n + 1, false);
            
            for(auto number : nums)
            {
                //First time seeing the number
                if(seen[number]==false)
                {
                    seen[number]=true;
                }
                //Else, we seen this number before and it's the duplicate number
                else
                {
                    result=number;
                    
                    break;
                }
            }
            
            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int findDuplicate(vector<int> & nums)
        {   
            int result=0;
            
            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
                int index=abs(nums[i]) - 1;
                
                //Mark as visited  
                nums[index]*=-1;
                
                //If nums[index] becomes positive, then we know that we've seen nums[i] at least twice
                if(nums[index] > 0)
                {
                    result=abs(nums[i]);
                    
                    break;
                }
            }
            
            return result;
        }
};