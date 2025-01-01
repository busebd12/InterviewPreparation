class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result: str=""

        n: int=len(s)

        include: List[bool]=[False for _ in range(0, n)]

        stack: List[chr]=list()

        for (index, character) in enumerate(s):
            if character=='(':
                if stack:
                    include[index]=True
                
                stack.append(character)
            else:
                if len(stack) > 1:
                    include[index]=True
                
                stack.pop()

        for index in range(0, n):
            if include[index]:
                result+=s[index]
        
        return result