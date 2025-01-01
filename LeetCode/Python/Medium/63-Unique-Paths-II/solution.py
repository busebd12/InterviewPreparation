class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        result: int=0

        m: int=len(obstacleGrid)

        n: int=len(obstacleGrid[0])

        result=self.solve(obstacleGrid, m - 1, n - 1)

        return result

    def solve(self, obstacleGrid: List[List[int]], m: int, n: int) -> int:
        if m < 0 or n < 0:
            return 0

        if obstacleGrid[m][n]==1:
            return 0

        if m==0 and n==0:
            return 1

        subproblem_solution: int=0

        move_up: int=self.solve(obstacleGrid, m - 1, n)

        move_left: int=self.solve(obstacleGrid, m, n - 1)

        subproblem_solution=move_up + move_left

        return subproblem_solution

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        result: int=0

        m: int=len(obstacleGrid)

        n: int=len(obstacleGrid[0])

        memo: List[List[int]]=[[-1 for iteration in range(0, n + 1)] for iteration in range(0, m + 1)]

        result=self.solve(obstacleGrid, memo, m - 1, n - 1)

        return result

    def solve(self, obstacleGrid: List[List[int]], memo: List[List[int]], m: int, n: int) -> int:
        if m < 0 or n < 0:
            return 0

        if obstacleGrid[m][n]==1:
            return 0

        if m==0 and n==0:
            return 1

        if memo[m][n]!=-1:
            return memo[m][n]

        subproblem_solution: int=0

        move_up: int=self.solve(obstacleGrid, memo, m - 1, n)

        move_left: int=self.solve(obstacleGrid, memo, m, n - 1)

        subproblem_solution=move_up + move_left

        memo[m][n]=subproblem_solution

        return subproblem_solution