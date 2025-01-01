class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        result=0

        stack=list()

        for character in s:
            if character=='(':
                stack.append(character)
            else:
                if stack:
                    stack.pop()
                else:
                    result+=1

        result+=len(stack)

        return result

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        result=0

        open_parenthesis=0

        closed_parenthesis=0

        for character in s:
            if character=='(':
                open_parenthesis+=1
            else:
                if open_parenthesis > 0:
                    open_parenthesis-=1
                else:
                    closed_parenthesis+=1

        if open_parenthesis > 0:
            result+=open_parenthesis

        if closed_parenthesis > 0:
            result+=closed_parenthesis

        return result