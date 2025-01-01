#include <deque>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/circular-array-loop/solutions/1388596/topological-sort-c/

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        bool circularArrayLoop(vector<int> & nums)
        {
            int n=nums.size();

            vector<vector<int>> graph(n, vector<int>());

            vector<int> indegree(n, 0);

            for(int from=0;from<n;from++)
            {
                int to=((from + nums[from]) % n + n) % n;

                if(from==to or nums[from] * nums[to] < 0)
                {
                    continue;
                }

                graph[from].push_back(to);

                indegree[to]+=1;
            }

            deque<int> queue;

            for(int vertex=0;vertex<n;vertex++)
            {
                if(indegree[vertex]==0)
                {
                    queue.push_back(vertex);
                }
            }

            int cycleLength=0;

            while(!queue.empty())
            {
                int current=queue.front();

                queue.pop_front();

                for(int neighbour : graph[current])
                {
                    indegree[neighbour]-=1;

                    if(indegree[neighbour]==0)
                    {
                        queue.push_back(neighbour);
                    }
                }

                cycleLength+=1;
            }

            return cycleLength!=n;
        }
};