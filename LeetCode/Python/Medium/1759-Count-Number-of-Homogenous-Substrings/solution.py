class Solution:
    def countHomogenous(self, s: str) -> int:
        result: int=0

        n: int=len(s)

        MOD: int=(10**9) + 7

        i: int=0

        while i < n:
            j: int=i + 1

            length: int=1

            while j < n and s[i]==s[j]:
                length+=1

                j+=1

            substrings: int=((length * (length + 1)) // 2) % MOD

            result+=substrings

            i=j
        
        return result