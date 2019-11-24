#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: as we loop over the string s, each time we see the letter 'L' we increment our balanced integer by one.
 * Each time we see the letter 'R' we decrement balanced by one. When balanced is equal to zero, then we know
 * we have a string with equal number 'L's and 'R's and we increment our result variable. After we finishing
 * iterating through the input string, we return our result variable.
 *
 * Time complexity: O(n) [where n is the length of our input string]
 * Space complexity: O(1)
 */

int balancedStringSplit(string s)
{
    int balanced=0;

    int result=0;

    for(const char & letter : s)
    {
        if(letter=='L')
        {
            balanced++;
        }
        else
        {
            balanced--;
        }

        if(balanced==0)
        {
            result++;
        }
    }

    return result;
}