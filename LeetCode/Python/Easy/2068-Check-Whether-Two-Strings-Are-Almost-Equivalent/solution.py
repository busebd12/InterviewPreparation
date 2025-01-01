class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        word1_hashmap: dict[chr, int]=dict()

        word2_hashmap: dict[chr, int]=dict()

        for character in word1:
            if character not in word1_hashmap:
                word1_hashmap[character]=0

            word1_hashmap[character]+=1

        for character in word2:
            if character not in word2_hashmap:
                word2_hashmap[character]=0

            word2_hashmap[character]+=1

        k: int=3

        for ascii in range(ord('a'), ord('z') + 1):
            letter: chr=chr(ascii)

            word1_letter_frequency: int=0

            if letter in word1_hashmap:
                word1_letter_frequency=word1_hashmap[letter]
            
            word2_letter_frequency: int=0

            if letter in word2_hashmap:
                word2_letter_frequency=word2_hashmap[letter]

            difference: int=abs(word1_letter_frequency - word2_letter_frequency)

            if difference > k:
                return False

        return True