class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        result: int=0

        rows: int=len(strs)

        columns: int=len(strs[0])

        for column in range(0, columns):
            for row in range(0, rows - 1):
                if strs[row][column] > strs[row + 1][column]:
                    result+=1

                    break

        return result