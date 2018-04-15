#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int start;

    int end;

    Interval(): start(0), end(0) {}

    Interval(int s, int e): start(s), end(e) {}
};

bool intervalsOverlap(const Interval & a, const Interval & b)
{
    return a.end >= b.start;
}

Interval mergeIntervals(const Interval & a, const Interval & b)
{
    int end=max(a.end, b.end);

    Interval merged(a.start, end);

    return merged;
}

vector<Interval> merge(vector<Interval> & intervals)
{
    if(intervals.size() <= 1)
    {
        return intervals;
    }

    sort(begin(intervals), end(intervals), [] (const Interval & a, const Interval & b) {return a.start < b.start;});

    vector<Interval> result;

    Interval current(intervals[0].start, intervals[0].end);

    const int intervalsSize=int(intervals.size());

    for(int i=1;i<intervalsSize;++i)
    {
        if(intervalsOverlap(current, intervals[i]))
        {
            current=mergeIntervals(current, intervals[i]);
        }
        else
        {
            result.emplace_back(current);

            current=intervals[i];
        }
    }

    result.emplace_back(current);

    return result;
}