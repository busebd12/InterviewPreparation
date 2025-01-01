class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        result: int=0

        n: int=len(cost)

        index: int=0

        start_with_index_zero: int=self.helper(cost, n, index)

        index=1

        start_with_index_one: int=self.helper(cost, n, index)

        result=min(start_with_index_zero, start_with_index_one)

        return result

    def helper(self, cost: List[int], n: int, index: int) -> int:
        if index > n-1:
            return 0
        
        subproblem_solution: int=0

        subproblem_solution=cost[index] + min(self.helper(cost, n, index + 1), self.helper(cost, n, index + 2))

        return subproblem_solution

class Solution:
    def __init__(self):
        self.memo=list()

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        result: int=0

        n: int=len(cost)

        self.memo=[-1] * (n + 1)

        index: int=0

        start_with_index_zero: int=self.helper(cost, n, index)

        index=1

        start_with_index_one: int=self.helper(cost, n, index)

        result=min(start_with_index_zero, start_with_index_one)

        return result

    def helper(self, cost: List[int], n: int, index: int) -> int:
        if index > n-1:
            return 0

        if self.memo[index]!=-1:
            return self.memo[index]
        
        subproblem_solution: int=0

        subproblem_solution=cost[index] + min(self.helper(cost, n, index + 1), self.helper(cost, n, index + 2))

        self.memo[index]=subproblem_solution

        return subproblem_solution