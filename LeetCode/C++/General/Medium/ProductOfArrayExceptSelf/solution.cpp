#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> & nums)
        {
            vector<int> result;
            
            int n=nums.size();
            
            result.resize(n);
            
            vector<int> leftToRightPrefixProducts(n, 0);
            
            leftToRightPrefixProducts[0]=1;
            
            for(int i=1;i<n;i++)
            {
                leftToRightPrefixProducts[i]=nums[i - 1] * leftToRightPrefixProducts[i - 1];
            }
            
            vector<int> rightToLeftPrefixProducts(n, 0);
            
            rightToLeftPrefixProducts[n - 1]=1;
            
            for(int i=n-2;i>=0;i--)
            {
                rightToLeftPrefixProducts[i]=nums[i + 1] * rightToLeftPrefixProducts[i + 1];
            }
            
            for(int i=0;i<n;i++)
            {
                result[i]=(leftToRightPrefixProducts[i] * rightToLeftPrefixProducts[i]);
            }
            
            return result;
        }
};