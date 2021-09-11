#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

/*
 * Approaches, from top-to-bottom
 *
 * 1) Use a hash table to map each letter to it corresponding integer values.
 * Then, loop over the string and convert each letter from base-26 to base-10
 * and add the result to our answer.
 *
 * Conversion example: for s = "BCM" the final solution would be (2 x 26 x 26) + (3 x 26) + (13)
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2) This is just a faster version of the previous solution.
 * The speed boost comes from not using a hash table to keep track of the integer values for our letters.
 * Instead, we use this trick: (letter - 'A') + 1
 * ('A' - 'A')=0 -> 0+1=1
 * ('B' - 'A')=1 -> 1+1=2
 * ('C' - 'A')=2 -> 2+1=3
 * etc
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

int titleToNumber(string s)
{
    int result=0;

    int n=int(s.size());

    int end=n-1;

    unordered_map<char, int> table;

    int count=1;

    for(char c='A';c<='Z';++c,++count)
    {
        table[c]=count;
    }

    for(int i=0;i<n;++i)
    {
        char letter=s[i];

        int offset=int(pow(26, end-i));

        int letterValue=table[letter];

        int converted=letterValue * offset;

        result+=converted;
    }

    return result;
}

int titleToNumber(string s)
{
    int result=0;

    int n=int(s.size());

    int end=n-1;

    for(int i=0;i<n;++i)
    {
        char letter=s[i];

        int offset=int(pow(26, end-i));

        int letterValue=(letter - 'A') + 1;

        int converted=letterValue * offset;

        result+=converted;
    }

    return result;
}