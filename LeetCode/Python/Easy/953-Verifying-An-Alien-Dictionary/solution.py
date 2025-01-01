class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        ordering: list[int]=[-1] * 123

        n: int=len(order)

        w: int=len(words)

        for index in range(0, n):
            letter: chr=order[index]

            ascii: int=ord(letter)

            ordering[ascii]=index

        for index in range(0, w-1):
            if self.in_order(ordering, words[index], words[index + 1])==False:
                return False

        return True

    def in_order(self, ordering: list[int], word1: str, word2: str) -> bool:
        w1: int=len(word1)

        w2: int=len(word2)

        limit: int=min(w1, w2)

        for index in range(0, limit):
            word1_letter: chr=word1[index]

            word1_ascii: int=ord(word1_letter)

            word2_letter: chr=word2[index]

            word2_ascii: int=ord(word2_letter)

            if ordering[word1_ascii] > ordering[word2_ascii]:
                return False
            elif ordering[word1_ascii] < ordering[word2_ascii]:
                return True

        return True if w1 <= w2 else False