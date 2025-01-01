#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n=length of nums]
Space complexity: O(2n) => O(n)
*/

class Solution
{
    public:
        vector<int> getConcatenation(vector<int> & nums)
        {
            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
                nums.push_back(nums[i]);
            }

            return nums;
        }
};

class Solution
{
    public:
        vector<int> getConcatenation(vector<int> & nums)
        {
            vector<int> result;
            
            int n=nums.size();

            int N=2 * n;
            
            result.resize(N);

            int low=0;

            int middle=n;

            int high=N;

            for(int i=low;i<middle;i++)
            {
                result[i]=nums[i];
            }

            for(int i=middle;i<high;i++)
            {
                result[i]=nums[i - n];
            }

            return result;
        }
};