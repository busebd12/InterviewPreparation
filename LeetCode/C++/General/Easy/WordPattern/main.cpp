#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

/*
 * Approach: use two hash tables (unordered_maps) to map each letter to its corresponding word in str.
 * The failure cases are if the same letter maps to two different strings or two different letters map
 * to the same word.
 *
 * Time complexity: O(n) [where n is the length of pattern and the number of words in str]
 * Space complexity: O(n)
 */

bool wordPattern(string pattern, string str)
{
    if(pattern.empty() && str.empty())
    {
        return true;
    }

    if(pattern.empty() || str.empty())
    {
        return false;
    }

    int n=int(pattern.size());

    int numberOfWords=1;

    int m=int(str.size());

    int current=0;

    while(current < m)
    {
        if(isspace(str[current]))
        {
            current++;

            numberOfWords++;
        }
        else
        {
            while(isalpha(str[current]))
            {
                current++;
            }
        }
    }

    if(numberOfWords!=n)
    {
        return false;
    }

    vector<string> words(numberOfWords);

    int index=0;

    string word{};

    stringstream ss(str);

    while(getline(ss, word, ' '))
    {
        words[index++]=word;
    }

    unordered_map<char, string> letterToWord;

    unordered_map<string, char> wordToLetter;

    for(int i=0;i<n;++i)
    {
        char letter=pattern[i];

        string currentWord=words[i];

        if(!letterToWord.count(letter))
        {
            if(!wordToLetter.count(currentWord))
            {
                letterToWord[letter]=currentWord;

                wordToLetter[currentWord]=letter;
            }
            else
            {
                if(wordToLetter[currentWord]!=letter)
                {
                    return false;
                }
            }
        }
        else
        {
            if(letterToWord[letter]!=currentWord)
            {
                return false;
            }
        }
    }

    return true;
}