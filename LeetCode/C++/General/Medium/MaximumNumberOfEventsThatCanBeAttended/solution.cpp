#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(n log n + d(n log n)) [where n is the length of events]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxEvents(vector<vector<int>> & events)
        {
            int result=0;
            
            int n=events.size();
            
            //Sort the events based on starting time O(n log n)
            sort(begin(events), end(events), [] (auto & lhs, auto & rhs) {return lhs[0] < rhs[0];});
            
            int index=0;
            
            //Min heap to store ending times of events
            //The earliest ending time will be on top of the heap
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
            for(int day=1;day<100001;day++)
            {
                //Remove ending times of events that ended before the current day
                while(!minHeap.empty() && minHeap.top() < day)
                {
                    minHeap.pop();
                }
                
                //Add all the ending times of events that start on the current day
                while(index < n && events[index][0]==day)
                {
                    minHeap.emplace(events[index][1]);
                    
                    index++;
                }
                
                //If the min heap is not empty, that means that there is at least one event that starts on the curren day that we can attend
                //Since we can only attend one event per day, attend the event that ends the soonest so we can attend other events on other days
                if(!minHeap.empty())
                {
                    minHeap.pop();
                    
                    result++;
                }
            }
            
            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n log n + d(n log n)) [where n is the length of events]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxEvents(vector<vector<int>> & events)
        {
            int result=0;
            
            int n=events.size();
            
            //Sort the events based on starting time O(n log n)
            sort(begin(events), end(events), [] (auto & lhs, auto & rhs) {return lhs[0] < rhs[0];});
            
            int index=0;
            
            //Min heap to store ending times of events
            //The earliest ending time will be on top of the heap
            multiset<int> minHeap;
            
            for(int day=1;day<100001;day++)
            {
                //Remove ending times of events that ended before the current day
                while(!minHeap.empty() && *(begin(minHeap)) < day)
                {
                    minHeap.erase(begin(minHeap));
                }
                
                //Add all the ending times of events that start on the current day
                while(index < n && events[index][0]==day)
                {
                    minHeap.insert(events[index][1]);
                    
                    index++;
                }
                
                //If the min heap is not empty, that means that there is at least one event that starts on the curren day that we can attend
                //Since we can only attend one event per day, attend the event that ends the soonest so we can attend other events on other days
                if(!minHeap.empty())
                {
                    minHeap.erase(begin(minHeap));
                    
                    result++;
                }
            }
            
            return result;
        }
};