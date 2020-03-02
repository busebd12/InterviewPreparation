#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Backtracking. We try to form the input string by choosing each word, recursing, and then un-choosing each word.
 *
 * Time complexity: O(2^w * n) [where n is the length of the input string and w is the number of words in the dictionary]
 * Space complexity: O(n)
 *
 * 2. Recursion + depth-first search. We start from the beginning of the string and if a word from the dictionary starts
 * with the same letter as the current letter in the string, we move our index up the length of that word in the string
 * and recurse.
 *
 * Time complexity: O(n^w) [where n is the length of the input string and w is the number of words in the dictionary]
 * Space complexity: O(n)
 *
 * 3. Recursion + depth-first search + memoization.
 *
 * Time complexity: O(n^2 * w) [where n is the length of the input string and w is the number of words in the dictionary]
 * Space complexity: O(n)
 */

void backtracking(std::string & s, std::vector<std::string> & wordDict, std::vector<std::string> & candidate, int & n, int characters, bool & found)
{
    if(found)
    {
        return;
    }

    if(characters==n)
    {
        std::string str{};

        for(auto & element : candidate)
        {
            str+=element;
        }

        if(str==s)
        {
            found=true;
        }
    }

    for(auto & word : wordDict)
    {
        auto length=characters + word.size();

        if(length > n)
        {
            continue;
        }

        candidate.push_back(word);

        characters+=static_cast<int>(word.size());

        backtracking(s, wordDict, candidate, n, characters, found);

        characters-=static_cast<int>(candidate.back().size());

        candidate.pop_back();
    }
}

bool wordBreak(std::string & s, std::vector<std::string> & wordDict)
{
    if(s.empty() || wordDict.empty())
    {
        return false;
    }

    int n=int(s.size());

    std::vector<std::string> candidate;

    int characters=0;

    bool found=false;

    backtracking(s, wordDict, candidate, n, characters, found);

    return found;
}


bool dfs(std::string & s, std::unordered_set<std::string> dictionary, int & n, int index)
{
    if(index==n)
    {
        return true;
    }

    if(index > n)
    {
        return false;
    }

    for(auto & word : dictionary)
    {
        if(word[0]==s[index])
        {
            int wordLength=static_cast<int>(word.size());

            std::string substring=s.substr(index, wordLength);

            if(dictionary.count(substring))
            {
                if(dfs(s, dictionary, n, index + wordLength))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool wordBreak(std::string & s, std::vector<std::string> & wordDict)
{
    if(s.empty() || wordDict.empty())
    {
        return false;
    }

    int n=int(s.size());

    std::unordered_set<std::string> dictionary(wordDict.begin(), wordDict.end());

    int index=0;

    bool result=dfs(s, dictionary, n, index);

    return result;
}

bool memoization(std::string & s, std::unordered_set<std::string> dictionary, std::vector<int> & memo, int & n, int index)
{
    if(index==n)
    {
        return true;
    }

    if(index > n)
    {
        return false;
    }

    if(memo[index]!=-1)
    {
        return memo[index];
    }

    bool subproblem=false;

    for(auto & word : dictionary)
    {
        if(word[0]==s[index])
        {
            int wordLength=static_cast<int>(word.size());

            std::string substring=s.substr(index, wordLength);

            if(dictionary.count(substring))
            {
                if(memoization(s, dictionary, memo, n, index + wordLength))
                {
                    subproblem=true;

                    break;
                }
            }
        }
    }

    if(subproblem)
    {
        memo[index]=1;
    }
    else
    {
        memo[index]=0;
    }

    return memo[index];
}

bool wordBreak(std::string & s, std::vector<std::string> & wordDict)
{
    if(s.empty() || wordDict.empty())
    {
        return false;
    }

    int n=int(s.size());

    std::unordered_set<std::string> dictionary(wordDict.begin(), wordDict.end());

    std::vector<int> memo(n, -1);

    int index=0;

    bool result=memoization(s, dictionary, memo, n, index);

    return result;
}