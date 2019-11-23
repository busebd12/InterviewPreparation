#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1. While we loop over the input string, we place only the letters that appear in the word "balloon"
 * into our hashtable (unordered_map<char, int>) which keeps track of their frequency. Then, we count
 * how many times we can make the word "balloon" from the letters in our hashtable.
 *
 * Time complexity: O(n) + O(f) => O(n + f) [where n is the length of our input string and f is the minimum frequency in our hashtable]
 * Space complexity: O(m) [where m is the total number of letters from the word balloon]
 *
 * 2. We place all the letters from our input string into a hashtable to count their frequency.
 * The answer will be the minimum frequency between the all the letters that make up the word balloon
 * that are in our hashtable.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

bool isValidCharacter(const char & c)
{
    return (c=='b' || c=='a' || c=='l' || c=='o' || c=='n');
}

int helper(unordered_map<char, int> & hashtable)
{
    if(!hashtable.count('a') || !hashtable.count('b') || !hashtable.count('l') || !hashtable.count('o') || !hashtable.count('n'))
    {
        return 0;
    }

    const int targetLength=7;

    int total=0;

    while(hashtable.count('a') && hashtable.count('b') && hashtable.count('l') && hashtable.count('o') && hashtable.count('n'))
    {
        int length=0;

        length++;

        hashtable['b']--;

        if(hashtable['b']==0)
        {
            hashtable.erase('b');
        }

        length++;

        hashtable['a']--;

        if(hashtable['a']==0)
        {
            hashtable.erase('a');
        }

        for(int count=0;count<2;++count)
        {
            length++;

            hashtable['l']--;

            if(hashtable['l']==0)
            {
                hashtable.erase('l');

                break;
            }
        }

        for(int count=0;count<2;++count)
        {
            length++;

            hashtable['o']--;

            if(hashtable['o']==0)
            {
                hashtable.erase('o');

                break;
            }
        }

        length++;

        hashtable['n']--;

        if(hashtable['n']==0)
        {
            hashtable.erase('n');
        }

        if(length==targetLength)
        {
            total++;
        }
    }

    return total;
}

int maxNumberOfBalloons(string text)
{
    int result=0;

    if(text.empty())
    {
        return 0;
    }

    unordered_map<char, int> hashtable;

    for(const auto & letter : text)
    {
        if(isValidCharacter(letter))
        {
            hashtable[letter]++;
        }
    }

    result+=helper(hashtable);

    return result;
}

int maxNumberOfBalloons(string text)
{
    unordered_map<char, int> hashtable;

    for(const char & letter : text)
    {
        hashtable[letter]++;
    }

    return min({hashtable['b'], hashtable['a'], hashtable['l']/2, hashtable['o']/2, hashtable['n']});
}