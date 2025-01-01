class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        result=-1

        n=len(s)

        hashmap=dict()

        for (index, character) in enumerate(s):
            if character not in hashmap.keys():
                hashmap[character]=index
            else:
                substring_length=((index - hashmap[character]) + 1) - 2

                result=max(result, substring_length)

        return result