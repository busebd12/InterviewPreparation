#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> countSubTrees(int n, vector<vector<int>> & edges, string labels)
        {
            vector<int> result(n, 0);

            vector<vector<int>> graph(n, vector<int>());

            for(vector<int> edge : edges)
            {
                int a=edge[0];

                int b=edge[1];

                graph[a].push_back(b);

                graph[b].push_back(a);
            }

            vector<bool> visited(n, false);

            int parent=-1;

            int node=0;

            helper(graph, result, labels, parent, node);

            return result;
        }

        vector<int> helper(vector<vector<int>> & graph, vector<int> & result, string & labels, int parent, int node)
        {
            vector<int> parentFrequencies(26, 0);

            char label=labels[node];

            for(int child : graph[node])
            {
                if(child!=parent)
                {
                    vector<int> childFrequencies=helper(graph, result, labels, node, child);

                    for(int index=0;index<26;index++)
                    {
                        parentFrequencies[index]+=childFrequencies[index];
                    }
                }
            }

            parentFrequencies[label - 'a']+=1;

            result[node]=parentFrequencies[label - 'a'];

            return parentFrequencies;
        }
};