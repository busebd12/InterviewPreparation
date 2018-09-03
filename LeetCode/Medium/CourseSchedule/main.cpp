#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
using namespace std;

bool canCompletePath(vector<vector<int>> & graph, unordered_set<int> & path, int current)
{
    if(path.count(current))
    {
        return false;
    }

    path.insert(current);

    for(auto & next : graph[current])
    {
        if(!canCompletePath(graph, path, next))
        {
            return false;
        }
    }

    path.erase(current);

    graph[current].clear();

    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>> prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());

    for(const auto & p : prerequisites)
    {
        graph[p.first].emplace_back(p.second);
    }

    unordered_set<int> path;

    for(int i=0;i<numCourses;++i)
    {
        if(!canCompletePath(graph, path, i))
        {
            return false;
        }
    }

    return true;
}