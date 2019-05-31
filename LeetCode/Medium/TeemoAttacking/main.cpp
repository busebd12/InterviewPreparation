#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    int totalTime=0;

    if(timeSeries.empty())
    {
        return 0;
    }

    int n=int(timeSeries.size());

    for(int i=0;i<n-1;++i)
    {
        if(timeSeries[i] + (duration-1) >= timeSeries[i+1])
        {
            totalTime+=timeSeries[i+1]-timeSeries[i];
        }
        else
        {
            totalTime+=duration;
        }
    }

    return totalTime+duration;
}