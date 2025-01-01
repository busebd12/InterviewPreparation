#Solution 1: recursive knapsack approach
#IMPORTANT: this solution gets Time Limit Exceeded when run!!! DON'T SUBMIT IT!!!

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        result: int=0

        if k==1:
            result=max([event[2] for event in events])

            return result

        n: int=len(events)

        events.sort(key=lambda event: (event[0], event[1]))

        start_times: list[int]=[event[0] for event in events]

        index: int=0

        result=self.helper(events, start_times, n, k, index)

        return result
    
    def helper(self, events: List[List[int]], start_times: List[int], n: int, k: int, index: int) -> int:
        if k==0 or index >= n:
            return 0

        subproblem_solution: int=0

        next_event_index: int=bisect.bisect_right(start_times, events[index][1])

        take_event: int=events[index][2] + self.helper(events, start_times, n, k - 1, next_event_index)

        skip_event: int=self.helper(events, start_times, n, k, index + 1)

        subproblem_solution=max(take_event, skip_event)

        return subproblem_solution

#Solution 2: a memoized verison of the first solution using a hashmap
#This solution is accepted

class Solution:
    __memo: dict[tuple[int, int], int]=None

    def maxValue(self, events: List[List[int]], k: int) -> int:
        result: int=0

        if k==1:
            result=max([event[2] for event in events])

            return result

        self.__memo=dict()

        n: int=len(events)

        #Sort events based on the start time first and then the end time if the start times for two events are equal
        events.sort(key=lambda event: (event[0], event[1]))

        #Create array of start times that we can search in using binary search
        start_times: list[int]=[event[0] for event in events]

        index: int=0

        result=self.helper(events, start_times, n, k, index)

        return result
    
    def helper(self, events: List[List[int]], start_times: List[int], n: int, k: int, index: int) -> int:
        #If we can't attend any more events or we've run out of events to attend
        if k==0 or index >= n:
            return 0

        #Check to see if we've already solved this subproblme identified by the tuple (index, k) before
        if (index, k) in self.__memo:
            return self.__memo[(index, k)]

        subproblem_solution: int=0

        #Use binary search to find the next event we can attend (if there is one)
        next_event_index: int=bisect.bisect_right(start_times, events[index][1])

        #Attend the event
        take_event: int=events[index][2] + self.helper(events, start_times, n, k - 1, next_event_index)

        #Don't attend the event
        skip_event: int=self.helper(events, start_times, n, k, index + 1)

        #Best score will be the maximum of take_event or skip_event
        subproblem_solution=max(take_event, skip_event)

        #Update the memoization hashmap with the current subproblem solution
        self.__memo[(index, k)]=subproblem_solution

        return subproblem_solution