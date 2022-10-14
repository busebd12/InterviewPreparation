#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> constructDistancedSequence(int n)
        {
            vector<int> result;

            int duplicates=(n - 1) * 2;

            int length=duplicates + 1;

            result.resize(length, -1);
            
            unordered_set<int> nums;
            
            for(int number=1;number<=n;number++)
            {
                nums.insert(number);
            }

            int index=0;

            helper(result, nums, n, index);
            
            return result;
        }

        bool helper(vector<int> & result, unordered_set<int> & nums, int n, int index)
        {
            if(nums.empty())
            {
                return true;
            }

            if(result[index]!=-1)
            {
                return helper(result, nums, n, index + 1);
            }

            for(int number=n;number>0;number--)
            {
                int offset=(number==1) ? 0 : number;

                int right=index + offset;

                if(nums.find(number)!=nums.end() and (right < result.size() and result[right]==-1))
                {
                    result[index]=number;

                    result[right]=number;

                    nums.erase(number);

                    if(helper(result, nums, n, index + 1)==true)
                    {
                        return true;
                    }

                    nums.insert(number);

                    result[index]=-1;

                    result[right]=-1;
                }
            }

            return false;
        }
};