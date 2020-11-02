#include <iostream>
#include <sstream>
using namespace std;

/*
 * Approaches:
 *
 * 1) Loop over the string. If the character is not a space, increment our count of characters.
 * If the current character is a space and we have seen any amount of characters before the space,
 * increment the segments and reset our count of characters to zero. An edge case to be aware of
 * is if we reach the end of the string and the last character is not a space, then that's the
 * last segment in the string, so increment our segemnts counter accordingly.
 *
 * Time complexity: O(n) [where n is the size of the input string]
 * Space complexity: O(1)
 *
 * 2) Using stringstream from the Standard Template Library (STL). While there are strings separate by spaces,
 * increment our segments counter.
 *
 * Time complexity: O(n) [where n is the length of the string)
 * Space complexity: O(1)
 */

int countSegments(string s)
{
    int segments=0;

    if(s.empty())
    {
        return segments;
    }

    int n=int(s.size());

    int characters=0;

    for(int index=0;index<n;++index)
    {
        if(!isspace(s[index]))
        {
            characters++;

            if(index==n-1)
            {
                segments++;
            }
        }

        if(isspace(s[index]) && characters > 0)
        {
            segments++;

            characters=0;
        }
    }

    return segments;
}

int countSegments(string s)
{
    int segments=0;

    istringstream iss(s);

    while(iss >> s)
    {
        segments++;
    }

    return segments;
}