#include <vector>
using namespace std;

/*
Time complexity: O(m + (n^2 * t) + t)
Space complexity: O(m + (n * t))
*/

class Solution
{
    private:
        vector<vector<int>> graph;

        vector<vector<int>> nextCity;

        vector<vector<int>> memo;
    
    public:
        vector<int> mostSimilar(int n, vector<vector<int>> & roads, vector<string> & names, vector<string>& targetPath)
    {
        vector<int> result;

        int t=targetPath.size();

        int m=roads.size();

        buildGraph(roads, n); //O(m) [where m is the length of roads]

        nextCity.resize(n, vector<int>(t, 0));

        memo.resize(n, vector<int>(t, -1));

        int minEditDistance=-1;

        int startCityIndex=-1;

        for(int cityIndex=0;cityIndex<n;cityIndex++) //O(n)
        {
            int targetPathIndex=0;
            
            int currentEditDistance=getMinEditDistance(names, targetPath, t, targetPathIndex, cityIndex); //O(n * t) [where t is the length of targetPath]

            if(minEditDistance==-1 or currentEditDistance < minEditDistance)
            {
                minEditDistance=currentEditDistance;

                startCityIndex=cityIndex;
            }
        }

        while(result.size() < t) //O(t)
        {
            result.push_back(startCityIndex);

            //Find the next city in the path given the index of current last node in the path is startCityIndex and the current path has length result.size() - 1
            startCityIndex=nextCity[startCityIndex][result.size() - 1];
        }
        
        return result;
    }

    void buildGraph(vector<vector<int>> & roads, int n)
    {
        graph.resize(n, vector<int>());

        for(vector<int> & road : roads)
        {
            int u=road[0];

            int v=road[1];

            graph[u].push_back(v);

            graph[v].push_back(u);
        }
    }

    int getMinEditDistance(vector<string> & names, vector<string> & targetPath, int t, int targetPathIndex, int cityIndex)
    {
        if(targetPathIndex >= t)
        {
            return 0;
        }

        if(memo[cityIndex][targetPathIndex]!=-1)
        {
            return memo[cityIndex][targetPathIndex];
        }

        int subproblemSolution=numeric_limits<int>::max();

        for(int neighbour : graph[cityIndex])
        {
            int editDistance=getMinEditDistance(names, targetPath, t, targetPathIndex + 1, neighbour);

            if(editDistance < subproblemSolution)
            {
                subproblemSolution=editDistance;

                nextCity[cityIndex][targetPathIndex]=neighbour;
            }
        }

        if(names[cityIndex]!=targetPath[targetPathIndex])
        {
            subproblemSolution+=1;
        }

        memo[cityIndex][targetPathIndex]=subproblemSolution;

        return subproblemSolution;
    }
};