#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

/*
 * Approach: we first determine if the input string is made up of all words (strings more than one character) or all letters.
 * Then, we put all the banned words in to an unordered_set<string> bannedWords so that we can have constant time searching
 * against the list. Next, using a stringstream, we parse the paragraph and isolate either the words or the characters, depending.
 * As we parse the string, we keep a count of how many times we've seen each word or character using a hashtable (unordered_map<string, int>).
 * After we are finished parsing the string, we return the string with the highest frequency.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

string mostCommonWord(string paragraph, vector<string> & banned)
{
    string result{};

    if(paragraph.empty())
    {
        return result;
    }

    bool onlyLetters=true;

    unordered_set<string> bannedWords;

    if(banned.empty())
    {
        onlyLetters=false;
    }
    else
    {
        for(string bannedWord : banned)
        {
            if(bannedWord.size() > 1)
            {
                onlyLetters=false;
            }

            bannedWords.insert(bannedWord);
        }
    }

    unordered_map<string, int> candidates;

    stringstream ss(paragraph);

    string buffer{};

    while(ss >> buffer)
    {
        string word{};

        for(const char & character : buffer)
        {
            if(isalpha(character))
            {
                word+=character;
            }
        }

        if(!bannedWords.count(word))
        {
            if(onlyLetters)
            {
                for_each(word.begin(), word.end(), [&candidates, &bannedWords] (char & c) {
                    c=char(tolower(c));

                    string s(1, c);

                    if(!bannedWords.count(s))
                    {
                        candidates[s]++;
                    }
                    ;});
            }
            else
            {
                for_each(word.begin(), word.end(), [&candidates] (char & c) {c=char(tolower(c));});

                candidates[word]++;
            }
        }
    }

    auto mostOccurring=max_element(candidates.begin(), candidates.end(), [] (const auto & e1, const auto & e2) {return e1.second < e2.second;});

    result=mostOccurring->first;

    return result;
}