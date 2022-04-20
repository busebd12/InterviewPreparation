#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minMoves(vector<int>& nums)
        {
            int result=0;

            int minNumber=*(min_element(begin(nums), end(nums)));

            //Instead of trying to increment n-1 numbers till their equal, we can just decrement n-1 numbers until they are equal to a single number
            //The question is, which number do we pick? The answer is the minimum value
            for(auto number : nums)
            {
                result+=(number - minNumber);
            }

            return result;
        }
};