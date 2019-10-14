#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) For each character in the string, do the following:
 *
 * a) If the character is a letter: if the letter is lowercase, convert it to uppercase and then recurse.
 * Then, recurse without changing the lowercase to uppercase. It the letter is uppercase, convert it to lowercase
 * and then recurse. Also, recurse without changing the character to lowercase.
 *
 * b) If the character is a number, just continue looping through the string
 *
 * Since this code generates duplicates, we use an unordered_set<string> cache to remove duplicates from the end result.
 *
 * Time complexity: exponential --> O(2^n)
 * Space complexity: O(2^n)
 *
 *
 * 2) Similar approach, but much cleaner and faster. If the current character is a letter, store the original state of
 * the character, convert the character to either uppercase or lowercase, depending, and then recurse. After returning
 * from our recursive call, if the current letter is character undo the change we just made to the current character
 * and then recurse.
 *
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 *
 *
 */

void backtracking(string S, unordered_set<string> & cache, string str, const size_t & n, size_t start)
{
    if(start >= n-1)
    {
        if(!cache.count(S))
        {
            cache.insert(S);
        }
    }

    for(size_t i=start;i<n;++i)
    {
        if(isalpha(S[i]))
        {
            if(islower(S[i]))
            {
                S[i]=char(toupper(S[i]));

                backtracking(S, cache, str, n, i+1);

                S[i]=char(tolower(S[i]));

                backtracking(S, cache, str, n, i+1);
            }
            else
            {
                S[i]=char(tolower(S[i]));

                backtracking(S, cache, str, n, i+1);

                S[i]=char(toupper(S[i]));

                backtracking(S, cache, str, n, i+1);
            }
        }
        else
        {
            backtracking(S, cache, str, n, i+1);
        }
    }
}

vector<string> letterCasePermutation(string S)
{
    vector<string> result;

    if(S.empty())
    {
        return result;
    }

    size_t n=S.size();

    size_t start=0;

    string str{};

    unordered_set<string> cache;

    backtracking(S, cache, str, n, start);

    for(const string & str : cache)
    {
        result.push_back(str);
    }

    return result;
}

void backtracking(string & S, vector<string> & result, size_t i)
{
    if(i==S.size())
    {
        result.push_back(S);

        return;
    }

    char beforeChange=S[i];

    if(isalpha(beforeChange))
    {
        S[i]=(islower(S[i])) ? char(toupper(S[i])) : char(tolower(S[i]));
    }

    backtracking(S, result, i+1);

    if(isalpha(beforeChange))
    {
        S[i]=beforeChange;

        backtracking(S, result, i+1);
    }
}

vector<string> letterCasePermutation(string S)
{
    vector<string> result;

    if(S.empty())
    {
        return result;
    }

    size_t i=0;

    backtracking(S, result, i);

    return result;
}