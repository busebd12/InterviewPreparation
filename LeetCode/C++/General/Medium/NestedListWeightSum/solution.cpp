#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the total number of integers in nestedList]
Space complexity: O(d + n) [where d is the maximum depth of nestedList]
*/

class Solution
{
    public:
        int depthSum(vector<NestedInteger> & nestedList)
        {
            int result=0;

            deque<pair<NestedInteger, int>> stack;

            for(auto element : nestedList)
            {
                stack.emplace_back(element, 1);
            }

            while(!stack.empty())
            {
                auto [object, depth]=stack.back();

                stack.pop_back();

                if(object.isInteger())
                {
                    result+=(object.getInteger() * depth);
                }
                else
                {
                    for(auto element : object.getList())
                    {
                        stack.emplace_back(element, depth + 1);
                    }
                }
            }

            return result;
        }
};