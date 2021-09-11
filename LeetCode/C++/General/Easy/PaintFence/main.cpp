#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursion. top down
 *
 * Base cases:
 * a) If there are no fence posts or no colors to paint them with, then there are zero ways to paint the fence posts.
 * b) If there is one fence post, then there are k ways to paint it.
 * c) If there are two fence posts, then there are k ways to paint each post. Thus, k * k total ways to paint both.
 *
 * General case:
 * You can use the color for the last post just for the last post or for the two last posts,
 * extending either the n-1 or the n-2 case, and in both cases, you must choose from the k-1 colors
 * that the case you're extending didn't end with.
 *
 * Time complexity: O(2^n * (k-1)) [where n is the number of posts and k is the number of colors]
 * Space complexity: O(2^n * (k-1)) recursive stack space.
 *
 * 2) Dynamic programming, bottom-up:
 * Just the same logic as the recursive approach, just written a tad differently.
 *
 * Time complexity: O(n) [where n is the number of fence posts]
 * Space complexity: O(n)
 */

int numWays(int n, int k)
{
    if(n==0 || k==0)
    {
        return 0;
    }

    if(n==1)
    {
        return k;
    }

    if(n==2)
    {
        return k * k;
    }

    return (numWays(n-1, k) + numWays(n-2, k)) * (k-1);
}

int numWays(int n, int k)
{
    if(n==0 || k==0)
    {
        return 0;
    }

    vector<int> dp(n);

    for(int index=0;index<n;++index)
    {
        if(index==0)
        {
            dp[index]=k;
        }
        else if(index==1)
        {
            dp[index]=k * k;
        }
        else
        {
            dp[index]=dp[index-1] * (k-1) + dp[index-2] * (k-1);
        }
    }

    return dp[n-1];
}