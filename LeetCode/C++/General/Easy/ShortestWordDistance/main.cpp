#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a hash table (unordered_map) map each word to a list of every other word (including itself) paired
 * with the distance from the current word (where the distance is minimized if there is more than one occurrence of a word).
 *
 * Time complexity: O(n-squared)
 * Space complexity: O(n)
 *
 * 2) While looping over the words vector, if the current word is equal to word1, we then
 * loop over the words vector a second time, looking for all occurrences of word2.
 * If we find an occurrence of word2, we calculate the distance from word one and update the current minimum distance, if necessary.
 *
 * Time complexity: O(n * (number of occurrences of word1 * n))
 * Space complexity: O(1)
 */

int shortestDistance(vector<string>& words, string word1, string word2)
{
    if(words.empty())
    {
        return 0;
    }

    unordered_map<string, unordered_map<string, int>> table;

    int n=int(words.size());

    for(int i=0;i<n;++i)
    {
        string word=words[i];

        for(int j=0;j<n;++j)
        {
            int dist=abs(i-j);

            if(!table[word].count(words[j]))
            {
                table[word].insert(make_pair(words[j], dist));
            }
            else
            {
                if(dist < table[word][words[j]])
                {
                    table[word][words[j]]=dist;
                }
            }
        }
    }

    return table[word1][word2];
}

int shortestDistance(vector<string> & words, string word1, string word2)
{
    if(words.empty())
    {
        return 0;
    }

    int n=int(words.size());

    int result=numeric_limits<int>::max();

    for(int i=0;i<n;++i)
    {
        string first=words[i];

        if(first==word1)
        {
            for(int j=0;j<n;++j)
            {
                string second=words[j];

                if(second==word2)
                {
                    int currentDist=abs(j-i);

                    if(currentDist < result)
                    {
                        result=currentDist;
                    }
                }
            }
        }
    }

    return result;
}