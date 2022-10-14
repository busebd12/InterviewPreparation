#include <vector>
using namespace std;
/*
Solution: inspired by these posts

1) https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1999083/C%2B%2B-oror-Binary-Search-oror-With-Explanation
2) https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064497/Unravel-it-Layer-by-Layer

Time complexity: O(n log n) [where n is the length of nums]
Space complexity: O(1)
*/
class Solution
{
    public:
        int minimumSize(vector<int> & nums, int maxOperations)
        {
            int result=0;
            
            int low=1;
            
            int high=1e9;
            
            while(low <= high)
            {
                int middle=(low + (high - low)/2);
                
                if(helper(nums, maxOperations, middle)==true)
                {
                    result=middle;
                    
                    high=middle - 1;
                }
                else
                {
                    low=middle + 1;
                }
            }
            
            return result;
        }
    
        bool helper(vector<int> & nums, int maxOperations, int ballsPerBag)
        {
            int splits=0;
            
            for(int & number : nums)
            {
                splits+=(number / ballsPerBag);
                
                if((number % ballsPerBag)==0)
                {
                    splits-=1;
                }
            }
            
            return splits <= maxOperations;
        }
};