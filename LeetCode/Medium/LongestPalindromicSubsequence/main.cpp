#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <unordered_map>
using namespace std;

bool isPalindrome(const string & subsequence)
{
    int start=0;

    int end=int(subsequence.size()-1);

    while(start < end)
    {
        if(!isalnum(subsequence[start]))
        {
            start++;
        }
        else if(!isalnum(subsequence[end]))
        {
            end--;
        }
        else
        {
            if(tolower(subsequence[start])!=tolower(subsequence[end]))
            {
                return false;
            }

            start++;

            end--;
        }
    }

    return true;
}

void dfs(string & s, string & subsequence, const int n, int & result, int index)
{
    if(index==n)
    {
        return;
    }

    if(isPalindrome(subsequence))
    {
        result=max(result, int(subsequence.size()));
    }

    for(int i=index+1;i<n;++i)
    {
        subsequence+=s[i];

        dfs(s, subsequence, n, result, i);

        subsequence.pop_back();
    }
}

int longestPalindromeSubseqV1(string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    string subsequence{};

    int n=int(s.size());

    int start=-1;

    dfs(s, subsequence, n, result, start);

    return result;
}

int dfs(string & s, int left, int right)
{
    if(left > right)
    {
        return 0;
    }

    if(left==right)
    {
        return 1;
    }

    if(s[left]==s[right])
    {
        return 2 + dfs(s, left+1, right-1);
    }
    else
    {
        return max(dfs(s, left+1, right), dfs(s, left, right-1));
    }
}

int longestPalindromeSubseqV2(string s)
{
    if(s.empty())
    {
        return 0;
    }

    int left=0;

    int right=int(s.size()-1);

    return dfs(s, left, right);
}

int dfsWithMemoization(string & s, vector<vector<int>> & memoization, int left, int right)
{
    if(left > right)
    {
        return 0;
    }

    if(left==right)
    {
        return 1;
    }

    if(memoization[left][right])
    {
        return memoization[left][right];
    }

    if(s[left]==s[right])
    {
        memoization[left][right]=2 + dfsWithMemoization(s, memoization, left+1, right-1);
    }
    else
    {
        memoization[left][right]=max(dfsWithMemoization(s, memoization, left+1, right), dfsWithMemoization(s, memoization, left, right-1));
    }

    return memoization[left][right];
}

int longestPalindromeSubseq(string s)
{
    if(s.empty())
    {
        return 0;
    }

    int n=int(s.size());

    int left=0;

    int right=n-1;

    vector<vector<int>> memoization(n, vector<int>(n, 0));

    return dfsWithMemoization(s, memoization, left, right);
}