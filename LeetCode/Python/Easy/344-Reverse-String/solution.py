class Solution:
    def reverseString(self, s: List[str]) -> None:
        n: int=len(s)

        low: int=0

        high: int=n-1

        while low < high:
            s[low], s[high]=s[high], s[low]

            low+=1

            high-=1