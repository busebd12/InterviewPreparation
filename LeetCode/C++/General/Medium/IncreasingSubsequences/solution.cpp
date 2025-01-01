#include <set>
#include <vector>
using namespace std;

/*
Solution: recursion + backtracking

Time complexity: O(n * 2^n)
Space complexity: O(n * 2^n)
*/

class Solution
{
    public:
        vector<vector<int>> findSubsequences(vector<int> & nums)
        {
            vector<vector<int>> result;

            int n=nums.size();

            int start=0;

            set<vector<int>> unique;

            vector<int> subsequence;

            helper(nums, unique, subsequence, n, start);

            for(const vector<int> & uniqueSubsequence : unique)
            {
                result.push_back(uniqueSubsequence);
            }

            return result;
        }

        void helper(vector<int> & nums, set<vector<int>> & unique, vector<int> & subsequence, int n, int start)
        {
            if(subsequence.size() > 1)
            {
                unique.insert(subsequence);
            }
            
            if(start==n)
            {
                return;
            }

            for(int index=start;index<n;index++)
            {
                if(subsequence.empty() or nums[index] >= subsequence.back())
                {
                    subsequence.push_back(nums[index]);

                    helper(nums, unique, subsequence, n, index + 1);
                    
                    subsequence.pop_back();
                }
            }
        }
};