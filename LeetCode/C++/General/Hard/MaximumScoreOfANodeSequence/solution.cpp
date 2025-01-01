#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/maximum-score-of-a-node-sequence/solutions/1953706/java-python-keep-3-biggest-neighbours/

Time complexity: O(e * log(3) + e) [where e=length of edges]
Space complexity: O(e)
*/

class Solution
{
    public:
        int maximumScore(vector<int> & scores, vector<vector<int>> & edges)
        {
            int result=-1;

            int e=edges.size();

            int s=scores.size();

            //Map each node to a sorted set of pairs {score of neighbour in graph, neighbour node} of three neighbours that have the highest score
            vector<set<pair<int, int>>> neighbourHeaps(s, set<pair<int, int>>());

            for(vector<int> edge : edges) //O(e) [where e=length of edges]
            {
                int u=edge[0];

                int v=edge[1];

                neighbourHeaps[u].emplace(scores[v], v);

                if(neighbourHeaps[u].size() > 3)
                {
                    neighbourHeaps[u].erase(neighbourHeaps[u].begin()); //O(log(k)) [where k=3]
                }

                neighbourHeaps[v].emplace(scores[u], u);

                if(neighbourHeaps[v].size() > 3)
                {
                    neighbourHeaps[v].erase(neighbourHeaps[v].begin()); //O(log(k)) [where k=3]
                }
            }

            for(vector<int> edge : edges) //O(e)
            {
                int u=edge[0];

                int v=edge[1];

                for(auto & [uNeighbourScore, uNeighbour] : neighbourHeaps[u]) //O(3)
                {
                    for(auto & [vNeighbourScore, vNeighbour] : neighbourHeaps[v]) //O(3)
                    {
                        if(uNeighbour!=v and vNeighbour!=u and uNeighbour!=vNeighbour)
                        {
                            int score=(scores[u] + scores[v] + uNeighbourScore + vNeighbourScore);

                            result=max(result, score);
                        }
                    }
                }
            }

            return result;
        }
};