#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this video --> https://www.youtube.com/watch?v=BgLVRkA8w6w

Time complexity: O(n * m) [where n is the length of nums1 and m is the length of nums2]
Space complexity: O(n * m)
*/

class Solution
{
    public:
        int findLength(vector<int> & nums1, vector<int> & nums2)
        {
            int result=0;
            
            int n=nums1.size();
            
            int m=nums2.size();
            
            vector<vector<int>> cache(n+1, vector<int>(m+1, 0));
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(nums1[i-1]==nums2[j-1])
                    {
                        cache[i][j]=1 + cache[i-1][j-1];
                    }
                    
                    result=max(result, cache[i][j]);
                }
            }
            
            return result;
        }
};