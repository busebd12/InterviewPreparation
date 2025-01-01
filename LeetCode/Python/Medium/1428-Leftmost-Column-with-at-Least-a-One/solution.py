class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        result=-1

        dimensions=binaryMatrix.dimensions()

        rows=dimensions[0]

        columns=dimensions[1]

        for row in range(0, rows):
            left_most_column_in_row=self.search_row(binaryMatrix, row, columns)

            if left_most_column_in_row!=-1:
                if result==-1:
                    result=left_most_column_in_row
                else:
                    result=min(result, left_most_column_in_row)

        return result
    
    def search_row(self, binaryMatrix: 'BinaryMatrix', row: int, columns: int) -> int:
        result=-1
        
        low=0

        high=columns - 1

        while low <= high:
            middle=(low + (high - low)//2)

            digit=binaryMatrix.get(row, middle)

            if digit==1:
                high=middle - 1
                
                result=middle
            else:
                low=middle + 1

        return result