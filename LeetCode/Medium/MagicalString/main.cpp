#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int magicalString(int n)
{
    if(n==0)
    {
        return 0;
    }

    if(n==1 || n==2)
    {
        return 1;
    }

    string result="122";

    for(int i=3;i<n;++i)
    {
        int limit=result[i-1]-'0';

        if(i%2==1)
        {
            for(int x=0;x<limit;++x)
            {
                result+='1';
            }
        }
        else
        {
            for(int x=0;x<limit;++x)
            {
                result+='2';
            }
        }
    }

    int ones=0;

    for(int i=0;i<n;++i)
    {
        if(result[i]=='1')
        {
            ones++;
        }
    }

    return ones;
}