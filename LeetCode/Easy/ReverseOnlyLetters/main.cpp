#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: two-pointers. We move from the ends of the strings towards the middle of the string and handle the following cases:
 *
 * 1) If the character on the left side is not a letter, we continue moving towards the middle.
 * 2) If the character on the right side is not a letter, we continue moving towards the middle.
 * 3) Else, we know that both characters are letters and we can swap them.
 * After we swap them, we keep advancing towards the middle of the string.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 */

string reverseOnlyLetters(string S)
{
    int left=0;

    int right=int(S.size())-1;

    while(left < right)
    {
        if(!isalpha(S[left]))
        {
            left++;
        }
        else if(!isalpha(S[right]))
        {
            right--;
        }
        else
        {
            swap(S[left], S[right]);

            left++;

            right--;
        }
    }

    return S;
}