#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Use a hashtable (unordered_map<char, int>) to store all the individual letters
 * in the input string chars. Then, for each word in words, we check if each letter
 * in the word is in the hashtable. If it is, we decrement the frequency of the letter
 * in the hashtable. If the frequency drops to zero, then we remove the letter.
 * If the letter is not found, then we set the allLettersFound boolean to false
 * and stop looping over the current word. After looping over the current word,
 * if all letters have been found, then we can add the length of the current word
 * to our result integer. After looping over all words, return our result variable.
 *
 * Time complexity: O(n * c * L) [where n is the length of the words vector, c is the length of the string chars, and L is the average length of a word]
 * Space complexity: O(c)
 *
 *
 * 2. Same logic but just using a vector<int> instead of unordered_map<char, int> for our hashtable.
 * We hash the letters based on the values when casted to integers.
 *
 * Time complexity: O(n * c * L) [where n is the length of the words vector, c is the length of the string chars, and L is the average length of a word]
 * Space complexity: O(c)
 */

int countCharacters(vector<string>& words, string chars)
{
    if(words.empty() || chars.empty())
    {
        return 0;
    }

    int result=0;

    for(const auto & word : words)
    {
        unordered_map<char, int> hashtable;

        for(const auto & character : chars)
        {
            hashtable[character]++;
        }

        bool allLettersFound=true;

        for(const auto & letter : word)
        {
            if(hashtable.count(letter))
            {
                hashtable[letter]--;

                if(hashtable[letter]==0)
                {
                    hashtable.erase(letter);
                }
            }
            else
            {
                allLettersFound=false;

                break;
            }
        }

        if(allLettersFound)
        {
            result+=int(word.size());
        }
    }

    return result;
}

int countCharacters(vector<string>& words, string chars)
{
    if(words.empty() || chars.empty())
    {
        return 0;
    }

    int result=0;

    for(const auto & word : words)
    {
        vector<int> hashtable(123, 0);

        for(const auto & character : chars)
        {
            hashtable[int(character)]++;
        }

        bool allLettersFound=true;

        for(const auto & letter : word)
        {
            if(hashtable[int(letter)] > 0)
            {
                hashtable[int(letter)]--;
            }
            else
            {
                allLettersFound=false;

                break;
            }
        }

        if(allLettersFound)
        {
            result+=int(word.size());
        }
    }

    return result;
}