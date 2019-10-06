#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * Approach: we use a hashtable to map each word to a list of words that it is similar to.
 * For each pair of words, x and y, since similarity is symmetrical, we know that y will
 * be in x's list of similar words and x will be in y's list of similar words. Also, because
 * each word is similar with itself (reflexsive), a word x will be in its own list of similar words.
 * Then, for each word in the two sentences, we check the following:
 *
 * a) if neither of the words are in the hashtable (i.e. they weren't a pair), then the only way they can
 * be similar is if they are the same. If they are not, return false.
 *
 * b) If one of the words is not similar to the other, return false.
 *
 * After looping over both sentences, we know that both sentences are similar and we can return true.
 *
 * Time complexity: O(n) [where n is the length of both words1 and words2]
 * Space complexity: O(p) [where p is the number of pairs of similar words]
 */

bool areSentencesSimilar(vector<string> & words1, vector<string> & words2, vector<vector<string>> & pairs)
{
    if(words1.empty() && words2.empty())
    {
        return true;
    }

    if(words1.empty() || words2.empty())
    {
        return false;
    }

    if(words1.size()!=words2.size())
    {
        return false;
    }

    size_t n=words1.size();

    unordered_map<string, unordered_set<string>> hashtable;

    for(const auto & p : pairs)
    {
        hashtable[p[0]].insert(p[0]);

        hashtable[p[0]].insert(p[1]);

        hashtable[p[1]].insert(p[0]);

        hashtable[p[1]].insert(p[1]);
    }

    for(size_t index=0;index<n;++index)
    {
        string word1=words1[index];

        string word2=words2[index];

        if(!hashtable.count(word2) && !hashtable.count(word1))
        {
            if(word1!=word2)
            {
                return false;
            }
        }
        else
        {
            if(!hashtable[word1].count(word2) || !hashtable[word2].count(word1))
            {
                return false;
            }
        }
    }

    return true;
}