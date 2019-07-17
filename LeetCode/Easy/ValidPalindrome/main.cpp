#include <iostream>
#include <string>
#include <locale>
using namespace std;

/*
 * Approach: Loop over the string using two pointers (integers indexers), lwo and high.
 * If the character pointed to by low is not alphanumeric, increment low.
 * Else if the character pointed to by high is not alphanumeric, increment high.
 * Else, if the two characters are not the same, return false. Else, continue looping.
 *
 * Time complexity: O(n) [where n is the size of the input string]
 * Space complexity: O(1)
 */

bool isPalindrome(string s)
{
    int low=0;

    int high=int(s.size()-1);

    while(low < high)
    {
        char left=tolower(s[low]);

        char right=tolower(s[high]);

        if(!isalnum(left))
        {
            low++;
        }
        else if(!isalnum(right))
        {
            high--;
        }
        else
        {
            if(left!=right)
            {
                return false;
            }
            else
            {
                low++;

                high--;
            }
        }
    }

    return true;
}