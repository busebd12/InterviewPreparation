class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        result: int=0

        n: int=len(events)

        #Sort the events based on the starting day and then the ending day if the starting day is the same for two events
        events.sort(key=lambda event: (event[0], event[1]))

        index: int=0

        max_ending_day: int=self.get_max_ending_day(events)

        min_heap: list[int]=list()

        #Loop through day 1 through max_ending_day (inclusive) to make sure we account for all possible ending days
        for day in range(1, max_day + 1):
            #while the min heap is not empty and the ending day for the events are less than the current day
            #This means that the event ended before the current day and we can remove it from the heap
            while min_heap and min_heap[0] < day:
                heapq.heappop(min_heap)
            
            #While there are still events left that we can attend, add the ending time for all events that begin on the current day to the heap
            while index < n and events[index][0]==day:
                heapq.heappush(min_heap, events[index][1])

                index+=1

            #If the heap is not empty, then there is an event that we can attend
            if min_heap:
                heapq.heappop(min_heap)

                result+=1

        return result

    def get_max_ending_day(self, events: list[list[int]]) -> int:
        max_day: int=0

        for event in events:
            end_day: int=event[1]

            max_day=max(max_day, end_day)

        return max_day