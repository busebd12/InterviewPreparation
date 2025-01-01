class Solution:
    def makeGood(self, s: str) -> str:
        result=""

        stack=list()

        for character in s:
            if not stack:
                stack.append(character)
            else:
                if (stack[-1].isupper() and character.islower()) or (character.isupper() and stack[-1].islower()):
                    if stack[-1].lower()==character.lower():
                        stack.pop()
                    else:
                        stack.append(character)
                else:
                    stack.append(character)

        result="".join(stack)

        return result
        