#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution: the algorithm is as follows
 *
 * 1. Put all intervals into a vector of intervals.
 * 2. Sort all the intervals by start time.
 * 3. Merge all the intervals that can be merged together.
 * 4. The free time intervals will be the formed by combining the end of an interval with the start of the next interval,
 * for all the merged intervals.
 *
 * Time complexity: O(n log n) [where n is the total number of intervals]
 * Space complexity: O(n + m) [where n is the total number of intervals and m is the total number of merged intervals]
 */

class Interval
{
    public:
        int start;
        int end;

        Interval() {}

        Interval(int _start, int _end)
        {
            start = _start;
            end = _end;
        }
};

std::vector<Interval> employeeFreeTime(std::vector<std::vector<Interval>> & schedule)
{
    std::vector<Interval> result;

    auto n=int(schedule.size());

    std::vector<Interval> intervals;

    for(const auto & employeeSchedule : schedule)
    {
        for(const auto & interval : employeeSchedule)
        {
            intervals.emplace_back(interval);
        }
    }

    std::sort(intervals.begin(), intervals.end(), [] (Interval & i1, Interval & i2) {return i1.start < i2.start;});

    std::vector<Interval> merged;

    Interval combined(intervals[0].start, intervals[0].end);

    for(auto i=1;i<int(intervals.size());++i)
    {
        if((combined.end >= intervals[i].start && combined.end <= intervals[i].end) || (intervals[i].start >= combined.start && intervals[i].start <= combined.end))
        {
            combined.start=std::min(combined.start, intervals[i].start);

            combined.end=std::max(combined.end, intervals[i].end);
        }
        else
        {
            Interval interval(combined.start, combined.end);

            merged.emplace_back(interval);

            combined.start=intervals[i].start;

            combined.end=intervals[i].end;
        }
    }

    merged.emplace_back(combined);

    for(auto i=1;i<int(merged.size());++i)
    {
        Interval interval(merged[i-1].end, merged[i].start);

        result.emplace_back(interval);
    }

    return result;
}