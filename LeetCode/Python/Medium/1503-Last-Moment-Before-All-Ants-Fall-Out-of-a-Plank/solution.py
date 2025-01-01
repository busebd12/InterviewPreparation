class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        result: int=0

        for position in left:
            distance: int=abs(0 - position)

            result=max(result, distance)

        for position in right:
            distance: int=abs(n - position)

            result=max(result, distance)

        return result