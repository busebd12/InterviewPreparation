#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: based on the following resources

1) Video --> https://www.youtube.com/watch?v=GSBLe8cKu0s

2) Blog post --> https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/?page=2

Time complexity: O(n + (n * log(n)) + (n * log(n))) [where n is the length of buildings]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<vector<int>> getSkyline(vector<vector<int>> & buildings)
        {
            vector<vector<int>> result;

            vector<pair<int, int>> points; //O(2 * n)

            for(vector<int> & building : buildings) //O(n)
            {
                int x=building[0];

                int y=building[1];

                int height=building[2];

                points.emplace_back(x, -height);

                points.emplace_back(y, height);
            }

            sort(points.begin(), points.end()); //O(n * log(n))

            multiset<int> maxHeap={0};

            int previousMaxHeight=0;

            for(auto & [currentPoint, height] : points) //O(2 * n)
            {
                if(height < 0)
                {
                    maxHeap.insert(-height); //O(log(n))
                }
                else
                {
                    auto itr=maxHeap.find(height); //O(log(n));

                    maxHeap.erase(itr); //O(log(n))
                }

                int currentMaxHeight=*(maxHeap.rbegin());

                if(previousMaxHeight!=currentMaxHeight)
                {
                    result.emplace_back(vector<int>{currentPoint, currentMaxHeight});

                    previousMaxHeight=currentMaxHeight;
                }
            }

            return result;
        }
};