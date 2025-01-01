class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encoded: str=""

        n: int=len(strs)

        for index in range(0, n):
            encoded+=self.encode_word(strs[index])
            
            if index < n - 1:
                encoded+="separator"

        return encoded

    def encode_word(self, word: str) -> str:
        encoded: str=""

        n: int=len(word)

        count: int=1

        i: int=0
        
        while i < n:
            j: int=i + 1

            while j < n and word[i]==word[j]:
                j+=1

                count+=1

            encoded+=str(count)

            encoded+=':'

            encoded+=word[i]

            count=1

            i=j

        return encoded

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        decoded: List[str]=list()

        words: List[str]=s.split("separator")

        for word in words:
            decoded.append(self.decode_word(word))
        
        return decoded
    
    def decode_word(self, word: str) -> str:
        w: int=len(word)

        decoded: str=""

        index: int=0

        while index + 2 < w:
            i: int=index
            
            times: int=0

            while i < w and word[i].isdigit():
                times=(times * 10) + int(word[i])

                i+=1

            i+=1

            for count in range(0, times):
                decoded+=word[i]

            index=i + 1

        return decoded

class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encoded: str=""

        n: int=len(strs)

        for index in range(0, n):
            encoded+=self.encode_word(strs[index])
            
            if index < n - 1:
                encoded+='|'

        return encoded

    def encode_word(self, word: str) -> str:
        encoded: str=""

        w: int=len(word)

        for (index, character) in enumerate(word):
            ascii_value: int=ord(character)

            encoded+=str(ascii_value)

            if index < w - 1:
                encoded+=','

        return encoded

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        decoded: List[str]=list()

        words: List[str]=s.split('|')

        for word in words:
            if not word:
                decoded.append(word)
            else:
                decoded.append(self.decode_word(word))
        
        return decoded
    
    def decode_word(self, word: str) -> str:
        ascii_value_strings: List[str]=word.split(',')

        decoded: str=""

        for ascii_value_string in ascii_value_strings:
            character: chr=chr(int(ascii_value_string))

            decoded+=character

        return decoded