#include <deque>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: the idea is to re-frame this as a graph question and the numbers [1, n] as the nodes.
Then, nums simply represents a traversal of the graph containing these numbers. Also, sequences
is just a list of directed edges in the graph where sequences[i][j] and sequences[i][j + 1] form
a directed edge. Once we re-frame the question this way, we are just asking if there exists another
graph traversal that is shorter than nums and contains all the edges that can be formed by each sequence
in sequences. Since the edges of this graph are directed (meaning they can only be traversed one way),
and we want to check if the given path is the shortest possible, let's use our friendly neighbourhood
breath-first search A.K.A topological sort to walk the graph and see if we can find a shorter path.

Time complexity: O(n) [where n=length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool sequenceReconstruction(vector<int> & nums, vector<vector<int>> & sequences)
        {
            int n=nums.size();
            
            vector<unordered_set<int>> graph(n + 1, unordered_set<int>());

            //Track the indegree (the number of edges coming into a node) of each node
            vector<int> indegree(n + 1, 0);

            //Build the graph by forming edges based on each sequence in sequences
            for(vector<int> sequence : sequences)
            {
                for(int i=1;i<sequence.size();i++)
                {
                    //Attempt to create an edge from sequence[i - 1] --> sequence[i]
                    auto [insertionIterator, success]=graph[sequence[i - 1]].insert(sequence[i]);

                    //If we are able to create an edge
                    if(success==true)
                    {
                        //Increase the indegree of sequence[i] since another edge is coming into it
                        indegree[sequence[i]]+=1;
                    }
                }
            }

            int numsIndex=0;

            //Queue used for topological sort
            deque<int> queue;

            //Find the starting node that has an indegree of zero
            for(int node=1;node<=n;node++)
            {
                if(indegree[node]==0)
                {
                    queue.push_back(node);
                }
            }

            //Do the topological sort
            while(!queue.empty())
            {
                //If the queue size is greater than one, this means that there are more than one valid next number in the path and there should only be one
                if(queue.size() > 1)
                {
                    return false;
                }

                int current=queue.front();

                queue.pop_front();

                //If the current value in the path doesn't match the corresponding value in the nums path, then we know nums is the shortest and only possible path
                if(current!=nums[numsIndex])
                {
                    return false;
                }

                numsIndex+=1;

                //Visit the children of the current node in the graph
                for(int child : graph[current])
                {
                    indegree[child]-=1;

                    if(indegree[child]==0)
                    {
                        queue.push_back(child);
                    }
                }
            }

            //Make sure that the path walked by the topological sort is valid by confirm that we visited all the nodes in the graph
            return numsIndex==n;
        }
};