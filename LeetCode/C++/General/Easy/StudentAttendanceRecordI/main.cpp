#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: loop over the string and count the number of 'A' characters
 * and the number of consecutive 'L' characters. If the number of these
 * characters don't meet our criteria, return false. Else, return true.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 */

bool checkRecord(string s)
{
    if(s.empty())
    {
        return true;
    }

    int aCount=0;

    int consecutiveLs=0;

    int n=int(s.size());

    int i=0;

    while(i < n)
    {
        if(s[i]=='L')
        {
            int count=0;

            while(s[i]=='L')
            {
                count++;

                i++;
            }

            consecutiveLs=max(consecutiveLs, count);
        }
        else
        {
            if(s[i]=='A')
            {
                aCount++;
            }

            i++;
        }
    }

    if(aCount > 1 || consecutiveLs > 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}