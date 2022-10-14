#include <deque>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/process-tasks-using-servers/discuss/1240042/C%2B%2B-Two-MinHeaps-Solution
*/

class Solution
{
    public:
        vector<int> assignTasks(vector<int> & servers, vector<int> & tasks)
        {
            vector<int> result;
            
            int n=servers.size();
            
            int m=tasks.size();
            
            auto freeServerComparator=[&servers] (int & lhs, int & rhs)
            {
                if(servers[lhs]==servers[rhs])
                {
                    return lhs > rhs;
                }
                else
                {
                    return servers[lhs] > servers[rhs];
                }
            };
            
            priority_queue<int, vector<int>, decltype(freeServerComparator)> freeServers(freeServerComparator);
            
            for(int index=0;index<n;index++)
            {
                freeServers.emplace(index);
            }
            
            auto busyServersComparator=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                return lhs.first > rhs.first;
            };
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(busyServersComparator)> busyServers(busyServersComparator);
            
            deque<int> taskQueue;
            
            for(int taskIndex=0;taskIndex<m;taskIndex++)
            {
                taskQueue.push_back(taskIndex);
            }
            
            int time=0;
            
            while(!taskQueue.empty())
            {
                while(!busyServers.empty() and busyServers.top().first <= time)
                {
                    auto [endingTime, serverIndex]=busyServers.top();
                    
                    busyServers.pop();
                    
                    freeServers.emplace(serverIndex);
                }
                
                while(!freeServers.empty() and !taskQueue.empty() and taskQueue.front() <= time)
                {
                    int taskIndex=taskQueue.front();
                    
                    taskQueue.pop_front();
                    
                    int serverIndex=freeServers.top();
                    
                    freeServers.pop();
                    
                    int endingTime=time + tasks[taskIndex];
                    
                    busyServers.emplace(endingTime, serverIndex);
                    
                    result.push_back(serverIndex);
                }
                
                if(freeServers.empty())
                {
                    time=busyServers.top().first;
                    
                    continue;
                }
                
                time+=1;
            }
            
            return result;
        }
};