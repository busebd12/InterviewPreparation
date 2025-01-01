#include <deque>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        int numSimilarGroups(vector<string> & strs)
        {
            int result=0;

            int n=strs.size();

            vector<vector<int>> graph=buildGraph(strs, n);

            vector<bool> visited(n, false);

            for(int node=0;node<n;node++)
            {
                if(visited[node]==true)
                {
                    continue;
                }

                dfs(graph, visited, n, node);

                result+=1;
            }

            return result;
        }

        vector<vector<int>> buildGraph(vector<string> & strs, int n)
        {
            vector<vector<int>> graph(n, vector<int>());

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(isSimilar(strs[i], strs[j])==true)
                    {
                        graph[i].push_back(j);

                        graph[j].push_back(i);
                    }
                }
            }

            return graph;
        }

        bool isSimilar(string & string1, string & string2)
        {
            int string1Size=string1.size();

            int string2Size=string2.size();

            if(string1Size!=string2Size)
            {
                return false;
            }

            int differences=0;

            for(int i=0;i<string1Size;i++)
            {
                if(string1[i]!=string2[i])
                {
                    differences+=1;

                    if(differences > 2)
                    {
                        return false;
                    }
                }
            }

            return differences==0 or differences==2;
        }

        void dfs(vector<vector<int>> & graph, vector<bool> & visited, int n, int node)
        {
            if(visited[node]==true)
            {
                return;
            }

            visited[node]=true;

            for(int neighbour : graph[node])
            {
                dfs(graph, visited, n, neighbour);
            }
        }
};

class Solution
{
    public:
        int numSimilarGroups(vector<string> & strs)
        {
            int result=0;

            int n=strs.size();

            vector<vector<int>> graph=buildGraph(strs, n);

            vector<bool> visited(n, false);

            for(int node=0;node<n;node++)
            {
                if(visited[node]==true)
                {
                    continue;
                }

                dfs(graph, visited, n, node);

                result+=1;
            }

            return result;
        }

        vector<vector<int>> buildGraph(vector<string> & strs, int n)
        {
            vector<vector<int>> graph(n, vector<int>());

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(isSimilar(strs[i], strs[j])==true)
                    {
                        graph[i].push_back(j);

                        graph[j].push_back(i);
                    }
                }
            }

            return graph;
        }

        bool isSimilar(string & string1, string & string2)
        {
            int string1Size=string1.size();

            int string2Size=string2.size();

            if(string1Size!=string2Size)
            {
                return false;
            }

            int differences=0;

            for(int i=0;i<string1Size;i++)
            {
                if(string1[i]!=string2[i])
                {
                    differences+=1;

                    if(differences > 2)
                    {
                        return false;
                    }
                }
            }

            return differences==0 or differences==2;
        }

        void dfs(vector<vector<int>> & graph, vector<bool> & visited, int n, int node)
        {
            deque<int> stack;

            stack.push_back(node);

            while(!stack.empty())
            {
                int current=stack.back();

                stack.pop_back();

                if(visited[current]==true)
                {
                    continue;
                }

                visited[current]=true;

                for(int neighbour : graph[current])
                {
                    stack.push_back(neighbour);
                }
            }
        }
};


class Solution
{
    public:
        int numSimilarGroups(vector<string> & strs)
        {
            int result=0;

            int n=strs.size();

            vector<vector<int>> graph=buildGraph(strs, n);

            vector<bool> visited(n, false);

            for(int node=0;node<n;node++)
            {
                if(visited[node]==true)
                {
                    continue;
                }

                bfs(graph, visited, n, node);

                result+=1;
            }

            return result;
        }

        vector<vector<int>> buildGraph(vector<string> & strs, int n)
        {
            vector<vector<int>> graph(n, vector<int>());

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(isSimilar(strs[i], strs[j])==true)
                    {
                        graph[i].push_back(j);

                        graph[j].push_back(i);
                    }
                }
            }

            return graph;
        }

        bool isSimilar(string & string1, string & string2)
        {
            int string1Size=string1.size();

            int string2Size=string2.size();

            if(string1Size!=string2Size)
            {
                return false;
            }

            int differences=0;

            for(int i=0;i<string1Size;i++)
            {
                if(string1[i]!=string2[i])
                {
                    differences+=1;

                    if(differences > 2)
                    {
                        return false;
                    }
                }
            }

            return differences==0 or differences==2;
        }

        void bfs(vector<vector<int>> & graph, vector<bool> & visited, int n, int node)
        {
            deque<int> queue;

            queue.push_back(node);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();

                    queue.pop_front();

                    if(visited[current]==true)
                    {
                        continue;
                    }

                    visited[current]=true;

                    for(int neighbour : graph[current])
                    {
                        queue.push_back(neighbour);
                    }
                }
            }
        }
};