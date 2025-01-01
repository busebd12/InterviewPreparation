'''
Solution inspired by this post: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/solutions/4155162/breaking-down-hard-problem-into-easy-problem/?envType=daily-question&envId=2023-10-10
'''
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        sorted_nums: Set[int]=sorted(set(nums))

        queue: Deque[int]=deque()

        length_of_longest_continuous_subarray: int=0

        for number in sorted_nums:
            while queue and number - queue[0] > n - 1:
                queue.popleft()

            queue.append(number)

            length_of_longest_continuous_subarray=max(length_of_longest_continuous_subarray, len(queue))

        result=n - length_of_longest_continuous_subarray

        return result