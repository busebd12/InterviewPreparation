class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        power_of_four: int=1

        while power_of_four <= n:
            if power_of_four==n:
                return True

            power_of_four*=4

        return False