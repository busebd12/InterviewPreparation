#include <algorithm>
#include <queue>
#include <vector>

/*
Solution: inspired by this post

https://leetcode.com/problems/two-best-non-overlapping-events/solutions/2592647/c-min-heap/

Time complexity: O(n * log(n)) [where n is the length of events]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxTwoEvents(vector<vector<int>> & events)
        {
            int result=0;

            int n=events.size();

            sort(events.begin(), events.end()); //O(n * log(n))

            auto heapComparator=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                int lhsEndTime=lhs.first;

                int rhsEndTime=rhs.first;

                return lhsEndTime > rhsEndTime;
            };

            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(heapComparator)> minHeap(heapComparator);

            int maxEventValue=0;

            for(vector<int> & event : events) //O(n * log(n))
            {
                int currentStartTime=event[0];

                int currentEndTime=event[1];

                int currentEventValue=event[2];

                while(!minHeap.empty() and minHeap.top().first < currentStartTime)
                {
                    int eventValue=minHeap.top().second;

                    maxEventValue=max(maxEventValue, eventValue);

                    minHeap.pop();
                }

                int sum=currentEventValue + maxEventValue;

                result=max(result, sum);

                minHeap.emplace(currentEndTime, currentEventValue);
            }

            return result;
        }
};