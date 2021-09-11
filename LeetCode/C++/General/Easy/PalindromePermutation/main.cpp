#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * Approach: For a string to be a palindrome, each letter needs to have a matching letter when
 * iterating over the string from both ends. Except, for when we reach the middle of the string, where there
 * will be just a single letter, before continuing onto the mirror side. The edge cases to worry about are:
 * the string is empty, the string has length one, or the string has an even number of letters.
 * If the string has an even number of letters, then we just need an even number of pairs of the same
 * letters.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

bool canPermutePalindrome(string s)
{
    if(s.empty())
    {
        return true;
    }

    if(s.size()==1)
    {
        return true;
    }

    unordered_map<char, int> counts;

    for(char letter : s)
    {
        counts[letter]++;
    }

    int evenFrequencies=0;

    int oddFrequencies=0;

    for(const auto & element : counts)
    {
        if((element.second % 2)==1)
        {
            oddFrequencies++;
        }
        else
        {
            evenFrequencies++;
        }
    }

    return oddFrequencies==1 || (evenFrequencies > 0 && oddFrequencies==0);
}