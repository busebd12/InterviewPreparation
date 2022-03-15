#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

/*
Solution: see comments for details

Time complexity: O(n + (n log n)) [where n is the number of tasks]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long max(long long a, int b)
        {
            if(a > b)
            {
                return a;
            }
            
            return b;
        }
    
        vector<int> getOrder(vector<vector<int>> & tasks)
        {
            vector<int> result;
            
            int n=tasks.size();
            
            if(n==0)
            {
                return result;
            }
            
            //Add the index of each task to the end of each task vector
            for(int i=0;i<n;i++)
            {
                tasks[i].emplace_back(i);
            }
            
            //Sort the tasks in increasing order of enqueue time
            sort(begin(tasks), end(tasks), [](auto & t1, auto & t2) {return t1[0] < t2[0];});
            
            //Comparator for the min heap we will use
            //If two tasks have the same processing time, then we choose the one with the smaller index
            //Otherwise, choose the task with the smaller processing time
            auto minHeapComparator=[](auto & p1, auto & p2)
            {
                if(p1.first==p2.first)
                {
                    //Since priority_queue in C++ is by default a max heap, we need to the > operator instead of < (because we want a min heap)
                    return p1.second > p2.second;
                }
                
                return p1.first > p2.first;
            };
            
            //Min heap of pairs to represent each task
            //Pair is made up of the processing time and index for each task
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(minHeapComparator)> minHeap(minHeapComparator);
            
            int i=0;
            
            //Set the time to start at the enqueue time of the first task in the list
            long long time=tasks[i][0];
            
            //While we are not at the end of the tasks list and the current task's enqueue time is less than the current time, add it to the min heap
            while(i < n && tasks[i][0] <= time)
            {   
                int processingTime=tasks[i][1];
                
                int index=tasks[i][2];
                
                minHeap.emplace(processingTime, index);
                
                i++;
            }
            
            while(!minHeap.empty())
            {
                auto task=minHeap.top();
                
                //Remove top element from min heap
                minHeap.pop();
                
                //Add index of the task to the result
                result.emplace_back(task.second);
                
                //Increment time by the task's processing time
                time+=task.first;
                
                //If the min heap is empty, set the time to the next task's enqueue time in the tasks list
                if(minHeap.empty())
                {
                    if(i < n)
                    {
                        time=max(time, tasks[i][0]);
                    }
                }
                
                //While we are not at the end of the tasks list and the current task's enqueue time
            //is less than the current time, add it to the min heap
                while(i < n && tasks[i][0] <= time)
                {
                    int processingTime=tasks[i][1];
                
                    int index=tasks[i][2];

                    minHeap.emplace(processingTime, index);

                    i++;
                }
            }
            
            return result;
        }
};