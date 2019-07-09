#include <iostream>
#include <string>
using namespace std;

/*
 * Approach:
 * Using two pointers, create a window the size of the needle.
 * Then, move the window along the string and each time, see if
 * the string in the window is the needle we are looking for.
 *
 * Time Complexity: O(n * m) [where n is the size of the haystack and m is the size of the needle]
 *
 * Space Complexity: O(1)
 */

int strStr(string haystack, string needle)
{
    if(needle.empty())
    {
        return 0;
    }

    if(haystack.empty())
    {
        return -1;
    }

    if(needle.size() > haystack.size())
    {
        return -1;
    }

    int n=int(haystack.size());

    int m=int(needle.size());

    int result=-1;

    int i=0;

    int j=m-1;

    while(j < n)
    {
        int count=0;

        int walker=i;

        int current=0;

        while(walker <= j)
        {
            if(haystack[walker]==needle[current])
            {
                count++;
            }

            walker++;

            current++;
        }

        if(count==m)
        {
            result=i;

            break;
        }

        i++;

        j++;
    }

    return result;
}