class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        result=0

        s=s.strip()

        words=s.split(" ")

        result=len(words[len(words) - 1])

        return result

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        result=0

        n=len(s)

        if s.isspace():
            return result

        right=n - 1

        while right >= 0 and s[right].isspace():
            right-=1

        left=right

        while left >= 0 and s[left].isalpha():
            left-=1

        left+=1

        result=(right - left) + 1

        return result