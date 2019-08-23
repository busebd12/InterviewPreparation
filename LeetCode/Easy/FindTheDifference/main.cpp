#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using an unordered_map as a hashtable, map each letter in t to its frequency.
 * Then, loop over s and decrease the frequency of each letter. Finally, loop over the hashtable
 * and the character that appears once, is the extra character.
 *
 * Time complexity: O(m + n) [where m is the length of s and n is the length of t]
 * Space complexity: O(m)
 *
 * 2) Same logic as the first approach, just using a vector of integers instead of an unordered_map
 * for our hashtable.
 *
 * Time complexity: O(m + n) [where m is the length of s and n is the length of t]
 * Space complexity: O(m)
 */

char findTheDifference(string s, string t)
{
    char result{};

    if(s.empty())
    {
        if(!t.empty())
        {
            return t[0];
        }
        else
        {
            return result;
        }
    }

    unordered_map<char, int> hashtable;

    for(char letter : t)
    {
        hashtable[letter]++;
    }

    for(char letter : s)
    {
        if(hashtable.count(letter))
        {
            if(hashtable[letter] > 0)
            {
                hashtable[letter]--;
            }
        }
    }

    for(const auto & element : hashtable)
    {
        if(element.second==1)
        {
            result=element.first;

            break;
        }
    }

    return result;
}

char findTheDifference(string s, string t)
{
    char result{};

    if(s.empty())
    {
        if(!t.empty())
        {
            return t[0];
        }
        else
        {
            return result;
        }
    }

    vector<int> hashtable(26, 0);

    for(char letter : t)
    {
        hashtable[letter - 'a']++;
    }

    for(char letter : s)
    {
        if(hashtable[letter - 'a'] > 0)
        {
            hashtable[letter - 'a']--;
        }
    }

    for(char c='a';c<='z';++c)
    {
        if(hashtable[c - 'a'] > 0)
        {
            result=c;

            break;
        }
    }

    return result;
}