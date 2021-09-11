#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approach: Since two meetings over lap if one meeting's ending time
 * is after another meeting starting time, sort the vector's by starting time.
 * Then, we simply loop over the intervals and see if one meeting's ending
 * time is after another meeting's starting time. This problem is asking
 * about the topic of disjoint sets.
 *
 * Time complexity: O(n log n) [where n is the number of intervals]
 * Space complexity: O(1)
 */

bool canAttendMeetings(vector<vector<int>>& intervals)
{
    if(intervals.empty())
    {
        return true;
    }

    if(intervals.size()==1)
    {
        return true;
    }

    int n=int(intervals.size());

    sort(intervals.begin(), intervals.end());

    for(int i=0;i<n;++i)
    {
        if(i+1 < n)
        {
            int currentEnd=intervals[i][1];

            int nextStart=intervals[i+1][0];

            if(currentEnd > nextStart)
            {
                return false;
            }
        }
    }

    return true;
}