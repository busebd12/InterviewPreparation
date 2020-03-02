#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

/*
 * Solution: the idea is to use a min heap to keep track of the meeting ending times.
 * Since we are using a min heap, the meeting that will end the soonest (or, the conference
 * room that will be free the soonest) will always be at the top. So, we iterate over the
 * intervals of start and ending meeting times and have the following situations to handle
 *
 * 1. The heap is empty: this means that no meetings have begun so add the first meetings ending time to the heap and increase the number of rooms needed to one.
 *
 * 2. The current meeting start time is less than the ending meeting time at the top of the heap. This means that the current cannot use the room that the meeting
 * sitting at the top of the heap is using, so, we need another room. Thus, increment the number of rooms and add the new meeting's ending time to heap.
 * The new ending time will sit at the top of the heap.
 *
 * 3. The current meeting start time is greater than or equal to the ending time of the meeting sitting at the top of the heap.
 * In this case, we can just "wait" for the conference room that the meeting at the top of the heap occupies to be free.
 * When the meeting that is currently occupying the conference room is done, the next meeting will boot them out of the room,
 * so we pop from the top of the heap and the next meeting can use the room (adding the ending time of the next meeting to the heap).
 *
 * Time complexity: O(n log n) [where n is the length of the input vector of vectors]
 * Space complexity: O(n)
 *
 */

int minMeetingRooms(std::vector<std::vector<int>> & intervals)
{
    if(intervals.empty())
    {
        return 0;
    }

    int n=int(intervals.size());

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    std::sort(intervals.begin(), intervals.end());

    int rooms=0;

    for(int i=0;i<n;++i)
    {
        if(minHeap.empty())
        {
            minHeap.push(intervals[i][1]);

            rooms++;
        }
        else
        {
            if(intervals[i][0] < minHeap.top())
            {
                rooms++;

                minHeap.push(intervals[i][1]);
            }
            else
            {
                minHeap.pop();

                minHeap.push(intervals[i][1]);
            }
        }
    }

    return rooms;
}

int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}