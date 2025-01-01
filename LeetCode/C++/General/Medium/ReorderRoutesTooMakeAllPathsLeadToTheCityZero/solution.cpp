#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: insipred by this post --> https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/solutions/883378/python3-simple-bfs-solution-with-explanation/

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int minReorder(int n, vector<vector<int>> & connections)
        {
            int result=0;

            vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

            for(vector<int> & connection : connections)
            {
                int parent=connection[0];

                int child=connection[1];

                graph[parent].emplace_back(child, 1);

                graph[child].emplace_back(parent, 0);
            }

            vector<bool> visited(n, false);

            int root=0;

            visited[root]=true;

            deque<int> queue;

            queue.emplace_back(root);

            while(!queue.empty())
            {
                int node=queue.front();

                queue.pop_front();

                for(auto & [neighbour, cost] : graph[node])
                {
                    if(visited[neighbour]==false)
                    {
                        visited[neighbour]=true;

                        if(cost > 0)
                        {
                            result+=1;
                        }

                        queue.push_back(neighbour);
                    }
                }
            }

            return result;
        }
};