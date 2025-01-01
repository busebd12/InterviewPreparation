class Solution:
    def __init__(self):
        self.substring_start: int=-1

        self.substring_end: int=-1

        self.max_substring_length: int=0
    
    def longestPalindrome(self, s: str) -> str:
        result: str=""

        n: int=len(s)

        for index in range(0, n):
            left: int=index

            right: int=index

            self.expand_around_center(s, n, left, right)

            right=index + 1

            self.expand_around_center(s, n, left, right)

        result=s[self.substring_start : self.substring_end + 1]

        return result

    def expand_around_center(self, s: str, n: int, left: int, right: int) -> None:
        while left >= 0 and right < n and s[left]==s[right]:
            left-=1

            right+=1

        left+=1

        right-=1

        substring_length: int=(right - left) + 1

        if substring_length > self.max_substring_length:
            self.max_substring_length=substring_length

            self.substring_start=left

            self.substring_end=right