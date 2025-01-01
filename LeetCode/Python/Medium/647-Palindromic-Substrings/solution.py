class Solution:
    def countSubstrings(self, s: str) -> int:
        result=0

        n=len(s)

        for index in range(0, n):
            result+=self.expand_around_center(s, n, index, index)

            result+=self.expand_around_center(s, n, index, index + 1)

        return result

    def expand_around_center(self, s: str, n: int, left: int, right: int) -> int:
        palindromes=0

        while left >= 0 and right < n and s[left]==s[right]:
            palindromes+=1

            left-=1

            right+=1

        return palindromes