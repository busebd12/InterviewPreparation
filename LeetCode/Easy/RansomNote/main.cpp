#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use a hashtable (unordered_map) to map each letter in the magazine to its frequency.
 * Then, loop over the ransom note and check the following things: is the letter in the hashtable and if it is,
 * are there more than one letter left.
 *
 * Time complexity: O(m + n) [where m is the length of ransomNote and n is the length of magazine]
 * Space complexity: O(n)
 *
 * 2) Use a vector instead of unordered_map for our hashtable. Similar logic.
 *
 * Time complexity: O(m + n) [where m is the length of ransomNote and n is the length of magazine]
 * Space complexity: O(n)
 *
 * 3) Same approach as number 2 but calculating the index differently for each letter.
 *
 * Time complexity: O(m + n) [where m is the length of ransomNote and n is the length of magazine]
 * Space complexity: O(n)
 */

bool canConstruct(string ransomNote, string magazine)
{
    if(magazine.empty())
    {
        if(ransomNote.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    unordered_map<char, int> hashtable;

    for(char c : magazine)
    {
        hashtable[c]++;
    }

    for(char letter : ransomNote)
    {
        if(hashtable.count(letter))
        {
            if(hashtable[letter] > 0)
            {
                hashtable[letter]--;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool canConstruct(string ransomNote, string magazine)
{
    if(magazine.empty())
    {
        if(ransomNote.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    vector<int> hashtable(26, 0);

    for(char c : magazine)
    {
        hashtable[(c - '0') % 26]++;
    }

    for(char letter : ransomNote)
    {
        if(hashtable[(letter - '0') % 26]==0)
        {
            return false;
        }
        else
        {
            hashtable[(letter - '0') % 26]--;
        }
    }

    return true;
}

bool canConstruct(string ransomNote, string magazine)
{
    if(magazine.empty())
    {
        if(ransomNote.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    vector<int> hashtable(26, 0);

    for(char c : magazine)
    {
        hashtable[c - 'a']++;
    }

    for(char letter : ransomNote)
    {
        if(hashtable[letter - 'a']==0)
        {
            return false;
        }
        else
        {
            hashtable[letter - 'a']--;
        }
    }

    return true;
}