'''
Solution: recursion + memoization
'''
class Solution:
    def __init__(self):
        self.directions=[(1, -1), (1, 0), (1, 1)]
    
    def cherryPickup(self, grid: List[List[int]]) -> int:
        result=0

        rows=len(grid)

        columns=len(grid[0])

        memo=[[[-1 for _ in range(0, columns)] for _ in range(0, columns)] for _ in range(0, rows)]

        row=0

        robot1_column=0

        robot2_column=columns - 1

        result=self.helper(grid, memo, rows, columns, row, robot1_column, robot2_column)

        return result

    def helper(self, grid: List[List[int]], memo: List[List[List[int]]], rows: int, columns: int, row: int, robot1_column: int, robot2_column: int) -> int:
        if not self.is_valid(rows, columns, row, robot1_column) or not self.is_valid(rows, columns, row, robot2_column):
            return 0

        if memo[row][robot1_column][robot2_column]!=-1:
            return memo[row][robot1_column][robot2_column]

        subproblem_solution=0

        subproblem_solution+=grid[row][robot1_column]

        if robot1_column!=robot2_column:
            subproblem_solution+=grid[row][robot2_column]

        max_cherries=0

        for (robot1_row_offset, robot1_column_offset) in self.directions:
            next_robot1_column=robot1_column + robot1_column_offset
            
            for (robot2_row_offset, robot2_column_offset) in self.directions:
                next_robot2_column=robot2_column + robot2_column_offset                

                max_cherries=max(max_cherries, self.helper(grid, memo, rows, columns, row + 1, next_robot1_column, next_robot2_column))

        subproblem_solution+=max_cherries

        memo[row][robot1_column][robot2_column]=subproblem_solution

        return subproblem_solution

    def is_valid(self, rows, columns, robot_row, robot_column) -> bool:
        return ((robot_row >= 0 and robot_row < rows) and (robot_column >= 0 and robot_column < columns))