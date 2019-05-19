#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

bool isValidStart(multiset<int> & ends, int start)
{
    bool valid=true;

    for(auto & end : ends)
    {
        if(start > end)
        {
            valid=false;

            break;
        }
    }

    return valid;
}

int findMinArrowShots(vector<pair<int, int>> & points)
{
    int arrows=0;

    if(points.empty())
    {
        return arrows;
    }

    sort(points.begin(), points.end(), [] (auto & p1, auto & p2) {return p1.first < p2.first;});

    int n=int(points.size());

    int balloons=n;

    int i=0;

    int j=0;

    multiset<int> ends;

    vector<int> starts;

    while(j < n)
    {
        if(ends.empty() && starts.empty())
        {
            ends.insert(points[j].second);

            starts.emplace_back(points[j].first);

            if(j==n-1)
            {
                break;
            }

            ++j;
        }

        if(points[j].second <= *(ends.end()) || points[j].second > *(ends.end()))
        {
            if(isValidStart(ends, points[j].first))
            {
                ends.insert(points[j].second);

                starts.emplace_back(points[j].first);

                ++j;
            }
            else
            {
                ++arrows;

                starts.clear();

                ends.clear();

                i=j;
            }
        }
    }

    if(!starts.empty() && !ends.empty())
    {
        ++arrows;

        starts.clear();

        ends.clear();
    }

    return arrows;
}