#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n^2 + s * log(s)) [where n is the length of nums and s is the number of subarray sums]
Space complexity: O(n + s)
*/

class Solution
{
    public:
        int rangeSum(vector<int> & nums, int n, int left, int right)
        {
            int result=0;
            
            const int MOD=1e9 + 7;
    
            vector<int> prefixSums(n, 0);

            prefixSums[0]=nums[0];

            for(int i=1;i<n;i++)
            {
                prefixSums[i]=prefixSums[i - 1] + nums[i];
            }

            vector<int> subarraySums;

            for(int i=0;i<n;i++)
            {
                subarraySums.push_back(nums[i]);

                if(i==0)
                {
                    for(int j=i+1;j<prefixSums.size();j++)
                    {
                        subarraySums.push_back(prefixSums[j]);
                    }
                }
                else
                {
                    for(int j=i+1;j<prefixSums.size();j++)
                    {
                        int subarraySum=prefixSums[j] - prefixSums[i - 1];

                        subarraySums.push_back(subarraySum);
                    }
                }
            }

            sort(begin(subarraySums), end(subarraySums));

            for(int i=left-1;i<right;i++)
            {
                result+=subarraySums[i];
                
                result=result % MOD;
            }
            
            return result;
        }
};