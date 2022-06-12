#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int findMinArrowShots(vector<vector<int>> & points)
        {
            int result=0;
            
            int p=points.size();
            
            //Custom comparator for two points
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[0]==rhs[0])
                {
                    return lhs[1] < rhs[1];
                }
                else
                {
                    return lhs[0] < rhs[0];
                }
            };
            
            //Sort the points using the custom comparator
            sort(begin(points), end(points), compareLikeThis);
            
            //Since we are starting our intersection interval using the first point, increment result by one
            result=1;
            
            //Interval representing the intersection of all the points we seen so far
            int intersectionStart=points[0][0];
            
            int intersectionEnd=points[0][1];
            
            for(int i=1;i<p;i++)
            {
                int currentStart=points[i][0];
                
                int currentEnd=points[i][1];
                
                //If the current point does not intersect with any of the points we've seen so far, we'll need one more arrow to pop this balloon
                if(intersectionEnd < currentStart)
                {
                    intersectionStart=currentStart;
                    
                    intersectionEnd=currentEnd;
                    
                    result+=1;
                }
                //Else, the current point intersects with the other points and we need to re-calculate the intersection interval
                else
                {
                    intersectionStart=max(intersectionStart, currentStart);
                    
                    intersectionEnd=min(intersectionEnd, currentEnd);
                }
            }
            
            return result;
        }
};