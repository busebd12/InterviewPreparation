#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int findMinDifference(vector<string> & timePoints)
{
    int minutesInADay=24 * 60;

    int n=int(timePoints.size());

    vector<int> table(n, 0);

    for(int i=0;i<n;++i)
    {
        auto colon=timePoints[i].find(':');

        string hoursString=timePoints[i].substr(0, colon);

        string minutesString=timePoints[i].substr(colon+1);

        int hours=stoi(hoursString);

        int minutes=stoi(minutesString);

        int totalMinutes=((hours * 60) + minutes);

        table[i]=totalMinutes;
    }

    sort(table.begin(), table.end());

    table.push_back(table[0] + minutesInADay);

    int result=minutesInADay;

    for(int i=1;i<table.size();++i)
    {
        result=min(result, table[i]-table[i-1]);
    }

    return result;
}