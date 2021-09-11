#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
 * Approach:
 * Loop over the string and if we see a space character,
 * we check to see if our count of non-space characters is greater than zero.
 * If it is, we set the length of the word to count. Then, we set count to zero.
 * If the character is not a space, then we increment our count of non-space characters.
 * If, after the for loop, count is not zero, that means the string ended in a non-space character.
 * So, set result equal to count.
 *
 * Time complexity: O(n) [where n is the size of the input string]
 *
 * Space complexity: O(1)
 */

int lengthOfLastWord(string s)
{
    if(s.empty())
    {
        return 0;
    }

    int result=0;

    int n=int(s.size());

    int count=0;

    for(int index=0;index<n;++index)
    {
        char current=s[index];

        if(isspace(current))
        {
            if(count > 0)
            {
                result=count;
            }

            count=0;
        }
        else
        {
            count++;
        }
    }

    if(count > 0)
    {
        result=count;
    }

    return result;
}