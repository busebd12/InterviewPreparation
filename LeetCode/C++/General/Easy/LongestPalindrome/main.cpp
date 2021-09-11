#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a hashtable (unordered_map<char, int>), map each character to how many times it appears in the string.
 * Loop over the hash table. If the character appears an even number of times, then just add its frequency to the result
 * since we can even split the amount of characters into both sides of the palindrome. If the character appears an odd
 * number of times, divide it in half and then double it. This way we can evenly divide all but one of the characters
 * on both sides of the palindrome. At this point, if the length is equal to the size of the string, then it's a
 * palindrome with an even number of characters on both sides. Else, the longest palindrome is an even number of characters
 * on either side with one single character in the middle.
 *
 * Time complexity: O(n) [where n is the size of the string]
 * Space complexity: O(m) [where m is the number of characters in the string]
 *
 * 2) Same logic just using a vector<int> instead of unordered_map<char, int> for our hashtable.
 *
 * Time complexity: O(n) [where n is the size of the string]
 * Space complexity: O(m) [where m is the number of ASCII characters]
 */

int longestPalindrome(string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    unordered_map<char, int> hashtable;

    for(char letter : s)
    {
        hashtable[letter]++;
    }

    for(auto element : hashtable)
    {
        if(element.second%2==0)
        {
            result+=element.second;
        }
        else
        {
            int halfDoubled=((element.second/2)*2);

            result+=halfDoubled;
        }
    }

    if(result!=s.length())
    {
        result+=1;
    }

    return result;
}

int longestPalindrome(string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    int m=256;

    vector<int> hashtable(m, 0);

    for(char letter : s)
    {
        hashtable[letter - '0']++;
    }

    for(int i=0;i<m;++i)
    {
        if(hashtable[i]%2==0)
        {
            result+=hashtable[i];
        }
        else
        {
            int halfDoubled=((hashtable[i]/2)*2);

            result+=halfDoubled;
        }
    }

    if(result!=s.length())
    {
        result+=1;
    }

    return result;
}