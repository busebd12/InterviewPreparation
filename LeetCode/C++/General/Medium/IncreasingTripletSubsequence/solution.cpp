#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        bool increasingTriplet(vector<int> & nums)
        {
            int n=nums.size();

            int first=numeric_limits<int>::max();

            int second=numeric_limits<int>::max();

            for(int number : nums)
            {
                if(number <= first)
                {
                    first=number;
                }
                else if(number <= second)
                {
                    second=number;
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
};