#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution the idea is to sort all the intervals in increasing order by their end values.
 * Then, we assign a variable, end, with the value of the first interval's ending value.
 * Next, we iterate through the rest of the intervals and handle the following cases
 *
 * a. The current value of end is less than or equal to the starting value for the current interval.
 * If this is the case, then there is no overlap. So, just assign end the value of the current interval's
 * ending value.
 *
 * b. Else, end overlaps with the starting value of the current interval and we increment our result variable.
 *
 * Return the result after iterating through all the intervals.
 *
 * Time complexity: O(n * log(n))
 * Space complexity: O(1)
 */

int eraseOverlapIntervals(std::vector<std::vector<int>> & intervals)
{
    int result=0;

    if(intervals.size() <= 1)
    {
        return result;
    }

    int n=int(intervals.size());

    std::sort(intervals.begin(), intervals.end(), [] (const std::vector<int> & v1, const std::vector<int> & v2) {return v1[1] < v2[1];});

    int end=intervals[0][1];

    for(int i=1;i<n;i++)
    {
        if(end <= intervals[i][0])
        {
            end=intervals[i][1];
        }
        else
        {
            result++;
        }
    }

    return result;
}