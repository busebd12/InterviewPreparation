#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void dfs(string & str, unordered_map<string, int> & subsequences, string & subsequence, const int & n, int index)
{
    if(index==n)
    {
        return;
    }

    if(!subsequences.count(subsequence))
    {
        subsequences.insert(make_pair(subsequence, 1));
    }
    else
    {
        subsequences[subsequence]++;
    }

    for(int i=index+1;i<n;++i)
    {
        subsequence+=str[i];

        dfs(str, subsequences, subsequence, n, i);

        subsequence.pop_back();
    }
}

int findLUSlength(vector<string> & strs)
{
    int result=-1;

    if(strs.empty())
    {
        return result;
    }

    unordered_map<string, int> subsequences;

    for(auto & str : strs)
    {
        string subsequence{};

        int n=int(str.size());

        int index=-1;

        dfs(str, subsequences, subsequence, n, index);
    }

    for(auto & element : subsequences)
    {
        if(element.second==1)
        {
            result=max(result, int(element.first.size()));
        }
    }

    return result;
}