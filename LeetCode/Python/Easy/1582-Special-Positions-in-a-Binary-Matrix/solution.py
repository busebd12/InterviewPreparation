class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        result=0

        rows=len(mat)

        columns=len(mat[0])

        one_positions=list()

        for row in range(0, rows):
            for column in range(0, columns):
                if mat[row][column]:
                    one_positions.append((row, column))

        for (row, column) in one_positions:
            if self.single_one_in_row(mat, columns, row, column) and self.single_one_in_column(mat, rows, row, column):
                result+=1

        return result

    def single_one_in_row(self, mat: List[List[int]], columns: int, row: int, column: int) -> bool:
        for c in range(0, column):
            if mat[row][c]:
                return False

        for c in range(column + 1, columns):
            if mat[row][c]:
                return False

        return True

    def single_one_in_column(self, mat: List[List[int]], rows: int, row: int, column: int) -> bool:
        for r in range(0, row):
            if mat[r][column]:
                return False

        for r in range(row + 1, rows):
            if mat[r][column]:
                return False

        return True