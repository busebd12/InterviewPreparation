#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Generate and store all possible subsequences for string a and b. Then, find the
 * longest uncommon subsequence.
 *
 * Time complexity: O(2^n + 2^m) [where n is the length of string a and m is the length of string b]
 * Space complexity: O(2^n + 2^m)
 *
 * 2) Remove common characters from both strings and then we are left with several cases to cover.
 * a. If string a is empty, then the result is the number of common characters plus the length of string b.
 * b. If string b is empty, then the result is the number of common characters plus the length of string a.
 * c. If neither string is empty, then the result is the max between the lengths of the two strings.
 * d. If neither string is empty and the two strings are different, then the result is the length of the longer string.
 * e. If both strings are empty, then the result is -1.
 *
 * Time complexity: O(n + m) [where n is the length of string a and m is the length of string b]
 * Space complexity: O(n + m)
 *
 * 3) Same approach as the prior solution except we don't delete the common characters, we just count them.
 *
 * Time complexity: O(n + m)
 * Space complexity: O(1)
 */

void generateSubsequences(string str, unordered_set<string> & subsequences, string subsequence, int index)
{
    if(subsequence.size() >= 1)
    {
        subsequences.insert(subsequence);
    }

    for(int i=index;i<str.size();++i)
    {
        subsequence+=str[i];

        generateSubsequences(str, subsequences, subsequence, i+1);

        subsequence.pop_back();
    }
}

int findLUSlength(string a, string b)
{
    if(a.empty() && b.empty())
    {
        return -1;
    }

    if(a.empty())
    {
        return int(b.size());
    }

    if(b.empty())
    {
        return int(a.size());
    }

    unordered_set<string> aSubsequences;

    unordered_set<string> bSubsequences;

    string subsequence{};

    int index=0;

    generateSubsequences(a, aSubsequences, subsequence, index);

    generateSubsequences(b, bSubsequences, subsequence, index);

    int result=-1;

    for(const string & s : aSubsequences)
    {
        if(!bSubsequences.count(s))
        {
            result=max(result, int(s.size()));
        }
    }

    for(const string & s : bSubsequences)
    {
        if(!aSubsequences.count(s))
        {
            result=max(result, int(s.size()));
        }
    }

    return result;
}

int findLUSlength(string a, string b)
{
    if(a.empty() && b.empty())
    {
        return -1;
    }

    if(a.empty())
    {
        return int(b.size());
    }

    if(b.empty())
    {
        return int(a.size());
    }

    int n=int(a.size());

    int m=int(b.size());

    vector<int> hashtable(26, 0);

    int commonCharacters=0;

    string aCopy=a;

    string bCopy=b;

    for(int i=0;i<n;++i)
    {
        char letter=aCopy[i];

        size_t position=bCopy.find(letter);

        if(position!=string::npos)
        {
            hashtable[letter - 'a']++;

            commonCharacters++;

            bCopy.erase(bCopy.begin() + position);
        }
    }

    for(int index=0;index<hashtable.size();++index)
    {
        if(hashtable[index] > 0)
        {
            int total=hashtable[index];

            char letter=index + 'a';

            for(int count=0;count<total;++count)
            {
                size_t position=aCopy.find_first_of(letter);

                aCopy.erase(aCopy.begin() + position);
            }
        }
    }

    int result=-1;

    if(aCopy.empty() && !bCopy.empty())
    {
        result=commonCharacters + int(bCopy.size());
    }
    else if(!aCopy.empty() && bCopy.empty())
    {
        result=commonCharacters + int(aCopy.size());
    }
    else if(!aCopy.empty() && !bCopy.empty())
    {
        result=max(int(aCopy.size()), int(bCopy.size()));
    }

    if(a!=b)
    {
        result=max(result, max(int(a.size()), int(b.size())));
    }

    return result;
}

int findLUSlength(string a, string b)
{
    if(a.empty() && b.empty())
    {
        return -1;
    }

    if(a.empty())
    {
        return int(b.size());
    }

    if(b.empty())
    {
        return int(a.size());
    }

    int n=int(a.size());

    int m=int(b.size());

    int commonCharacters=0;

    for(int i=0;i<n;++i)
    {
        char letter=a[i];

        size_t position=b.find(letter);

        if(position!=string::npos)
        {
            commonCharacters++;
        }
    }

    int result=-1;

    int aLengthWithoutCommonCharacters=n - commonCharacters;

    int bLengthWithoutCommonCharacters=m - commonCharacters;

    if(aLengthWithoutCommonCharacters==0 && bLengthWithoutCommonCharacters > 0)
    {
        result=commonCharacters + bLengthWithoutCommonCharacters;
    }
    else if(aLengthWithoutCommonCharacters > 0 && bLengthWithoutCommonCharacters==0)
    {
        result=commonCharacters + aLengthWithoutCommonCharacters;
    }
    else if(aLengthWithoutCommonCharacters > 0 && bLengthWithoutCommonCharacters > 0)
    {
        result=max(aLengthWithoutCommonCharacters, bLengthWithoutCommonCharacters);
    }

    if(a!=b)
    {
        result=max(result, max(int(a.size()), int(b.size())));
    }

    return result;
}