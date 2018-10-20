#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n)
{
    vector<int> dp(n+1);

    dp[0]=0;

    dp[1]=1;

    dp[2]=2;

    dp[3]=3;

    for(int x=4;x<=n;++x)
    {
        dp[x]=x;

        for(int y=1;y<=x;++y)
        {
            int perfectSquare=y * y;

            if(perfectSquare > x)
            {
                break;
            }
            else
            {
                dp[x]=min(dp[x], 1 + dp[x-perfectSquare]);
            }
        }
    }

    return dp[n];
}