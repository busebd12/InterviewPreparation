#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
};

int eraseOverlapIntervals(vector<Interval> & intervals)
{
    int count=0;

    if(intervals.empty())
    {
        return count;
    }

    int n=int(intervals.size());

    sort(intervals.begin(), intervals.end(), [] (Interval & i1, Interval & i2) {return i1.end <= i2.end;});

    int end=intervals[0].end;

    count=1;

    for(int i=1;i<n;++i)
    {
        if(intervals[i].start >= end)
        {
            end=intervals[i].end;

            ++count;
        }
    }

    return n-count;
}