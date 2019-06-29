#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>> & friends, unordered_set<int> & visited, int current)
{
    visited.insert(current);

    for(auto itr : friends[current])
    {
        if(!visited.count(itr))
        {
            dfs(friends, visited, itr);
        }
    }
}

int findCircleNum(vector<vector<int>>& M)
{
    int n=int(M.size());

    unordered_map<int, unordered_set<int>> friends;

    unordered_set<int> visited;

    int answer=0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i!=j && M[i][j])
            {
                friends[i].insert(j);
            }
        }
    }

    for(int i=0;i<n;++i)
    {
        if(!visited.count(i))
        {
            dfs(friends, visited, i);

            answer++;
        }
    }

    return answer;
}