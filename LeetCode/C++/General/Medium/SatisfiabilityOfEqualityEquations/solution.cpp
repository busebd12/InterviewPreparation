#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: graph + recursive depth-first traversal.
*/

class Solution
{
    public:
        bool equationsPossible(vector<string> & equations)
        {
            int e=equations.size();
            
            unordered_map<char, vector<char>> graph;
            
            for(string equation : equations)
            {
                if(equation[1]=='=')
                {
                    char u=equation[0];
                    
                    char v=equation[3];
                    
                    if(graph.find(u)==end(graph))
                    {
                        graph.emplace(u, vector<char>());
                    }
                    
                    graph[u].push_back(v);
                    
                    if(graph.find(v)==end(graph))
                    {
                        graph.emplace(v, vector<char>());
                    }
                    
                    graph[v].push_back(u);
                }
            }
            
            for(string equation : equations)
            {
                if(equation[1]=='!')
                {
                    char u=equation[0];
                    
                    char v=equation[3];
                    
                    if(u==v)
                    {
                        return false;
                    }
                    
                    unordered_set<char> visited;
                    
                    if(dfs(graph, visited, u, v)==true)
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    
        bool dfs(unordered_map<char, vector<char>> & graph, unordered_set<char> & visited, int u, int v)
        {
            if(u==v)
            {
                return true;
            }
            
            for(char neighbour : graph[u])
            {
                if(visited.find(neighbour)==end(visited))
                {
                    visited.insert(neighbour);
                    
                    if(dfs(graph, visited, neighbour, v)==true)
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }
};

/*
Solution 2: graph + iterative depth-first traversal.
*/

class Solution
{
    public:
        bool equationsPossible(vector<string> & equations)
        {
            int e=equations.size();
            
            unordered_map<char, vector<char>> graph;
            
            for(string equation : equations)
            {
                if(equation[1]=='=')
                {
                    char u=equation[0];
                    
                    char v=equation[3];
                    
                    if(graph.find(u)==end(graph))
                    {
                        graph.emplace(u, vector<char>());
                    }
                    
                    graph[u].push_back(v);
                    
                    if(graph.find(v)==end(graph))
                    {
                        graph.emplace(v, vector<char>());
                    }
                    
                    graph[v].push_back(u);
                }
            }
            
            for(string equation : equations)
            {
                if(equation[1]=='!')
                {
                    char u=equation[0];
                    
                    char v=equation[3];
                    
                    if(u==v)
                    {
                        return false;
                    }
                    
                    if(dfs(graph, u, v)==true)
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    
        bool dfs(unordered_map<char, vector<char>> & graph, int u, int v)
        {
            deque<char> stack;
            
            unordered_set<char> visited;
            
            visited.insert(u);
            
            stack.push_back(u);
            
            while(!stack.empty())
            {
                char current=stack.back();
                
                stack.pop_back();
                
                if(current==v)
                {
                    return true;
                }
                
                for(char neighbour : graph[current])
                {
                    if(visited.find(neighbour)==end(visited))
                    {
                        visited.insert(neighbour);
                        
                        stack.push_back(neighbour);
                    }
                }
            }
            
            return false;
        }
};

/*
Solution 3: graph + iterative breadth-first traversal.
*/

class Solution
{
    public:
        bool equationsPossible(vector<string> & equations)
        {
            int e=equations.size();
            
            unordered_map<char, vector<char>> graph;
            
            for(string equation : equations)
            {
                if(equation[1]=='=')
                {
                    char u=equation[0];
                    
                    char v=equation[3];
                    
                    if(graph.find(u)==end(graph))
                    {
                        graph.emplace(u, vector<char>());
                    }
                    
                    graph[u].push_back(v);
                    
                    if(graph.find(v)==end(graph))
                    {
                        graph.emplace(v, vector<char>());
                    }
                    
                    graph[v].push_back(u);
                }
            }
            
            for(string equation : equations)
            {
                if(equation[1]=='!')
                {
                    char u=equation[0];
                    
                    char v=equation[3];
                    
                    if(u==v)
                    {
                        return false;
                    }
                    
                    if(bfs(graph, u, v)==true)
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    
        bool bfs(unordered_map<char, vector<char>> & graph, int u, int v)
        {
            deque<char> queue;
            
            unordered_set<char> visited;
            
            visited.insert(u);
            
            queue.push_back(u);
            
            while(!queue.empty())
            {
                char current=queue.front();
                
                queue.pop_front();
                
                if(current==v)
                {
                    return true;
                }
                
                for(char neighbour : graph[current])
                {
                    if(visited.find(neighbour)==end(visited))
                    {
                        visited.insert(neighbour);
                        
                        queue.push_back(neighbour);
                    }
                }
            }
            
            return false;
        }
};

/*
Solution 4: Disjoint sets + Union-Find.

Implementation based off this page --> https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/
*/

class Solution
{
    private:
        vector<int> parents;
    
    public:
        bool equationsPossible(vector<string> & equations)
        {
            parents.resize(26, 0);
            
            for(int i=0;i<26;i++)
            {
                parents[i]=i;
            }
            
            for(string equation : equations)
            {
                if(equation[1]=='=')
                {
                    int u=equation[0] - 'a';
                    
                    int v=equation[3] - 'a';
                    
                    doUnion(u, v);
                }
            }
            
            for(string equation : equations)
            {
                if(equation[1]=='!')
                {
                    int u=equation[0] - 'a';
                    
                    int v=equation[3] - 'a';
                    
                    int uParent=find(u);
                    
                    int vParent=find(v);
                    
                    if(uParent==vParent)
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    
        void doUnion(int u, int v)
        {
            int uParent=find(u);
            
            int vParent=find(v);
            
            parents[vParent]=uParent;
        }
    
        int find(int node)
        {
            if(parents[node]==node)
            {
                return node;
            }
            
            return find(parents[node]);
        }
};