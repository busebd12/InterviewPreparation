#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: based on this resource --> https://www.youtube.com/watch?v=zx5Sw9130L0

Time complexity: O(h) [where h=length of heights]
Space complexity: O(h)
*/

class Solution
{
    public:
        int largestRectangleArea(vector<int> & heights)
        {
            int result=0;

            int maxAreaSoFar=0;

            int h=heights.size();

            deque<pair<int, int>> stack;

            for(int i=0;i<h;i++)
            {
                int startIndex=i;
                
                while(!stack.empty() and stack.back().second > heights[i])
                {
                    auto [index, height]=stack.back();

                    stack.pop_back();

                    int length=i - index;

                    int area=height * length;

                    maxAreaSoFar=max(maxAreaSoFar, area);

                    startIndex=index;
                }

                stack.emplace_back(startIndex, heights[i]);
            }

            while(!stack.empty())
            {
                auto [index, height]=stack.back();

                stack.pop_back();

                int length=h - index;

                int area=height * length;

                maxAreaSoFar=max(maxAreaSoFar, area);
            }

            result=maxAreaSoFar;

            return result;
        }
};