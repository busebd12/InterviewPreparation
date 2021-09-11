#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approach:
 *
 * 1. We use a hashtable (unordered_map<char, int>) to map each letter in the keyboard to its index.
 * Then, for each letter in word, we calculate the time it takes to go from the index of the previous
 * letter to the index of the current letter and add that time to our time integer variable.
 * After we have finished iterating through the word, return our time variable.
 *
 * Time complexity: O(k + w) [where k is the length of the keyboard string and w is the length of the word string]
 * Space complexity: O(k)
 *
 *
 * 2. Same logic but using a vector<int> for our hashtable. We hash each letter based on its ascii value.
 *
 * Time complexity: O(k + w) [where k is the length of the keyboard string and w is the length of the word string]
 * Space complexity: O(k)
 */

int calculateTime(string keyboard, string word)
{
    int time=0;

    if(word.empty() || keyboard.empty())
    {
        return time;
    }

    unordered_map<char, int> hashtable;

    auto k=keyboard.size();

    for(auto i=0;i<k;++i)
    {
        char key=keyboard[i];

        hashtable[key]=i;
    }

    int previousIndex=0;

    auto w=word.size();

    for(int i=0;i<w;++i)
    {
        char letter=word[i];

        int currentTime=0;

        int currentIndex=hashtable[letter];

        if(i > 0)
        {
            if(letter!=word[i-1])
            {
                currentTime=static_cast<int>(abs(currentIndex - previousIndex));
            }
        }
        else
        {
            currentTime=static_cast<int>(abs(currentIndex - previousIndex));
        }

        time+=currentTime;

        previousIndex=currentIndex;
    }

    return time;
}

int calculateTime(string keyboard, string word)
{
    int time=0;

    if(word.empty() || keyboard.empty())
    {
        return time;
    }

    vector<int> hashtable(26, 0);

    auto k=keyboard.size();

    for(auto i=0;i<k;++i)
    {
        char key=keyboard[i];

        hashtable[key - 'a']=i;
    }

    int previousIndex=0;

    auto w=word.size();

    for(int i=0;i<w;++i)
    {
        char letter=word[i];

        int currentTime=0;

        int currentIndex=hashtable[letter - 'a'];

        if(i > 0)
        {
            if(letter!=word[i-1])
            {
                currentTime=static_cast<int>(abs(currentIndex - previousIndex));
            }
        }
        else
        {
            currentTime=static_cast<int>(abs(currentIndex - previousIndex));
        }

        time+=currentTime;

        previousIndex=currentIndex;
    }

    return time;
}