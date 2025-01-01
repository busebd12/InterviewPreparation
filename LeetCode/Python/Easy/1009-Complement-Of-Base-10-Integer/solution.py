class Solution:
    def bitwiseComplement(self, n: int) -> int:
        result: int=0

        binary: str=bin(n)[2:]

        complement: str=""

        for digit in binary:
            if digit=='1':
                complement+='0'
            else:
                complement+='1'

        result=int(complement, 2)

        return result

class Solution:
    def bitwiseComplement(self, n: int) -> int:
        result: int=0

        if n==0:
            return 1

        position: int=0

        while n > 0:
            if (n & 1)==0:
                result=result + (1 << position)
            
            position+=1

            n=n >> 1

        return result