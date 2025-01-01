class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result: str=""

        while columnNumber > 0:
            columnNumber-=1

            mod_value: int =(columnNumber % 26)

            letter_ascii_value: int=mod_value + ord('A')

            letter: chr=chr(letter_ascii_value)

            result=letter + result

            columnNumber //= 26

        return result