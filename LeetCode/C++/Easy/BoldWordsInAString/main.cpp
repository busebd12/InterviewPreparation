#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach: the idea is the mark the positions of all words from the vector<string> words found
 * in the string S as true in a vector<bool> marked. Then, we simply add the <b> and </b> tags
 * around the correct substrings in the string S according to the marked positions.
 *
 * Time complexity: O(w * n) [where w is the average length of a word and n is the length of the input string, S]
 * Space complexity: O(n + number of <b> and </b> tags)
 */

void markLetters(string & S, string & word, vector<bool> & marked, const size_t & n)
{
    size_t wordSize=word.size();

    for(size_t i=0;i+wordSize-1<n;++i)
    {
        string substring=S.substr(i, wordSize);

        if(substring==word)
        {
            for(size_t j=i,count=0;count<wordSize;++count,++j)
            {
                marked[j]=true;
            }
        }
    }
}

string boldWords(vector<string> & words, string S)
{
    if(S.empty() || words.empty())
    {
        return S;
    }

    size_t n=S.size();

    vector<bool> marked(n, false);

    for(string & word : words)
    {
        markLetters(S, word, marked, n);
    }

    string result{};

    string openingTag="<b>";

    string closingTag="</b>";

    for(size_t index=0;index<n;++index)
    {
        if(marked[index] && (index==0 || !marked[index-1]))
        {
            result+=openingTag;
        }

        result+=S[index];

        if(marked[index] && (index==n-1 || !marked[index+1]))
        {
            result+=closingTag;
        }
    }

    return result;
}