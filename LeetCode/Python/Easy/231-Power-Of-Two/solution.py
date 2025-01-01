class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        set_bits: int=0

        while n > 0:
            right_most_bit: int=(n & 1)

            if right_most_bit==1:
                set_bits+=1

            n=n >> 1

        return set_bits==1