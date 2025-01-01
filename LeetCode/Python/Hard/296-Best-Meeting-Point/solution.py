class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        result=0

        rows=len(grid)

        columns=len(grid[0])

        x_coordinates=list()

        for row in range(0, rows):
            for column in range(0, columns):
                if grid[row][column]==1:
                    x_coordinates.append(row)

        y_coordinates=list()

        for column in range(0, columns):
            for row in range(0, rows):
                if grid[row][column]==1:
                    y_coordinates.append(column)

        midpoint=len(x_coordinates) // 2

        x_coordinates_middle=x_coordinates[midpoint]

        y_coordinates_middle=y_coordinates[midpoint]

        for row in range(0, rows):
            for column in range(0, columns):
                if grid[row][column]==1:
                    manhattan_distance=abs(row - x_coordinates_middle) + abs(column - y_coordinates_middle)

                    result+=manhattan_distance

        return result