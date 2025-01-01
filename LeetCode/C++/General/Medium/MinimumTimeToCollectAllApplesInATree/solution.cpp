#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int minTime(int n, vector<vector<int>> & edges, vector<bool> & hasApple)
        {
            int result=0;

            vector<vector<int>> graph(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int a=edge[0];

                int b=edge[1];

                graph[a].push_back(b);

                graph[b].push_back(a);
            }

            vector<bool> visited(n, false);

            int node=0;

            pair<bool, int> root=helper(graph, visited, hasApple, node);

            result=root.second;

            return result;
        }

        pair<bool, int> helper(vector<vector<int>> & graph, vector<bool> & visited, vector<bool> & hasApple, int node)
        {
            visited[node]=true;
            
            pair<bool, int> p(false, 0);

            if(hasApple[node]==true and node!=0)
            {
                p.first=true;

                p.second+=2;
            }

            bool childrenHaveApples=false;

            for(int neighbour : graph[node])
            {
                if(visited[neighbour]==false)
                {
                    pair<bool, int> child=helper(graph, visited, hasApple, neighbour);

                    if(child.first==true)
                    {
                        childrenHaveApples=true;

                        p.first=p.first or child.first;
                        
                        p.second+=child.second;
                    }
                }
            }

            if(childrenHaveApples==true and (node!=0 and hasApple[node]==false))
            {
                p.second+=2;
            }

            return p;
        }
};