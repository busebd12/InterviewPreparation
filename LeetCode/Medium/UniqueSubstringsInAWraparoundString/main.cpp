#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

char next(char c)
{
    return c=='z' ? 'a' : c+1;
}

int findSubstringInWraproundString(string p)
{
    if(p.empty())
    {
        return 0;
    }

    vector<int> dp(int(p.size()));

    vector<int> buckets(26, 0);

    dp[0]=1;

    buckets[p[0]-'a']=1;

    for(int i=1,N=int(p.size());i<N;++i)
    {
        char c=next(p[i-1]);

        if(c==p[i])
        {
            dp[i]=dp[i-1]+1;
        }
        else
        {
            dp[i]=1;
        }

        int bucket=p[i]-'a';

        buckets[bucket]=max(buckets[bucket], dp[i]);
    }

    return accumulate(buckets.begin(), buckets.end(), 0);
}