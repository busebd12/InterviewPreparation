#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach:
 *
 * First, we sort the vector of strings. This way, they will be lexicographical order.
 * Then, for each word in words, we look to see if the substring formed by all letters
 * in the current word, except for the last one, has been seen before. If it has, then
 * we know that this word has been built letter-by-letter up to this point, and we add
 * it to our unordered_set<string> smallerByOne. If the current word has size one, then
 * we are at the start of a possible longest word and also add it to our unordered_set.
 * Each time, we find a valid word, we compare it to the length of our result and update
 * result if the length of the current word is longer than it.
 *
 * Time complexity: O((n log n) * L) [where n is the length of our input vector and L is the length of the average word]
 * Space complexity: O(n)
 */

string longestWord(vector<string> & words)
{
    string result{};

    if(words.empty())
    {
        return result;
    }

    size_t n=words.size();

    if(n==1)
    {
        return words[0];
    }

    sort(words.begin(), words.end());

    unordered_set<string> smallerByOne;

    for(string word : words)
    {
        if(word.size()==1 || smallerByOne.count(word.substr(0, word.size()-1)))
        {
            if(word.size() > result.size())
            {
                result=word;
            }

            smallerByOne.insert(word);
        }
    }

    return result;
}