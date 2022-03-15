#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Solution: do the following

1) Sort the words by length (ascending)
2) Each word by itself has a string chain length of 1. Map each word to a length of one.
3) For each word, create a copy, and then iterate through the copy word, deleting one character
at a time as we go. After deleting a letter, check the hashtable to see if the new word + 1 will
form a longer string chain than just the current word. If so, update the longest string chain for
the current word. After finishing with the current word, update the result variable to be the max
between result and the longest string chain for the current word.
4) After iterating through all the words, return the max length string chain.

Time complexity: O((w log w) + O(w) + (O(w * L)) [where w is the total number of words and L is the average length of a word]
Space complexity: O(w);
*/

class Solution
{
    public:
        int longestStrChain(vector<string> & words)
        {
            int result=0;
    
            sort(words.begin(), words.end(), [](const string & w1, const string & w2) {return w1.size() < w2.size();});

            unordered_map<string, int> hashtable;

            for(const string & word : words)
            {
                hashtable.insert(make_pair(word, 1));
            }

            for(string word : words)
            {
                string next=word;

                int n=next.size();

                for(int index=0;index<n;index++)
                {
                    int chainLength=hashtable[word];

                    char letter=next[index];

                    next.erase(next.begin() + index);

                    if(hashtable.count(next) && hashtable[next] + 1 > hashtable[word])
                    {
                        hashtable[word]=hashtable[next] + 1;
                    }

                    next.insert(next.begin() + index, letter);
                }

                result=max(result, hashtable[word]);
            }
            
            return result;
        }
};