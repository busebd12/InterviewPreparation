#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int toInt(vector<bool> & used)
{
    int number=0;

    for(bool x : used)
    {
        number<<=1;

        if(x)
        {
            number|=1;
        }
    }

    return number;
}

bool dfs(unordered_map<int, bool> & memoization, vector<bool> & used, int desiredTotal)
{
    if(desiredTotal <= 0)
    {
        return false;
    }

    int key=toInt(used);

    if(!memoization.count(key))
    {
        for(int i=1;i<int(used.size());++i)
        {
            if(!used[i])
            {
                used[i]=true;

                if(!dfs(memoization, used, desiredTotal-i))
                {
                    memoization[key]=true;

                    used[i]=false;

                    return true;
                }

                used[i]=false;
            }
        }

        memoization[key]=false;
    }

    return memoization[key];
}

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    if(desiredTotal <= 0)
    {
        return true;
    }

    int sum=0;

    for(int i=1;i<=maxChoosableInteger;++i)
    {
        sum+=i;
    }

    if(sum < desiredTotal)
    {
        return false;
    }

    unordered_map<int, bool> memoization;

    vector<bool> used(maxChoosableInteger+1);

    return dfs(memoization, used, desiredTotal);
}