#include <numeric>
#include <unordered_map>
#include <vector>

/*
Solution 1: see comments.

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the total unique values in nums]
*/

class Solution
{
    public:
        vector<int> findDuplicates(vector<int> & nums)
        {
            vector<int> result;

            //Map each number to its frequency within nums
            unordered_map<int, int> frequencies;

            //Create frequency mappings
            for(auto number : nums)
            {
                frequencies[number]++;
            }

            //Iterate through frequencies
            for(const auto & [number, frequency] : frequencies)
            {
                //If number appears twice in nums
                if(frequency==2)
                {
                    result.emplace_back(number);
                }
            }

            return result;
        }
};

/*
Solution 2: inspired from this post --> https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c%2B%2B-Four-Solution-or-O-(N*N)-to-greater-O(N)-or-Explain-All

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/
class Solution
{
    public:
        vector<int> findDuplicates(vector<int> & nums)
        {
            vector<int> result;

            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
                int number=nums[i];
                
                if(nums[abs(number) - 1] < 0)
                {
                    result.emplace_back(abs(number));
                }
                else
                {
                    nums[abs(number) - 1]=-nums[abs(number) - 1];
                }
            }

            return result;
        }
};