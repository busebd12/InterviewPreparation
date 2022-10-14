#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

/*
Solution 1: Depth-first search.
*/

class Solution
{
    private:
        unordered_map<int, vector<int>> graph;
    
    public:
        int dfs(vector<int> & informTime, int employeeId)
        {
            if(graph.find(employeeId)==end(graph))
            {
                return 0;
            }
            
            int timeForSupervisorToReport=informTime[employeeId];
            
            int timeForReportsToInform=0;
            
            for(int directReport : graph[employeeId])
            {
                timeForReportsToInform=max(timeForReportsToInform, dfs(informTime, directReport));
            }
            
            timeForSupervisorToReport+=timeForReportsToInform;
            
            return timeForSupervisorToReport;
        }
    
        int numOfMinutes(int n, int headID, vector<int> & manager, vector<int> & informTime)
        {
            int result=0;
            
            for(int employee=0;employee<n;employee++)
            {
                if(employee!=headID)
                {
                    int supervisor=manager[employee];
                    
                    graph[supervisor].emplace_back(employee);
                }   
            }
            
            result=dfs(informTime, headID);
            
            return result;
        }
};

/*
Solution 2: Breadth-first search.
*/

class Solution
{
    private:
        unordered_map<int, vector<int>> graph;
    
    public:
        int numOfMinutes(int n, int headID, vector<int> & manager, vector<int> & informTime)
        {
            int result=0;
            
            for(int employee=0;employee<n;employee++)
            {
                if(employee!=headID)
                {
                    int supervisor=manager[employee];
                    
                    graph[supervisor].emplace_back(employee);
                }   
            }
            
            deque<pair<int, int>> queue;
            
            queue.emplace_back(headID, informTime[headID]);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [employeeId, timeToInform]=queue.front();
                    
                    queue.pop_front();
                    
                    if(graph.find(employeeId)==end(graph))
                    {
                        continue;
                    }
                    
                    result=max(result, timeToInform);
                    
                    for(int directReport : graph[employeeId])
                    {
                        queue.emplace_back(directReport, timeToInform + informTime[directReport]);
                    }
                }
            }
            
            return result;
        }
};