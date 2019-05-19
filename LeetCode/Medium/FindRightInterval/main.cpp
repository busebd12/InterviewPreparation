#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int findIndex(vector<Interval> & intervals, int target)
{
    int index=-1;

    int n=int(intervals.size());

    int minimum=numeric_limits<int>::max();

    for(int i=0;i<n;++i)
    {
        if(intervals[i].start >= target && intervals[i].start < minimum)
        {
            minimum=intervals[i].start;

            index=i;
        }
    }

    return index;
}

vector<int> findRightIntervalBruteForce(vector<Interval> & intervals)
{
    vector<int> indices;

    if(intervals.empty())
    {
        return indices;
    }

    int n=int(intervals.size());

    vector<bool> used(n, false);

    for(int i=0;i<n;++i)
    {
        int target=intervals[i].end;

        int index=findIndex(intervals, target);

        indices.emplace_back(index);
    }

    return indices;
}

vector<int> findRightInterval(vector<Interval> & intervals)
{
    vector<int> indices;

    if(intervals.empty())
    {
        return indices;
    }

    int n=int(intervals.size());

    vector<int> starts;

    for(auto & interval : intervals)
    {
        starts.emplace_back(interval.start);
    }

    unordered_map<int, int> startsMap;

    for(int i=0;i<n;++i)
    {
        int start=intervals[i].start;

        startsMap[start]=i;
    }

    sort(starts.begin(), starts.end());


    for(auto & interval : intervals)
    {
        int target=interval.end;

        auto minimumLarger=lower_bound(starts.begin(), starts.end(), target);

        if(minimumLarger==starts.end())
        {
            minimumLarger=prev(minimumLarger, 1);

            if(*(minimumLarger) < target)
            {
                indices.emplace_back(-1);
            }
        }
        else
        {
            int start=*(minimumLarger);

            indices.emplace_back(startsMap[start]);
        }

    }

    return indices;
}