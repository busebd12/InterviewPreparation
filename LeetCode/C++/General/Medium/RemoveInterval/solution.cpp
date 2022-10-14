#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/remove-interval/discuss/939928/Simple-Python-Solution

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved)
        {
            vector<vector<int>> result;
            
            for(vector<int> interval : intervals)
            {
                int start=interval[0];
                
                int end=interval[1];
                
                if(start < toBeRemoved[0])
                {
                    result.emplace_back(vector<int>{start, min(end, toBeRemoved[0])});
                }
                
                if(end > toBeRemoved[1])
                {
                    result.emplace_back(vector<int>{max(start, toBeRemoved[1]), end});
                }
            }
            
            return result;
        }
};

/*
Solution: inspired by this post --> https://leetcode.com/problems/remove-interval/discuss/939928/Simple-Python-Solution

Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
    public:
        vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved)
        {
            vector<vector<int>> result;
            
            for(vector<int> interval : intervals)
            {   
                int start=interval[0];
                
                int end=interval[1];
                
                int intersectionStart=max(start, toBeRemoved[0]);
                
                int intersectionEnd=min(end, toBeRemoved[1]);
                
                if(intersectionEnd <= intersectionStart)
                {
                    result.emplace_back(vector<int>{start, end});
                }
                else
                {
                    if(start < intersectionStart)
                    {
                        result.emplace_back(vector<int>{start, intersectionStart});
                    }

                    if(end > intersectionEnd)
                    {
                        result.emplace_back(vector<int>{intersectionEnd, end});
                    }
                }
            }
            
            return result;
        }
};