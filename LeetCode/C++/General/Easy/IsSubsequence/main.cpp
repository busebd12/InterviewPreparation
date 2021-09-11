#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursion. We use an unordered_map<char, vector<int>> as our hashtable and
 * map each letter in t to all the indices at which it appears in t.
 * Then, we go through each letter in s and check if it is in the hashtable (aka, in string t).
 * If it isn't, then we return false. If it is, we check to see if there is an index that is larger
 * than the previous index for the previous letter in s (this way we maintain the order of the letters).
 * If there is, we recurse for the next letter. If we reach the length of s and we have found all the letters,
 * in the correct order, we return true. Else, we return false.
 *
 * Time complexity: O(n * m) [where n is the length of s and m is the length of t)
 * Space complexity: O(n * m) recursive stack space used.
 *
 * 2) We use two-pointers to loop over s and t. If the current character in s equals the current character in t,
 * then we increment our s and t pointers. Otherwise, we just increment our t pointer.
 *
 * Time complexity: O(n + m) [where n is the length of s and m is the length of t]
 * Space complexity: O(1)
 */

bool dfs(unordered_map<char, vector<int>> & hashtable, string s, int n, int i, int previousIndex, int count)
{
    if(i==n)
    {
        return (count==n) ? true : false;
    }

    char letter=s[i];

    if(!hashtable.count(s[i]))
    {
        return false;
    }

    for(int index : hashtable[letter])
    {
        if(index > previousIndex || previousIndex==-1)
        {
            return dfs(hashtable, s, n, i+1, index, count+1);
        }
    }

    return false;
}

bool isSubsequence(string s, string t)
{
    if(s.empty())
    {
        return true;
    }

    if(t.empty())
    {
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    unordered_map<char, vector<int>> hashtable;

    int n=int(s.size());

    int m=int(t.size());

    for(int i=0;i<m;++i)
    {
        hashtable[t[i]].push_back(i);
    }

    int i=0;

    int previousIndex=-1;

    int count=0;

    return dfs(hashtable, s, n, i, previousIndex, count);
}

bool isSubsequence(string s, string t)
{
    if(s.empty())
    {
        return true;
    }

    if(t.empty())
    {
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int count=0;

    int n=int(s.size());

    int m=int(t.size());

    for(int i=0;i<m;++i)
    {
        if(t[i]==s[count])
        {
            count++;
        }
    }

    return count==n;
}