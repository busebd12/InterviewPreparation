class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows: int=len(matrix)

        columns: int=len(matrix[0])

        row: int=0

        column: int=columns - 1

        while row < rows and column >= 0:
            if matrix[row][column]==target:
                return True
            elif matrix[row][column] > target:
                column-=1
            else:
                row+=1

        return False

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows: int=len(matrix)

        columns: int=len(matrix[0])

        n: int=rows * columns

        low: int=0

        high: int=n - 1

        while low <= high:
            middle: int=(low + (high - low)//2)

            middle_row: int=middle // columns

            middle_column: int=middle % columns

            if matrix[middle_row][middle_column]==target:
                return True
            elif matrix[middle_row][middle_column] > target:
                high=middle - 1
            else:
                low=middle + 1

        return False