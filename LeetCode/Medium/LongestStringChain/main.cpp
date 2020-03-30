#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion + depth-first search. The idea is to built the chain backwards. Instead of adding characters to a word,
 * we delete characters from the word and then recurse on the string. We choose each word in the words list as a starting
 * point and our base case is when the word resulting from the deletion of chracters is not in the hashtable or the word
 * is empty.
 *
 * Time complexity: O(n^2 * w * n log n) [where n is the length of the input words list and w is the average length of a word]
 * Space complexity: O(n * w)
 *
 * 2. Almost the same as the first solution except that we don't need to sort the input list of words by length since
 * we will choose each word as a starting point, regardless of length.
 *
 * Time complexity: O(n^2 * w) [where n is the length of the input word list and w is the average length of a word]
 * Space complexity: O(n * w)
 *
 * 3. Similar approach to the first two solutions except that we only recurse for words that are in the hashtable.
 *
 * Time complexity: O(n^2 * w) [where n is the length of the input word list and w is the average length of a word]
 * Space complexity: O(n * w)
 *
 * 4. Memoized version of the third solution.
 *
 * Time complexity: O(n) [where n is the length of the input word list and w is the average length of a word]
 * Space complexity: O(n * w)
 *
 * 5. Breadth-first search approach.
 *
 * Time complexity: O(n^2 * w)
 * Space complexity: O(n * w)
 */

void dfs(std::unordered_multiset<std::string> & hashtable, const std::string & word, int & result, int length)
{
    if(!hashtable.count(word) || word.empty())
    {
        result=std::max(result, length);

        return;
    }

    auto w=word.size();

    for(auto index=0;index<w;++index)
    {
        std::string copy=word;

        auto itr=copy.begin() + index;

        copy.erase(itr);

        dfs(hashtable, copy, result, length + 1);
    }
}

int longestStrChain(std::vector<std::string> & words)
{
    int result=0;

    if(words.empty())
    {
        return result;
    }

    std::unordered_multiset<std::string> hashtable(words.begin(), words.end());

    std::sort(words.begin(), words.end());

    int n=int(words.size());

    for(auto index=n-1;index>=0;--index)
    {
        int length=0;

        dfs(hashtable, words[index], result, length);
    }

    return result;
}

void dfs(std::unordered_multiset<std::string> & hashtable, const std::string & word, int & result, int length)
{
    if(!hashtable.count(word) || word.empty())
    {
        result=std::max(result, length);

        return;
    }

    auto w=word.size();

    for(auto index=0;index<w;++index)
    {
        std::string copy=word;

        auto itr=copy.begin() + index;

        copy.erase(itr);

        dfs(hashtable, copy, result, length + 1);
    }
}

int longestStrChain(std::vector<std::string> & words)
{
    int result=0;

    if(words.empty())
    {
        return result;
    }

    std::unordered_multiset<std::string> hashtable(words.begin(), words.end());

    for(auto & word : words)
    {
        int length=0;

        dfs(hashtable, word, result, length);
    }

    return result;
}

int dfs(std::unordered_set<std::string> & hashtable, const std::string & word)
{
    int subproblem=0;

    auto w=word.size();

    for(auto index=0;index<w;++index)
    {
        std::string copy=word;

        auto itr=copy.begin() + index;

        copy.erase(itr);

        if(hashtable.count(copy))
        {
            subproblem=std::max(subproblem, dfs(hashtable, copy));
        }
    }

    subproblem+=1;

    return subproblem;
}

int longestStrChain(std::vector<std::string> & words)
{
    int result=0;

    if(words.empty())
    {
        return result;
    }

    std::unordered_set<std::string> hashtable(words.begin(), words.end());

    for(auto & word : words)
    {
        result=std::max(result, dfs(hashtable, word));
    }

    return result;
}

int dfs(std::unordered_set<std::string> & hashtable, std::unordered_map<std::string, int> & memo, const std::string & word)
{
    if(memo.count(word))
    {
        return memo[word];
    }

    int subproblem=0;

    auto w=word.size();

    for(auto index=0;index<w;++index)
    {
        std::string copy=word;

        auto itr=copy.begin() + index;

        copy.erase(itr);

        if(hashtable.count(copy))
        {
            subproblem=std::max(subproblem, dfs(hashtable, memo, copy));
        }
    }

    subproblem+=1;

    memo[word]=subproblem;

    return memo[word];
}

int longestStrChain(std::vector<std::string> & words)
{
    int result=0;

    if(words.empty())
    {
        return result;
    }

    std::unordered_set<std::string> hashtable(words.begin(), words.end());

    std::unordered_map<std::string, int> memo;

    for(auto & word : words)
    {
        result=std::max(result, dfs(hashtable, memo, word));
    }

    return result;
}

int longestStrChain(std::vector<std::string> & words)
{
    int result=0;

    if(words.empty())
    {
        return result;
    }

    std::unordered_multiset<std::string> hashtable(words.begin(), words.end());

    for(auto & word : words)
    {
        int length=0;

        std::queue<std::pair<std::string, int>> Q;

        Q.emplace(std::make_pair(word, 0));

        while(!Q.empty())
        {
            auto qSize=Q.size();

            bool done=false;

            for(auto count=0;count<qSize;++count)
            {
                auto current=Q.front();

                Q.pop();

                if(!hashtable.count(current.first) || current.first.empty())
                {
                    result=std::max(result, current.second);

                    done=true;
                }

                if(done)
                {
                    break;
                }

                auto w=current.first.size();

                for(auto index=0;index<w;++index)
                {
                    std::string copy=current.first;

                    auto itr=copy.begin() + index;

                    copy.erase(itr);

                    Q.emplace(std::make_pair(copy, current.second + 1));
                }
            }
        }
    }

    return result;
}