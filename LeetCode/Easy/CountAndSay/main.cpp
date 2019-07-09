#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Approach:
 *
 * The key realization is that the x+1 term of the count-and-say sequence is derived
 * by applying the "count-and-say" logic to the previous term of the count-and-say sequence.
 * So, this seems like a good candidate for straight forward dynamic programming because we will be using
 * solutions to previous sub-problems to solve the current problem.
 * We have a vector of strings and we pre-populate it with the first five strings of the count-and-say sequence.
 * Then, starting at the sixth term, we use the previous string and apply the "count-and-say" logic to it in order to get the next term.
 *
 * Time complexity: O(n)
 *
 * Space complexity: O(1) [we know the largest value of n will be thirty, a.k.a. a constant]
 */

string countAndSay(int n)
{
    if(n <= 0)
    {
        return "-1";
    }

    int space=30;

    vector<string> dp(space+1);

    dp[1]="1";

    dp[2]="11";

    dp[3]="21";

    dp[4]="1211";

    dp[5]="111221";

    int count=0;

    for(int i=6;i<=n;++i)
    {
        string next{};

        string previous=dp[i-1];

        int m=int(previous.size());

        for(int j=0;j<m;)
        {
            char current=previous[j];

            while(current==previous[j] && j < m)
            {
                j++;

                count++;
            }

            if(count==1)
            {
                next+=to_string(int(1));

                next+=current;
            }
            else
            {
                next+=to_string(count);

                next+=current;
            }

            count=0;
        }

        dp[i]=next;
    }

    return dp[n];
}