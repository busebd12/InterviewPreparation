from collections import deque

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result: str=""

        n: int=len(a)

        m: int=len(b)

        i: int=n-1

        j: int=m-1

        carry: int=0

        digits: deque[int]=deque()

        while i >= 0 or j >= 0 or carry > 0:
            sum: int=carry

            if i >= 0:
                sum+=int(a[i])

                i-=1

            if j >= 0:
                sum+=int(b[j])

                j-=1

            carry=sum // 2

            digit: int=sum % 2

            digits.appendleft(digit)

        separator: chr=''

        result=separator.join(str(digit) for digit in digits)

        return result