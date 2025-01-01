class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        result: list[list[int]]=list()

        result.append([1])

        row: int=2

        while row <= numRows:
            next_row: list[int]=list()

            for index in range(0, len(result[-1]) + 1):
                if index==0:
                    next_row.append(result[-1][0])
                elif index==len(result[-1]):
                    next_row.append(result[-1][-1])
                else:
                    next_row.append(result[-1][index - 1] + result[-1][index])

            result.append(next_row)

            row+=1

        return result