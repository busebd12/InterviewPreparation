#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: two pointers. We use two integer variables, i and j (both initialized to zero), to loop over
 * the name and typed strings. For each letter in the name string, we count the number of consecutive matching characters
 * starting from the index i and store it in nameLetterCount. Then, starting from the index j, count how many consecutive
 * letters match the current letter we are looking at in the name string and store it in typedLetterCount.
 * If typedLetterCount is less than nameLetterCount or if the current letter in typed is not the same as the current letter in name, we return false.
 * After iterating through both strings, if we haven't returned false yet, then we know typed is valid and we can return true.
 *
 * Time complexity: O(n + m) [where n is the length of the input string name and m is the length of the input string typed]
 * Space complexity: O(1)
 */

bool isLongPressedName(string name, string typed)
{
    int n=int(name.size());

    int m=int(typed.size());

    for(int i=0,j=0;i<n;)
    {
        char nameLetter=name[i];

        int nameLetterCount=0;

        while(name[i]==nameLetter && i < n)
        {
            nameLetterCount++;

            i++;
        }

        int typedLetterCount=0;

        if(j < m)
        {
            char typedLetter=typed[j];

            if(typedLetter!=nameLetter)
            {
                return false;
            }

            while(typed[j]==typedLetter & j < m)
            {
                typedLetterCount++;

                j++;
            }
        }

        if(typedLetterCount < nameLetterCount)
        {
            return false;
        }
    }

    return true;
}