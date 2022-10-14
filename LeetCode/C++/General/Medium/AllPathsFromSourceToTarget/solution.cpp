#include <deque>
#include <vector>
using namespace std;

/*
Solution 1: recursive depth-first traversal of all the paths.

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
Space complexity: O(V + E)
*/

class Solution
{
    private:
        vector<vector<int>> result;
    
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph)
        {
            int source=0;
            
            int n=graph.size();
            
            vector<int> path={source};
            
            dfs(graph, path, n, source);
            
            return result;
        }
    
        void dfs(vector<vector<int>> & graph, vector<int> & path, int & n, int source)
        {
            if(source==n-1)
            {   
                result.push_back(path);
            }
            
            for(int neighbour : graph[source])
            {
                path.push_back(neighbour);
                
                dfs(graph, path, n, neighbour);
                
                path.pop_back();
            }
        }
};

/*
Solution 2: iterative depth-first traversal of all the paths.

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
Space complexity: O(V + E)
*/

class Solution
{
    private:
        vector<vector<int>> result;
    
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph)
        {
            int source=0;
            
            int n=graph.size();
            
            vector<int> path={source};
            
            dfs(graph, path, n, source);
            
            return result;
        }
    
        void dfs(vector<vector<int>> & graph, vector<int> & path, int & n, int source)
        {
            deque<vector<int>> stack;
            
            stack.push_back(path);
            
            while(!stack.empty())
            {
                vector<int> current=stack.front();
                
                stack.pop_front();
                
                if(current.back()==n-1)
                {
                    result.push_back(current);
                }
                else
                {
                    for(int neighbour : graph[current.back()])
                    {
                        current.push_back(neighbour);
                        
                        stack.push_back(current);
                        
                        current.pop_back();
                    }
                }
            }
        }
};

/*
Solution 3: iterative breadth-first traversal of all the paths.

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
Space complexity: O(V + E)
*/

class Solution
{
    private:
        vector<vector<int>> result;
    
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph)
        {
            int source=0;
            
            int n=graph.size();
            
            vector<int> path={source};
            
            bfs(graph, path, n, source);
            
            return result;
        }
    
        void bfs(vector<vector<int>> & graph, vector<int> & path, int & n, int source)
        {
            deque<vector<int>> queue;
            
            queue.push_back(path);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    vector<int> current=queue.front();
                
                    queue.pop_front();

                    if(current.back()==n-1)
                    {
                        result.push_back(current);
                    }
                    else
                    {
                        for(int neighbour : graph[current.back()])
                        {
                            current.push_back(neighbour);

                            queue.push_back(current);

                            current.pop_back();
                        }
                    }
                }
            }
        }
};