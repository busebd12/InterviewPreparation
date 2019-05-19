#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfsBruteForce(vector<pair<int,int>> counts, int m, int n, int i)
{
    if(m < 0 || n < 0)
    {
        return -1;
    }

    if(i==counts.size())
    {
        return 0;
    }

    return max(dfsBruteForce(counts, m, n, i+1), 1 + dfsBruteForce(counts, m-counts[i].first, n-counts[i].second, i+1));
}
int findMaxFormBruteForce(vector<string>& strs, int m, int n)
{
    int k=int(strs.size());

    vector<pair<int,int>> counts(k);

    for(int i=0;i<k;i++)
    {
        string currentString=strs[i];

        int currentStringSize=int(strs[i].size());

        int zeroes=0;

        for(char c : currentString)
        {
            if(c=='0')
            {
                zeroes++;
            }
        }

        int ones=currentStringSize-zeroes;

        counts[i]=make_pair(zeroes, ones);
    }

    int i=0;

    return dfsBruteForce(counts, m, n, i);
}


int dfs(vector<vector<vector<int>>> & memoization, vector<pair<int, int>> & counts, int m, int n, int i)
{
    if(m < 0 || n < 0)
    {
        return -1;
    }

    if(i==counts.size())
    {
        return 0;
    }

    if(memoization[i][m][n] > -1)
    {
        return memoization[i][m][n];
    }

    return memoization[i][m][n]=max(1 + dfs(memoization, counts, m-counts[i].first, n-counts[i].second, i+1), dfs(memoization, counts, m, n, i+1));

}

int findMaxForm(vector<string>& strs, int m, int n)
{
    int k=int(strs.size());

    vector<pair<int,int>> counts(k);

    for(int i=0;i<k;i++)
    {
        string currentString=strs[i];

        int currentStringSize=int(strs[i].size());

        int zeroes=0;

        for(char c : currentString)
        {
            if(c=='0')
            {
                zeroes++;
            }
        }

        int ones=currentStringSize-zeroes;

        counts[i]=make_pair(zeroes, ones);
    }

    vector<vector<vector<int>>> memoization(k, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

    int i=0;

    return dfs(memoization, counts, m, n, i);
}
