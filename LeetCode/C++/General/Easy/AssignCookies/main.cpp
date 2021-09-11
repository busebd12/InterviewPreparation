#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach: the idea is to sort both the greed vector and the cookie vector (g and s, respectively).
Then, we use two pointers to loop over both vectors. If the current cookie is large enough to satisfy
the current child's greed, then great, we increment the result and keep moving through both vectors.
However, if the cookie is not enough to satisfy the greed, then we just keep moving through the cookies
until we find one that does satisfy the greed level.

Time complexity: O(g log g + s log s) [where g is the total number of greed factors and s is the total number of cookies]
Space complexity: O(1)
*/

int findContentChildren(vector<int> & g, vector<int> & s)
{
    if(g.empty() || s.empty())
    {
        return 0;
    }

    int result=0;

    int n=int(g.size());

    int m=int(s.size());

    sort(g.begin(), g.end());

    sort(s.begin(), s.end());

    int i=0;

    int j=0;

    while(i < n && j < m)
    {
        int cookie=s[j];

        int greed=g[i];

        if(cookie >= greed)
        {
            result++;

            i++;
        }

        j++;
    }

    return result;
}