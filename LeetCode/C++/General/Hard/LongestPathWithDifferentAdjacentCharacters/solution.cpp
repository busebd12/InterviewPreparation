#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        int longestPath(vector<int> & parent, string s)
        {
            int result=0;

            int n=parent.size();

            vector<vector<int>> graph(n, vector<int>());

            for(int child=1;child<n;child++)
            {
                int p=parent[child];

                graph[p].push_back(child);
            }

            int node=0;

            helper(graph, s, result, node);

            return result;
        }

        int helper(vector<vector<int>> & graph, string & s, int & result, int node)
        {
            int longest=0;

            int secondLongest=0;

            for(int child : graph[node])
            {
                int childLength=helper(graph, s, result, child);

                if(s[child]==s[node])
                {
                    continue;
                }

                if(childLength > longest)
                {
                    secondLongest=longest;

                    longest=childLength;
                }
                else if(childLength > secondLongest)
                {
                    secondLongest=childLength;
                }
            }

            int option1=longest + 1;

            int option2=longest + secondLongest + 1;

            result=max(result, max(option1, option2));

            return option1;
        }
};