import heapq

class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        result=0
        
        min_heap=list()

        for stick in sticks:
            heapq.heappush(min_heap, stick)

        while len(min_heap) > 1:
            x=heapq.heappop(min_heap)

            y=heapq.heappop(min_heap)

            total=x + y

            result+=total

            heapq.heappush(min_heap, total)
            
        return result