class Solution:
    def removeDuplicates(self, s: str) -> str:
        result: str=""

        stack: List[chr]=list()

        for character in s:
            if not stack:
                stack.append(character)
            else:
                if stack[-1]!=character:
                    stack.append(character)
                else:
                    stack.pop()

        separator: chr=''

        result=separator.join(stack)

        return result