'''
Solution 1: pure recursion.
IMPORTANT: DO NOT submit this solution. It receives Time Limit Exceeded when run.
I have only included it so it can be seen how the recursive + memoization solution is derived from this one.
'''
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        result: int=0

        total: int=0

        result=self.solve(nums, target, total)

        return result

    def solve(self, nums: List[int], target: int, total: int) -> int:
        if total==target:
            return 1

        subproblem_solution: int=0

        for number in nums:
            if total + number <= target:
                total+=number

                subproblem_solution+=self.solve(nums, target, total)

                total-=number

        return subproblem_solution

'''
Solution 2: recursion + memoization
'''
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        result: int=0

        total: int=0

        memo: List[int]=[-1] * (target + 1)

        result=self.solve(nums, memo, target, total)

        return result

    def solve(self, nums: List[int], memo: List[int], target: int, total: int) -> int:
        if total==target:
            return 1

        if memo[total]!=-1:
            return memo[total]

        subproblem_solution: int=0

        for number in nums:
            if total + number <= target:
                total+=number

                subproblem_solution+=self.solve(nums, memo, target, total)

                total-=number

        memo[total]=subproblem_solution

        return subproblem_solution