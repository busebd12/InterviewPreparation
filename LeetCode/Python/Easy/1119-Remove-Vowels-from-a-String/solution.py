class Solution:
    def removeVowels(self, s: str) -> str:
        result=""
        
        left_over=list()

        lowercase_vowels=set(['a', 'e', 'i', 'o', 'u'])

        for character in s:
            if character not in lowercase_vowels:
                left_over.append(character)

        result=''.join(left_over)

        return result