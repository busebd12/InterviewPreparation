class Solution:
    def countOdds(self, low: int, high: int) -> int:
        result: int=0

        length: int=(high - low) + 1

        if length % 2 == 1:
            if low % 2 == 1 and high % 2 == 1:
                result=(length // 2) + 1
            elif low % 2 == 0 and high % 2 == 0:
                result=length // 2
        else:
            result=length // 2

        return result