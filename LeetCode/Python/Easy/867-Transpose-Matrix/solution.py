class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        rows: int=len(matrix)

        columns: int=len(matrix[0])

        transposed: List[List[int]]=[[0 for row in range(0, rows)] for column in range(0, columns)]

        for row in range(0, rows):
            for column in range(0, columns):
                transposed[column][row]=matrix[row][column]

        return transposed