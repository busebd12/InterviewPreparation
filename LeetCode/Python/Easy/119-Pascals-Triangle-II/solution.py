class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        result: List[int]=[1]
        
        row: int=0

        while row < rowIndex:
            next_row_length: int=len(result) + 1
            
            next_row: List[int]=[-1] * next_row_length

            for index in range(0, next_row_length):
                if index==0:
                    next_row[index]=result[index]
                elif index==(next_row_length - 1):
                    next_row[index]=result[index - 1]
                else:
                    next_row[index]=(result[index - 1] + result[index])

            result=next_row

            row+=1

        return result