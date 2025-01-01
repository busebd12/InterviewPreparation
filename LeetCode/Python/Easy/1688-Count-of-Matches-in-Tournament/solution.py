class Solution:
    def numberOfMatches(self, n: int) -> int:
        result: int=0

        while n > 1:
            matches: int=0

            team: int=0

            if n % 2 == 0:
                matches=n // 2

                teams=n // 2
            else:
                matches=(n - 1) // 2

                teams=matches + 1

            n=teams

            result+=matches

        return result

class Solution:
    def numberOfMatches(self, n: int) -> int:
        return n-1