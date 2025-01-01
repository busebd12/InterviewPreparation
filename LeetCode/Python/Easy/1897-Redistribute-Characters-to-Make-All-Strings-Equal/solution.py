class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        w=len(words)

        hashmap=dict()

        for word in words:
            for character in word:
                if character not in hashmap.keys():
                    hashmap[character]=0

                hashmap[character]+=1

        for frequency in hashmap.values():
            if frequency % w != 0:
                return False

        return True

class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        w=len(words)

        hashmap=[0 for _ in range(0, 26)]

        for word in words:
            for character in word:
                ascii=ord(character) - ord('a')

                hashmap[ascii]+=1

        for ascii in range(0, 26):
            frequency=hashmap[ascii]

            if frequency % w != 0:
                return False

        return True