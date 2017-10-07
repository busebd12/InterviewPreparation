#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> findRelativeRanks(vector<int>& nums)
{
    map<int, int> mp;

    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]=i;
    }

    vector<string> result(mp.size(), "");

    int count=1;

    for(auto itr=mp.rbegin();itr!=mp.rend();++itr,++count)
    {
        if(count==1)
        {
           result[itr->second]="Gold Medal"; 
        }   
        else if(count==2)
        {
            result[itr->second]="Silver Medal";
        }
        else if(count==3)
        {
            result[itr->second]="Bronze Medal";
        }
        else
        {
            result[itr->second]=to_string(count);
        }
    }

    return result;
}