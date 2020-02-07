#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution: first we sort the given intervals in increasing order by the beginning of each interval.
 * Then, we iterate through the sorted intervals and merge two intervals if either of the endings fit
 * in between the start and end of the other interval. If this is not the case, then we add the interval
 * we have to the vector<vector<int>> result.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1) if we are not counting space allocated for the return result. O(m) [where m is the number of merged intervals] otherwise.
 */

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> & intervals)
{
    std::vector<std::vector<int>> result;

    if(intervals.empty())
    {
        return result;
    }

    int n=int(intervals.size());

    std::sort(intervals.begin(), intervals.end());

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