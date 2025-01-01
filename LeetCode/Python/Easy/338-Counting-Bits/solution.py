class Solution:
    def countBits(self, n: int) -> List[int]:
        result: List[int]=[0] * (n + 1)

        for number in range(0, n + 1):
            set_bits: int=self.count_set_bits(number)

            result[number]=set_bits

        return result

    def count_set_bits(self, n: int) -> int:
        set_bits: int=0

        while n > 0:
            bit: int=(n & 1)

            if bit==1:
                set_bits+=1

            n=n >> 1

        return set_bits