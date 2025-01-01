from collections import Counter

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result=""

        hashmap=Counter(s)

        used=set()

        characters=[]

        for character in order:
            if character in hashmap.keys():
                characters.append(character * hashmap[character])

                del hashmap[character]

                used.add(character)

        for character in s:
            if character not in used:
                characters.append(character)

        result=''.join(characters)

        return result

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result=""

        hashmap=[0 for _ in range(0, 26)]

        for character in s:
            ascii=ord(character) - ord('a')

            hashmap[ascii]+=1

        used=[False for _ in range(0, 26)]

        characters=[]

        for character in order:
            ascii=ord(character) - ord('a')

            frequency=hashmap[ascii]

            if frequency > 0:
                characters.append(character * frequency)

                hashmap[ascii]=0

                used[ascii]=True

        for character in s:
            ascii=ord(character) - ord('a')
            
            if not used[ascii]:
                characters.append(character)

        result=''.join(characters)

        return result