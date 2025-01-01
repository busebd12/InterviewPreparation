class Solution:
    def minimumLength(self, s: str) -> int:
        result=0

        n=len(s)

        left=0

        right=n - 1

        while left < right and s[left]==s[right]:
            character=s[left]

            while left <= right and s[left]==character:
                left+=1

            while right >= left and s[right]==character:
                right-=1
        
        result=(right - left) + 1

        return result