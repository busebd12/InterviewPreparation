#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> insert(vector<vector<int>> & intervals, vector<int> & newInterval)
        {
            vector<vector<int>> result;
            
            int insertionIndex=-1;
            
            for(int i=1;i<intervals.size();i++)
            {
                if(intervals[i][0] >= newInterval[0] && intervals[i - 1][0] <= newInterval[0])
                {
                    insertionIndex=i;
                    
                    break;
                }
            }
            
            if(insertionIndex==-1)
            {
                if(intervals.empty())
                {
                    intervals.insert(begin(intervals), newInterval);
                }
                else
                {
                    if(newInterval[0] >= intervals[0][0])
                    {
                        intervals.push_back(newInterval);
                    }
                    else
                    {
                        intervals.insert(begin(intervals), newInterval);
                    }
                }
            }
            else
            {
                intervals.insert(begin(intervals) + insertionIndex, newInterval);
            }
            
            int intervalStart=intervals[0][0];
            
            int intervalEnd=intervals[0][1];
            
            for(int i=1;i<intervals.size();i++)
            {
                int currentIntervalStart=intervals[i][0];
                
                int currentIntervalEnd=intervals[i][1];
                
                if(currentIntervalStart <= intervalEnd)
                {
                    intervalStart=min(intervalStart, currentIntervalStart);
                    
                    intervalEnd=max(intervalEnd, currentIntervalEnd);
                }
                else
                {
                    result.emplace_back(vector<int>{intervalStart, intervalEnd});
                    
                    intervalStart=currentIntervalStart;
                    
                    intervalEnd=currentIntervalEnd;
                }
            }
            
            result.emplace_back(vector<int>{intervalStart, intervalEnd});
            
            return result;
        }
};