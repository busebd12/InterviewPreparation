import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        result: int=0

        max_heap: list[int]=list()

        for stone in stones:
            #Multiply the stone's value by -1 when we add it to heap so that the most negative value sits on top
            #So, if stones=[1, 2, 3, 4, 5, 6, 7], when we add all the values to the heap, the heap will look like [-7, -6, -5, -4, -3, -2, -1]
            #Also, when we pop values from the heap, we multiply the value by -1 to make it positive
            #If the heap is [-7, -6, -5, -4, -3, -2, -1], when we pop the top number, -7, we multiply it by -1 to make it 7
            heapq.heappush(max_heap, -stone)
        
        while len(max_heap) > 1:
            #Important: when we pop x and y from the heap, we need to multiply the values by -1 to make them positive
            x: int=-heapq.heappop(max_heap)

            y: int=-heapq.heappop(max_heap)

            if x!=y:
                #Remember to multiply the difference between x and y by -1 when adding it to the heap
                heapq.heappush(max_heap, -(x - y))

        #If the max heap is not empty
        if max_heap:
            #Remember to multiply the top heap value by -1 when popping
            result=-heapq.heappop(max_heap)

        return result