class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        result: int=0

        result=self.solve(m - 1, n - 1)

        return result

    def solve(self, m: int, n: int) -> int:
        if m < 0 or n < 0:
            return 0

        if m==0 or n==0:
            return 1

        subproblem_solution: int=0

        go_up: int=self.solve(m - 1, n)

        go_left: int=self.solve(m, n - 1)

        subproblem_solution=go_up + go_left

        return subproblem_solution

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        result: int=0

        memo: List[List[int]]=[[-1 for iteration in range(0, n + 1)] for iteration in range(0, m + 1)]

        result=self.solve(memo, m - 1, n - 1)

        return result

    def solve(self, memo: List[List[int]], m: int, n: int) -> int:
        if m < 0 or n < 0:
            return 0

        if m==0 and n==0:
            return 1

        if memo[m][n]!=-1:
            return memo[m][n]

        subproblem_solution: int=0

        go_up: int=self.solve(memo, m - 1, n)

        go_left: int=self.solve(memo, m, n - 1)

        subproblem_solution=go_up + go_left

        memo[m][n]=subproblem_solution

        return subproblem_solution