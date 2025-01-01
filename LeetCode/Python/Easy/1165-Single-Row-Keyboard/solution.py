class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        result=0

        hashmap=[0 for _ in range(0, 26)]

        for (index, character) in enumerate(keyboard):
            ascii_index=ord(character) - ord('a')

            hashmap[ascii_index]=index

        previous_key_index=0

        for character in word:
            character_ascii=ord(character) - ord('a')

            key_index=hashmap[character_ascii]

            result+=abs(key_index - previous_key_index)

            previous_key_index=key_index

        return result