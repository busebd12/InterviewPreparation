class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        n: int=len(word)

        m: int=len(abbr)

        i: int=0

        j: int=0

        while i < n and j < m:
            if word[i]==abbr[j]:
                i+=1

                j+=1
            elif abbr[j]=='0':
                return False
            elif abbr[j].isnumeric():
                offset: int=0

                while j < m and abbr[j].isnumeric():
                    offset=(offset * 10) + int(abbr[j])

                    j+=1

                i+=offset
            else:
                return False

        return i==n and j==m