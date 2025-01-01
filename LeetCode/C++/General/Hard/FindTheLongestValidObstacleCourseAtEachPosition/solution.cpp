#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/solutions/3494672/c-best-solution-upper-bound-easy-to-understand/
*/

class Solution
{
    public:
        vector<int> longestObstacleCourseAtEachPosition(vector<int> & obstacles)
        {
            vector<int> result;

            int n=obstacles.size();

            result.resize(n, -1);

            vector<int> upperBounds(n, numeric_limits<int>::max());

            for(int i=0;i<n;i++)
            {   
                auto upperBoundItr=upper_bound(upperBounds.begin(), upperBounds.end(), obstacles[i]);

                int upperBoundIndex=upperBoundItr - upperBounds.begin();

                int length=upperBoundIndex + 1;

                result[i]=length;

                upperBounds[upperBoundIndex]=obstacles[i];
            }

            return result;
        }
};