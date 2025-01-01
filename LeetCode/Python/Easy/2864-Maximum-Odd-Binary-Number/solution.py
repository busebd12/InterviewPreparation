class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        result=""

        n=len(s)

        ones=0

        for digit in s:
            if digit=='1':
                ones+=1

        digits=['0' for _ in range(0, n)]

        digits[n - 1]='1'

        ones-=1

        for index in range(0, ones):
            digits[index]='1'

        result=''.join(digits)

        return result