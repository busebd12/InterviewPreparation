#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the total number of integers in nestedList]
Space complexity: O(d + n) [where d is the maximum depth of nestedList]
*/

class Solution
{
    public:
        int depthSumInverse(vector<NestedInteger>& nestedList)
        {
            int result=0;

            unordered_multimap<int, int> integerToDepth;

            int maxDepth=0;

            deque<pair<NestedInteger, int>> stack;

            //All initial elements in nestedList have depth of 1
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
                    //Map the integer to its depth
                    integerToDepth.emplace(object.getInteger(), depth);

                    //Update the maxDepth
                    maxDepth=max(maxDepth, depth);
                }
                else
                {
                    for(auto element : object.getList())
                    {
                        stack.emplace_back(element, depth + 1);
                    }
                }
            }

            for(auto & [integer, depth] : integerToDepth)
            {
                int weight=(maxDepth - depth) + 1;

                result+=(integer * weight);
            }

            return result;
        }
};