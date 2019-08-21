#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Approach: Moving from both ends of the string towards the middle, swap the letters if both of them are vowels
 *
 * Time complexity: O(n/2) [where n is the number of characters in the string]
 * Spaec complexity: O(1)
 */

bool isVowel(const char & c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

string reverseVowels(string s)
{
    if(s.empty())
    {
        return s;
    }

    int n=int(s.size());

    if(n==1)
    {
        return s;
    }

    int left=0;

    int right=n-1;

    while(left < right)
    {
        if(!isVowel(tolower(s[left])))
        {
            left++;
        }
        else if(!isVowel(tolower(s[right])))
        {
            --right;
        }
        else
        {
            swap(s[left], s[right]);

            left++;

            right--;
        }
    }

    return s;
}