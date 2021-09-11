#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approach:
 *
 * 1) We count the number of letters in the license plate. Then, for each word in the words vector,
 * we map each letter to its frequency in a hashtable. Then, for each letter in the license plate,
 * we check two things: a) is the letter in the hashtable and b) is there more than one occurrence
 * of the letter left. If both of these conditions hold, we decrement the frequency of the current
 * letter by one. After looping through all of the license plate letters, if we have found all of
 * them in hashtable, if the result string is empty, we choose the current word. Else, if the current
 * word size is less than the result string size, then we choose the current word.
 *
 * Time complexity: O(w * (l + m)) [where w is the number of words in the words vector; l is the average length of a word and m is the length of the license plate]
 * Space complexity: O(w)
 *
 *
 * 2) The same logic, we just use a vector<int> instead of unordered_map<char, int> as our hashtable.
 *
 * Time complexity: O(w * (l + m)) [where w is the number of words in the words vector; l is the average length of a word and m is the length of the license plate]
 * Space complexity: O(w)
 */

string shortestCompletingWord(string licensePlate, vector<string>& words)
{
    string result{};

    if(licensePlate.empty() || words.empty())
    {
        return result;
    }

    int licensePlateLetters=0;

    for(char & letter : licensePlate)
    {
        if(isalpha(letter))
        {
            ++licensePlateLetters;
        }
    }

    for(const string & word : words)
    {
        unordered_map<char, int> hashtable;

        int foundLetters=licensePlateLetters;

        for(const char & letter : word)
        {
            ++hashtable[letter];
        }

        for(char & letter : licensePlate)
        {
            if(isalpha(letter))
            {
                char lowercase=tolower(letter);

                if(hashtable.count(lowercase) && hashtable[lowercase] > 0)
                {
                    --foundLetters;

                    --hashtable[lowercase];
                }
            }
        }

        if(foundLetters==0)
        {
            if(result.empty())
            {
                result=word;
            }
            else
            {
                if(word.size() < result.size())
                {
                    result=word;
                }
            }
        }
    }

    return result;
}

string shortestCompletingWord(string licensePlate, vector<string> & words)
{
    string result{};

    if(licensePlate.empty() || words.empty())
    {
        return result;
    }

    int licensePlateLetters=0;

    for(char & letter : licensePlate)
    {
        if(isalpha(letter))
        {
            ++licensePlateLetters;
        }
    }

    for(const string & word : words)
    {
        vector<int> hashtable(26, 0);

        for(const char & letter : word)
        {
            ++hashtable[letter - 'a'];
        }

        int foundLetters=licensePlateLetters;

        for(char & letter : licensePlate)
        {
            if(isalpha(letter))
            {
                char lowercase=tolower(letter);

                if(hashtable[lowercase - 'a'] > 0)
                {
                    --foundLetters;

                    --hashtable[lowercase - 'a'];
                }
            }
        }

        if(foundLetters==0)
        {
            if(result.empty())
            {
                result=word;
            }
            else
            {
                if(word.size() < result.size())
                {
                    result=word;
                }
            }
        }
    }

    return result;
}