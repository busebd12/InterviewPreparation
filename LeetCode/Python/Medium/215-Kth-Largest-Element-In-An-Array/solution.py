import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()

        return nums[-k]

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)

        return nums[k - 1]

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap: List[int]=list()

        for number in nums:
            heapq.heappush(min_heap, number)

            if len(min_heap) > k:
                heapq.heappop(min_heap)
        
        return min_heap[0]

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        result: int=0
        
        max_heap: List[int]=list()

        for number in nums:
            heapq.heappush(max_heap, -number)
        
        while max_heap and k > 0:
            result=(-1 * heapq.heappop(max_heap))

            k-=1

        return result

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        result: int=0
        
        hashmap: Dict[int, int]=dict()

        for number in nums:
            if number not in hashmap.keys():
                hashmap[number]=0
            
            hashmap[number]+=1

        min_value: int=min(nums)

        max_value: int=max(nums)

        for number in range(max_value, min_value - 1, -1):
            if number in hashmap.keys():
                frequency: int=hashmap[number]

                if k > frequency:
                    k-=frequency
                else:
                    result=number

                    break

        return result