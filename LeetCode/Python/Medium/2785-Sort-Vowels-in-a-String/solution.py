from collections import deque

class Solution:
    def sortVowels(self, s: str) -> str:
        result: str=""

        ascii_table: List[int]=[0 for _ in range(0, 129)]

        vowels: Set[chr]='AEIOUaeiou'

        ordered_vowels: Deque[chr]=deque()

        for letter in s:
            if letter in vowels:
                ascii_value: int=ord(letter)

                ascii_table[ascii_value]+=1

        for index in range(0, 129):
            if ascii_table[index]:
                for count in range(0, ascii_table[index]):
                    ordered_vowels.append(chr(index))

        for letter in s:
            if letter in vowels:
                result+=ordered_vowels.popleft()
            else:
                result+=letter

        return result