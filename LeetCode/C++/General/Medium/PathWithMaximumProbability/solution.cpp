#include <deque>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        double maxProbability(int n, vector<vector<int>> & edges, vector<double> & succProb, int start, int end)
        {
            double result=0.0;

            int e=edges.size();

            vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());

            for(int i=0;i<e;i++)
            {
                int u=edges[i][0];

                int v=edges[i][1];

                double weight=succProb[i];

                graph[u].emplace_back(v, weight);

                graph[v].emplace_back(u, weight);
            }

            auto compareLikeThis=[] (const pair<int, double> & lhs, const pair<int, double> & rhs)
            {
                return lhs.second < rhs.second;
            };

            priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(compareLikeThis)> maxHeap(compareLikeThis);

            vector<bool> visited(e, false);

            maxHeap.emplace(start, 1.0);

            while(!maxHeap.empty())
            {
                auto [node, weight]=maxHeap.top();

                maxHeap.pop();

                if(node==end)
                {
                    result=weight;

                    return result;
                }

                if(visited[node]==true)
                {
                    continue;
                }

                visited[node]=true;

                for(auto & [neighbour, neighbourWeight] : graph[node])
                {
                    double nextWeight=weight * neighbourWeight;

                    maxHeap.emplace(neighbour, nextWeight);
                }
            }

            return 0.0;
        }
};

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> & edges, vector<double> & succProb, int start, int end)
    {
        double result=0.0;

        int e=edges.size();

        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());

        for(int i=0;i<e;i++)
        {
            int u=edges[i][0];

            int v=edges[i][1];

            double weight=succProb[i];

            graph[u].emplace_back(v, weight);

            graph[v].emplace_back(u, weight);
        }

        deque<pair<int, double>> queue;

        vector<double> distances(n, 0.0);

        distances[start]=1.0;

        queue.emplace_back(start, 1.0);

        while(!queue.empty())
        {
            auto [node, weight]=queue.front();

            queue.pop_front();

            for(auto & [neighbour, neighbourWeight] : graph[node])
            {
                double nextWeight=weight * neighbourWeight;

                if(nextWeight > distances[neighbour])
                {
                    distances[neighbour]=nextWeight;
                    
                    queue.emplace_back(neighbour, nextWeight);
                }
            }
        }

        return distances[end];
    }
};