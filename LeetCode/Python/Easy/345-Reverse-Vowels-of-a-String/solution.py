from collections import deque

class Solution:
    def reverseVowels(self, s: str) -> str:
        result: str=""

        n: int=len(s)

        left: int=0

        right: int=n-1

        vowels: Set[chr]=set('AEIOUaeiou')

        s_vowels: Deque[chr]=deque()

        for character in s:
            if character in vowels:
                s_vowels.append(character)

        s_vowels.reverse()

        for character in s:
            if character not in vowels:
                result+=character
            else:
                result+=s_vowels.popleft()

        return result