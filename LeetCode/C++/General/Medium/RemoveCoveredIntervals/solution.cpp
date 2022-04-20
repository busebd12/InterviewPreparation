#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/remove-covered-intervals/discuss/451420/C%2B%2B-O(nlogn-%2B-n)-solution-with-explanation

Time complexity: O(n log n) [where n is the length of intervals]
Space complexity: O(1)
*/

class Solution
{
    public:
        int removeCoveredIntervals(vector<vector<int>> & intervals)
        {
            int n=intervals.size();
            
            int result=n;
            
            auto comparator=[] (auto & i1, auto & i2)
            {
                if(i1[0]!=i2[0])
                {
                    return i1[0] < i2[0];
                }
                else
                {
                    return i1[1] > i2[1];
                }
            };
            
            sort(begin(intervals), end(intervals), comparator);
            
            int end=intervals[0][1];
            
            for(int i=1;i<n;i++)
            {
                int currentEnd=intervals[i][1];
                
                if(end >= currentEnd)
                {
                    result-=1;
                }
                else
                {
                    end=currentEnd;
                }
            }
            
            return result;
        }
};