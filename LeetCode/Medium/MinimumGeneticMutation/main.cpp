#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

void dfs(vector<string> & bank, unordered_set<string> & visited, string & start, string & end, int & mutations, int & count)
{
    if(start==end)
    {
        mutations=min(mutations, count);
    }

    for(auto & str : bank)
    {
        int differences=0;

        for(int i=0;i<int(str.size());++i)
        {
            if(start[i]!=str[i])
            {
                ++differences;

                if(differences > 1)
                {
                    break;
                }
            }
        }

        if(differences==1 && visited.count(str)==0)
        {
            visited.insert(str);

            dfs(bank, visited, str, end, mutations, count+=1);

            visited.erase(str);

            count--;
        }
    }
}

int minMutation(string & start, string & end, vector<string> & bank)
{
    int mutations=numeric_limits<int>::max();

    unordered_set<string> visited;

    int count=0;

    dfs(bank, visited, start, end, mutations, count);

    return (mutations==numeric_limits<int>::max()) ? -1 : mutations;
}