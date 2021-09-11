#include <iostream>
#include <vector>

/*
 * Solution: the algorithm operates as follows
 *
 * 1. Find the index in the intervals where we want to insert the new interval. Edge cases to be aware of are either
 * the intervals are empty or the new interval is larger than every other interval. In both of these cases, we insert
 * the new interval at the end of the intervals.
 *
 * 2. Merge the intervals to eliminate redundant intervals.
 *
 * 3. Return the merged intervals.
 *
 * Time complexity: O(n) [where n is the length of intervals]
 * Space complexity: O(m) [where m is the number of merged intervals]
 *
 */

class Solution
{
    public:

        std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>> & intervals)
        {
            std::vector<std::vector<int>> result;

            if(intervals.empty())
            {
                return result;
            }

            int n=int(intervals.size());

            int start=intervals[0][0];

            int end=intervals[0][1];

            for(int i=1;i<n;++i)
            {
                if(intervals[i][0] <= end && end <= intervals[i][1])
                {
                    end=intervals[i][1];
                }
                else if(start <= intervals[i][1] && intervals[i][1] <= end)
                {
                    continue;
                }
                else
                {
                    std::vector<int> interval={start, end};

                    result.push_back(interval);

                    start=intervals[i][0];

                    end=intervals[i][1];
                }
            }

            std::vector<int> interval={start, end};

            result.push_back(interval);

            return result;
        }


        std::vector<std::vector<int>> insert(std::vector<std::vector<int>> & intervals, std::vector<int> & newInterval)
        {
            int insertionIndex=-1;

            int n=int(intervals.size());

            for(int i=0;i<n;i++)
            {
                if(intervals[i][0] > newInterval[0])
                {
                    insertionIndex=i;

                    break;
                }
            }

            if(insertionIndex==-1)
            {
                intervals.insert(intervals.end(), newInterval);

                insertionIndex=int(intervals.size()-1);
            }

            if(insertionIndex-1 >= 0 && intervals[insertionIndex - 1][0]==newInterval[0])
            {
                if(intervals[insertionIndex - 1][1] > newInterval[1])
                {
                    insertionIndex-=1;
                }
            }

            intervals.insert(intervals.begin() + insertionIndex, newInterval);

            auto merged=mergeIntervals(intervals);

            return merged;
        }
};