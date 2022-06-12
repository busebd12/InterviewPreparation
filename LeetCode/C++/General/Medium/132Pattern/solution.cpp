#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/132-pattern/discuss/1418970/C%2B%2B-Solution-using-Ordered-Set-and-Binary-Search-Time-O(nlogn)

Time complexity: O(n + (n log n)) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool find132pattern(vector<int>& nums)
        {
            int n=nums.size();
            
            vector<int> leftMinimums(n, 0);
            
            leftMinimums[0]=nums[0];
            
            for(int i=1;i<n;i++)
            {
                leftMinimums[i]=min(nums[i], leftMinimums[i - 1]);
            }
            
            set<int> hashset;
            
            for(int i=n-1;i>=1;i--)
            {
                int one=leftMinimums[i - 1];
                
                int three=nums[i];
                
                if(one < three)
                {
                    auto itr=hashset.upper_bound(one);
                    
                    if(itr!=end(hashset))
                    {
                        int two=*itr;
                        
                        if(three > two)
                        {
                            return true;
                        }
                    }
                }
                
                hashset.insert(three);
            }
            
            return false;
        }
};