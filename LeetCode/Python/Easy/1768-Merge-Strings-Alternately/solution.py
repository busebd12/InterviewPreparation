class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        result: str=""

        n: int=len(word1)

        m: int=len(word2)

        i: int=0

        j: int=0

        while i < n or j < m:
            if i < n:
                result+=word1[i]

                i+=1

            if j < m:
                result+=word2[j]

                j+=1

        return result