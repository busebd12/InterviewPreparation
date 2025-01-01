import heapq

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        result: List[int]=list()

        min_heap: List[int]=list()

        for number in nums:
            square: int=number**2

            heapq.heappush(min_heap, square)

        while min_heap:
            result.append(heapq.heappop(min_heap))

        return result

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        result: List[int]=list()

        limit: int=(10**4) + 1

        buckets: List[int]=[0 for _ in range(0, limit)]

        for number in nums:
            if number < 0:
                number=number * -1

            buckets[number]+=1

        for number in range(0, limit):
            if buckets[number]:
                for count in range(0, buckets[number]):
                    result.append(number * number)

        return result