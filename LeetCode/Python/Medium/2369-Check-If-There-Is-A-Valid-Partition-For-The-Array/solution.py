class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n: int=len(nums)

        index: int=0

        return self.solve(nums, n, index)

    def solve(self, nums: List[int], n: int, index: int) -> bool:
        if index >= n:
            return True

        subproblem_solution: bool=False

        if index + 1 < n:
            if nums[index]==nums[index + 1]:
                subproblem_solution=(subproblem_solution or self.solve(nums, n, index + 2))
        
        if index + 2 < n:
            all_three_same: bool=(nums[index]==nums[index + 1] and nums[index + 1]==nums[index + 2])

            consecutive_difference_of_one: bool=(nums[index + 1] - nums[index] == 1) and (nums[index + 2] - nums[index + 1] == 1)
            
            if all_three_same or consecutive_difference_of_one:
                subproblem_solution=(subproblem_solution or self.solve(nums, n, index + 3))

        return subproblem_solution

class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n: int=len(nums)

        memo: List[int]=[-1] * (n + 1)

        index: int=0

        return self.solve(nums, memo, n, index)

    def solve(self, nums: List[int], memo: List[int], n: int, index: int) -> bool:
        if index >= n:
            return True

        if memo[index]!=-1:
            return memo[index]

        subproblem_solution: bool=False

        if index + 1 < n:
            if nums[index]==nums[index + 1]:
                subproblem_solution=(subproblem_solution or self.solve(nums, memo, n, index + 2))

        if index + 2 < n:
            all_three_same: bool=(nums[index]==nums[index + 1] and nums[index + 1]==nums[index + 2])

            consecutive_difference_of_one: bool=(nums[index + 1] - nums[index] == 1) and (nums[index + 2] - nums[index + 1] == 1)
            
            if all_three_same or consecutive_difference_of_one:
                subproblem_solution=(subproblem_solution or self.solve(nums, memo, n, index + 3))

        memo[index]=subproblem_solution

        return subproblem_solution