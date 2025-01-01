class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        result: int=0

        n: int=len(piles)

        piles.sort()

        largest_index: int=n - 1

        second_largest_index: int=n - 2

        groups: int=n // 3

        count: int=0

        while count < groups:
            result+=piles[second_largest_index]

            largest_index-=2

            second_largest_index-=2

            count+=1

        return result