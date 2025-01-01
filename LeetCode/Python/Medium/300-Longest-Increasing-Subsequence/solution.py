'''
Solution 1: purse recursion. This solution gets Time Limit Exceeded when run so DO NOT submit it.
'''
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        result=0

        n=len(nums)

        for index in range(0, n):
            length=1 + self.dfs(nums, n, index)

            result=max(result, length)

        return result

    def dfs(self, nums: List[int], n: int, index: int) -> int:
        if index==n:
            return 0

        subproblem_solution=0

        for i in range(index + 1, n):
            if nums[i] > nums[index]:
                subproblem_solution=max(subproblem_solution, 1 + self.dfs(nums, n, i))

        return subproblem_solution

'''
Solution 2: recursion + memoization. This solution is accepted.
'''
class Solution:
    def __init__(self):
        self.memo=list()
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        result=0

        n=len(nums)

        self.memo=[-1 for _ in range(0, n)]

        for index in range(0, n):
            length=1 + self.dfs(nums, n, index)

            result=max(result, length)

        return result

    def dfs(self, nums: List[int], n: int, index: int) -> int:
        if index==n:
            return 0

        if self.memo[index]!=-1:
            return self.memo[index]

        subproblem_solution=0

        for i in range(index + 1, n):
            if nums[i] > nums[index]:
                subproblem_solution=max(subproblem_solution, 1 + self.dfs(nums, n, i))

        self.memo[index]=subproblem_solution

        return subproblem_solution