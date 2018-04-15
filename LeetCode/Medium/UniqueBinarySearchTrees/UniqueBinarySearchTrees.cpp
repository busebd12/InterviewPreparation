#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n)
{
    vector<int> dp(n+1);

    dp[0]=0;

    dp[1]=1;

    dp[2]=2;

    if(n <= 2)
    {
        return dp[n];
    }

    for(int index=3;index<=n;++index)
    {
        int total=0;

        for(int number=1;number<=index;++number)
        {
            int leftChildren=index-number;

            int rightChildren=number-1;

            if(leftChildren==0)
            {
                total+=dp[rightChildren];
            }
            else if(rightChildren==0)
            {
                total+=dp[leftChildren];
            }
            else
            {
                total+=dp[leftChildren] * dp[rightChildren];
            }
        }

        dp[index]=total;
    }

    return dp[n];
}