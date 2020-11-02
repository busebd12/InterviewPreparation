#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use a hash table (unordered_map) to keep track of the frequencies of each letter in s.
 * If t is an anagram of s, then the frequency of each letter in t should match s.
 *
 * Time complexity: O(n + m) [where n is the length of s and m is the length of t]
 * Space complexity: O(n) [where n is the length of s]
 *
 * 2) Same logic but use a vector instead of a hash table (unordered_map)
 *
 * Time complexity: O(n + m) [where n is the length of s and m is the length of t]
 * Space complexity: O(n) [where n is the length of s]
 */

bool isAnagram(string s, string t)
{
    if(s.empty() && t.empty())
    {
        return true;
    }

    if(s.empty() && !t.empty())
    {
        return false;
    }

    if(s.size()!=t.size())
    {
        return false;
    }

    unordered_map<char, int> sLetters;

    for(char c : s)
    {
        sLetters[c]++;
    }

    for(char letter : t)
    {
        if(sLetters.count(letter))
        {
            if(sLetters[letter]==0)
            {
                return false;
            }
            else
            {
                sLetters[letter]--;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool isAnagram(string s, string t)
{
    vector<int> sLetters(26, 0);

    for(char letter : s)
    {
        int integerEquivalent=(letter - 'a');

        sLetters[integerEquivalent]++;
    }

    for(char letter : t)
    {
        int integerEquivalent=(letter - 'a');

        if(sLetters[integerEquivalent]==0)
        {
            return false;
        }
        else
        {
            sLetters[integerEquivalent]--;
        }
    }

    return true;
}