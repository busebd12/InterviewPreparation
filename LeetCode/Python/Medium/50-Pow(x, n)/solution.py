#Solution based on this explanation: https://cp-algorithms.com/algebra/binary-exp.html

class Solution:
    def myPow(self, x: float, n: int) -> float:
        result: float=1

        if n < 0:
            x=1 / x

            n=-n

        while n > 0:
            right_most_bit: int=(n & 1)

            if right_most_bit==1:
                result*=x

            x*=x

            n=n >> 1

        return result