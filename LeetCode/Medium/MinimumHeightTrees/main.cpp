#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <numeric>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>> & edges)
{
    vector<int> result;

    if(n==1)
    {
        result.emplace_back(0);

        return result;
    }

    if(edges.empty())
    {
        return result;
    }

    vector<unordered_set<int>> graph(n);

    for(const auto & e : edges)
    {
        graph[e.first].insert(e.second);

        graph[e.second].insert(e.first);
    }

    vector<int> leaves;

    for(int i=0;i<n;++i)
    {
        if(graph[i].size()==1)
        {
            leaves.emplace_back(i);
        }
    }

    while(true)
    {
        vector<int> newLeaves;

        for(auto & leaf : leaves)
        {
            for(auto & neighbor : graph[leaf])
            {
                graph[neighbor].erase(leaf);

                if(graph[neighbor].size()==1)
                {
                    newLeaves.emplace_back(neighbor);
                }
            }
        }

        if(newLeaves.empty())
        {
            break;
        }

        leaves=newLeaves;
    }

    return leaves;
}