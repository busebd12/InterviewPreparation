from collections import deque

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        result: List[int]=list()

        queue: Deque[int]=deque()
        
        n: int=len(digits)

        carry: int=0

        for index in range(n-1, -2, -1):
            total: int=carry

            if index >= 0:
                if index==n-1:
                    total+=1

                total+=digits[index]

            if (index >= 0 and total >= 0) or (index < 0 and total > 0):
                queue.appendleft(total % 10)

            carry=total // 10

        result=[number for number in queue]

        return result