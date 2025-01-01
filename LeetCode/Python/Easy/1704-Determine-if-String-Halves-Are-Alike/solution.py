class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n=len(s)

        half=n // 2

        first_half_vowels=0

        for index in range(0, half):
            if self.is_vowel(s[index]):
                first_half_vowels+=1

        second_half_vowels=0

        for index in range(half, n):
            if self.is_vowel(s[index]):
                second_half_vowels+=1

        return first_half_vowels==second_half_vowels

    def is_vowel(self, character: chr) -> bool:
        vowels=set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])

        return character in vowels