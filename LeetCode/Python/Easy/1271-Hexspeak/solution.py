class Solution:
    def toHexspeak(self, num: str) -> str:
        hex_string: str=hex(int(num)).upper()

        hex_string=hex_string[2:]

        hex_string_letters: List[chr]=list(hex_string)

        for index in range(0, len(hex_string_letters)):
            if hex_string_letters[index]=='0':
                hex_string_letters[index]='O'

            if hex_string_letters[index]=='1':
                hex_string_letters[index]='I'

        allowed_letters: Set[chr]=set('ABCDEFIO')

        for letter in hex_string_letters:
            if letter not in allowed_letters:
                return "ERROR"

        separator: chr=''

        return separator.join(hex_string_letters)