#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    private:
        unordered_map<int, vector<int>> graph;
    
    public:
        vector<int> killProcess(vector<int> & pid, vector<int> & ppid, int kill)
        {
            vector<int> result;
            
            int n=pid.size();
            
            for(int i=0;i<n;i++)
            {
                int processId=pid[i];
                
                int parentProcessId=ppid[i];
                
                graph[parentProcessId].push_back(processId);
            }
            
            deque<int> stack;
            
            stack.push_back(kill);
            
            while(!stack.empty())
            {
                int process=stack.back();
                
                stack.pop_back();
                
                result.push_back(process);
                
                for(int childProcess : graph[process])
                {
                    stack.push_back(childProcess);
                }
            }
            
            return result;
        }
};

class Solution
{
    private:
        unordered_map<int, vector<int>> graph;
    
    public:
        vector<int> killProcess(vector<int> & pid, vector<int> & ppid, int kill)
        {
            vector<int> result;
            
            int n=pid.size();
            
            for(int i=0;i<n;i++)
            {
                int processId=pid[i];
                
                int parentProcessId=ppid[i];
                
                graph[parentProcessId].push_back(processId);
            }
            
            deque<int> queue;
            
            queue.push_back(kill);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    int process=queue.front();
                
                    queue.pop_front();

                    result.push_back(process);

                    for(int childProcess : graph[process])
                    {
                        queue.push_back(childProcess);
                    }
                }
            }
            
            return result;
        }
};