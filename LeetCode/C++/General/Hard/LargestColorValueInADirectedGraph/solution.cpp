class Solution
{
    public:
        int largestPathValue(string colors, vector<vector<int>> & edges)
        {
            int result=0;

            int n=colors.size();

            int m=edges.size();

            vector<vector<int>> graph(n, vector<int>());

            vector<int> indegree(n, 0);

            //Build directed graph based on edges
            for(vector<int> & edge : edges)
            {
                int a=edge[0];

                int b=edge[1];

                graph[a].push_back(b);

                indegree[b]+=1;
            }

            //For each node, keep a list of frequencies for each color that have accumulated from exploring all paths ending at the current node
            //Since the colors are represented by lower-case letters, we can simply increment the index corresponding to their ascii value
            vector<vector<int>> nodeColorValueFrequencies(n, vector<int>(26, 0));

            //Queue used as part of topological sort
            deque<int> queue;

            //Iterate through each node and check if it has an indegree of zero
            for(int node=0;node<n;node++)
            {
                //If it does, then this node has no incoming edges and it is a "source" node
                if(indegree[node]==0)
                {
                    //Add the node to the queue
                    queue.push_back(node);

                    int colorAsciiIndex=colors[node] - 'a';

                    //The color frequency for this path only has one occurrence of the color of the current node
                    nodeColorValueFrequencies[node][colorAsciiIndex]=1;
                }
            }

            //Keep track of the number of nodes in the graph that we visit as the topological sort algorithm executes
            int visited=0;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int node=queue.front();

                    queue.pop_front();

                    //We've visited another node
                    visited+=1;

                    //The maximum value in nodeColorValueFrequencies[node] represents the highest color frequency
                    //from all the possible paths in the graph that converge/meet at the current node
                    int mostFrequentlyOccuringColor=*(max_element(nodeColorValueFrequencies[node].begin(), nodeColorValueFrequencies[node].end()));

                    //Maximize our result
                    result=max(result, mostFrequentlyOccuringColor);

                    //Iterate through all the neighbour colors for this current node
                    for(int neighbour : graph[node])
                    {
                        int neighbourColorAsciiIndex=colors[neighbour] - 'a';
                        
                        //Iterate through all the possible ascii color indices
                        for(int asciiIndex=0;asciiIndex<26;asciiIndex++)
                        {
                            //The frequency up to this point of the color represented by the value asciiIndex
                            int previousColorFrequency=nodeColorValueFrequencies[node][asciiIndex];

                            //If the neighbour color is a valid color
                            if(neighbourColorAsciiIndex==asciiIndex)
                            {
                                //Increment the frequency of this color since we've encountered another occurrence of it
                                previousColorFrequency+=1;
                            }
                            
                            //If the new frequency of this color is larger than the previous frequency,
                            //then we want the neighbour node to have this up-to-date information
                            nodeColorValueFrequencies[neighbour][asciiIndex]=max(nodeColorValueFrequencies[neighbour][asciiIndex], previousColorFrequency);
                        }

                        //Decrement the number of incoming edges for this neighbouring node
                        indegree[neighbour]-=1;

                        //If this neighbouring node has no more incoming edges
                        if(indegree[neighbour]==0)
                        {
                            //Add the node to the queue
                            queue.push_back(neighbour);
                        }
                    }
                }
            }

            //If we didn't visit all the nodes in the graph, then the graph contains a cycle
            if(visited < n)
            {
                return -1;
            }

            return result;
        }
};