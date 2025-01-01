#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(k)
*/

class Solution
{
    public:
        vector<int> mostCompetitive(vector<int> & nums, int k)
        {
            vector<int> stack;

            int n=nums.size();

            for(int i=0;i<n;i++)
            {
                int number=nums[i];

                int remaining=n - i;
                
                while(!stack.empty() and stack.back() > number and (stack.size() - 1) + remaining >= k)
                {
                    stack.pop_back();
                }

                if(stack.size() < k)
                {
                    stack.push_back(number);
                }
            }

            return stack;
        }
};