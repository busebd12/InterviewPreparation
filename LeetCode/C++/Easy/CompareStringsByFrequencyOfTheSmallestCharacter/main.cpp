#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach: for each word in the words vector, we calculate the frequency of the smallest letter
 * and map the index of the current word to that frequency in a hashtable (vector<int>).
 * Next, for each query in the queries vector, we calculate the frequency of its smallest letter
 * and then compare that value against the frequency for all words and if a word has a largest frequency,
 * we increment our count integer variable. After loop through all the words, we put the value of count
 * at the appropriate index within our vector<int> result. After we have finished looping through all the queries,
 * we return our result vector.
 *
 * Time complexity: O(w + (q * w)) [where w is the length of the words vector and q is the length of the queries vector]
 * Space complexity: O(w + 26)
 */

int getSmallestLetterFrequency(const string & str)
{
    vector<int> hashtable(26, 0);

    for(auto & letter : str)
    {
        hashtable[letter - 'a']++;
    }

    int frequency=0;

    int i=0;

    while(hashtable[i]==0)
    {
        i++;
    }

    frequency=hashtable[i];

    return frequency;
}

vector<int> numSmallerByFrequency(vector<string> & queries, vector<string> & words)
{
    if(queries.empty() || words.empty())
    {
        return {};
    }

    auto q=queries.size();

    auto w=words.size();

    vector<int> result(q, 0);

    vector<int> hashtable(w, 0);

    int smallestLetterFrequency=0;

    for(auto i=0;i<w;++i)
    {
        smallestLetterFrequency=getSmallestLetterFrequency(words[i]);

        hashtable[i]=smallestLetterFrequency;
    }

    for(auto x=0;x<q;++x)
    {
        smallestLetterFrequency=getSmallestLetterFrequency(queries[x]);

        int count=0;

        for(int i=0;i<w;++i)
        {
            if(hashtable[i] > smallestLetterFrequency)
            {
                count++;
            }
        }

        result[x]=count;
    }

    return result;
}