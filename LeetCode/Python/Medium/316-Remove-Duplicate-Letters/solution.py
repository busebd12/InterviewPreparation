class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        result: str=""

        seen: List[bool]=[False] * 26

        frequencies: List[int]=[0] * 26

        for letter in s:
            ascii_value: int=ord(letter) - ord('a')

            frequencies[ascii_value]+=1

        stack: List[chr]=list()

        for letter in s:
            ascii_value: int=ord(letter) - ord('a')
            
            if not stack:
                stack.append(letter)

                frequencies[ascii_value]-=1

                seen[ascii_value]=True
            else:
                while stack and letter < stack[-1] and frequencies[ord(stack[-1]) - ord('a')] > 0 and not seen[ascii_value]:
                    seen[ord(stack[-1]) - ord('a')]=False
                    
                    stack.pop()

                if not seen[ascii_value]:
                    stack.append(letter)

                    seen[ascii_value]=True

                frequencies[ascii_value]-=1

        separator: chr=''

        result=separator.join(stack)

        return result