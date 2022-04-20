#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this video --> https://www.youtube.com/watch?v=nSEO5zOwP7g

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique sums in nums]
*/

class Solution
{
    public:
        int findMaxLength(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            unordered_map<int, int> hashtable;
            
            hashtable[0]=-1;
            
            int sum=0;
            
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    sum-=1;
                }
                else
                {
                    sum+=1;
                }
                
                if(hashtable.find(sum)!=end(hashtable))
                {
                    result=max(result, i - hashtable[sum]);
                }
                else
                {
                    hashtable[sum]=i;
                }
            }
            
            return result;
        }
};