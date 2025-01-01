class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        result: int=0

        rows: int=len(matrix)

        columns: int=len(matrix[0])

        hashmap: Dict[int, List[int]]=dict()

        for row in range(0, rows):
            hashmap[row]=list()

        for column in range(0, columns):
            ones: int=0

            for row in range(0, rows):
                if matrix[row][column]:
                    ones+=1

                    hashmap[row].append(ones)
                else:
                    ones=0

        for row in range(0, rows):
            hashmap[row].sort(reverse=True)

        for row in range(0, rows):
            width: int=1

            for height in hashmap[row]:
                area: int=height * width

                result=max(result, area)

                width+=1

        return result