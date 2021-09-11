#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Approach: use two pointers, i and j to walk the string.
 * Our goal is to reverse the first k characters for every 2k characters.
 * If there are less than k characters left, reverse all of them.
 * If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and ignore the rest.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

void reverseHelper(string & s, int start, int end)
{
    while(start <= end)
    {
        swap(s[start], s[end]);

        start++;

        end--;
    }
}

string reverseStr(string s, int k)
{
    if(s.empty())
    {
        return s;
    }

    int n=int(s.size());

    int twoK=2 * k;

    if(n < k)
    {
        reverseHelper(s, 0, n-1);

        return s;
    }

    if(n >= k && n < twoK)
    {
        reverseHelper(s, 0, k-1);

        return s;
    }

    int i=0;

    int j=twoK-1;

    while(j < n && i < n)
    {
        int charactersLeft=(j-i)+1;

        if(charactersLeft < k)
        {
            reverseHelper(s, i, n-1);

            break;
        }
        else if(charactersLeft >= k && charactersLeft < twoK)
        {
            reverseHelper(s, i, i+(k-1));

            break;
        }
        else
        {
            reverseHelper(s, i, i+(k-1));

            i+=twoK;

            if(n-(j+1) < twoK)
            {
                j+=(n-(j+1));
            }
            else
            {
                j+=twoK;
            }
        }
    }

    return s;
}