from collections import deque

'''
Solution 1: Receives Time Limit Exceeded when executed.
'''
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result: List[int]=list()

        n: int=len(nums)

        queue: Deque[int]=deque()

        left: int=0

        right: int=0

        while right < k:
            queue.append(nums[right])

            right+=1

        result.append(max(queue))

        while right < n:
            queue.append(nums[right])

            queue.popleft()

            result.append(max(queue))

            left+=1

            right+=1

        return result

'''
Solution 2: Accepted
'''
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result: List[int]=list()

        n: int=len(nums)

        queue: Deque[int]=deque()

        for (index, current) in enumerate(nums):
            #While the queue is not empty and the value of nums at index queue[-1] is less than
            #the current value in nums, we want to pop from the right-end of the queue
            #This way all indices in the queue reference numbers in nums that are kept
            #in decreasing order (not strictly decreasing order though)
            while queue and nums[queue[-1]] < current:
                queue.pop()

            #Add the index of the current value
            queue.append(index)

            #Calculate the current sliding window size
            window_size: int=(index - queue[0]) + 1

            if window_size > k:
                queue.popleft()

            #If we have processed at least k numbers, then we take the maximum value of the current sliding window from the front of the queue
            if index + 1 >= k:
                result.append(nums[queue[0]])  

        return result