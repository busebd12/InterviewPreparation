import heapq

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        result: int=0

        n: int=len(nums)

        max_heap: List[int]=list()

        heapq.heappush(max_heap, (-nums[0], 0))

        result=nums[0]

        for index in range(1, n):
            while max_heap and index - max_heap[0][1] > k:
                heapq.heappop(max_heap)

            max_of_past_k_values: int=max(0, -max_heap[0][0])

            subsequence_sum_ending_here: int=nums[index] + max_of_past_k_values

            result=max(result, subsequence_sum_ending_here)

            heapq.heappush(max_heap, (-subsequence_sum_ending_here, index))

        return result