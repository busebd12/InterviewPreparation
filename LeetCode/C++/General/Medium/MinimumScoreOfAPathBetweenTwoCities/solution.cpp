#include <algorithm>
#include <deque>
#include <limits>
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
        int minScore(int n, vector<vector<int>> & roads)
        {
            const int INF=numeric_limits<int>::max();
            
            int result=INF;

            vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());

            vector<bool> visited(n + 1, false);

            for(vector<int> & road : roads)
            {
                int a=road[0];

                int b=road[1];

                int distance=road[2];

                graph[a].emplace_back(b, distance);

                graph[b].emplace_back(a, distance);
            }

            deque<int> queue;

            queue.emplace_back(1);

            while(!queue.empty())
            {
                auto city=queue.front();

                queue.pop_front();

                if(visited[city]==true)
                {
                    continue;
                }

                visited[city]=true;

                for(auto & [neighbour, distance] : graph[city])
                {
                    result=min(result, distance);

                    queue.push_back(neighbour);
                }
            }

            return result;
        }
};