from collections import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        result=0

        min_heap=list()

        intervals.sort(key=lambda interval: interval[0])

        for interval in intervals:
            interval_start=interval[0]

            interval_end=interval[1]

            if not min_heap:
                heapq.heappush(min_heap, interval_end)

                result+=1
            else:
                if interval_start >= min_heap[0]:
                    heapq.heappop(min_heap)
                else:
                    result+=1
                
                heapq.heappush(min_heap, interval_end)

        return result