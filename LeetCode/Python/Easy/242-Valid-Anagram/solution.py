class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_frequencies: list[int]=self.get_frequencies(s)

        t_frequencies: list[int]=self.get_frequencies(t)

        return s_frequencies==t_frequencies

    def get_frequencies(self, string: str) -> list[int]:
        frequencies: list[int]=[0] * 123

        for letter in string:
            ascii: int=ord(letter)

            frequencies[ascii]+=1

        return frequencies