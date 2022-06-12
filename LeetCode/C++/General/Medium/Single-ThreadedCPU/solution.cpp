#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n) [where n is the length of tasks]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> getOrder(vector<vector<int>> & tasks)
        {
            vector<int> result;
            
            size_t n=tasks.size();
            
            //Add index to each task
            for(size_t i=0;i<n;i++)
            {
                tasks[i].emplace_back(i);
            }
            
            //Custom sorting comparator
            //Compare tasks based on enqueue time
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[0] < rhs[0];
            };
            
            //Sort tasks in acsending order of enqueue time
            sort(begin(tasks), end(tasks), compareLikeThis);
            
            //Custom comparator used for our minimum heap
            auto heapComparator=[] (vector<int> & lhs, vector<int> & rhs)
            {
                //If the processing time for two tasks is not the same
                if(lhs[1]!=rhs[1])
                {
                    //Task with smaller processing time will be higher up in the heap
                    return lhs[1] > rhs[1];
                }
                //Else, processing time for two tasks are the same
                else
                {
                    //The task with the smaller index will be higher up in the heap
                    return lhs[2] > rhs[2];
                }
            };
            
            priority_queue<vector<int>, vector<vector<int>>, decltype(heapComparator)> minHeap(heapComparator);
            
            long int startTime=tasks[0][0];
            
            for(size_t index=0;index<n || !minHeap.empty();)
            {
                //Add all tasks that start on or before the current startTime
                while(index < n && tasks[index][0] <= startTime)
                {
                    minHeap.emplace(tasks[index]);
                    
                    index++;
                }
                
                //If there is a task to process
                if(!minHeap.empty())
                {
                    vector<int> current=minHeap.top();
                    
                    minHeap.pop();
                    
                    int taskIndex=current[2];
                    
                    result.emplace_back(taskIndex);
                    
                    int processingTime=current[1];
                    
                    //Process the task and increment the start time
                    startTime+=processingTime;
                }
                //Else, no current task to process; update the startTime to the enqueue time of the next task
                else
                {
                    startTime=tasks[index][0];
                }
            }
            
            return result;
        }
};