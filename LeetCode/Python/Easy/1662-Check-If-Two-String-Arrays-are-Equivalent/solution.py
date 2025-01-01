class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        first: str=''.join(word1)

        second: str=''.join(word2)

        return first==second