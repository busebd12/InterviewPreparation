class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        result=""

        s_characters=[character for character in s]

        stack=list()

        for (index, character) in enumerate(s_characters):
            if character=='(':
                stack.append(index)
            elif character==')':
                if stack:
                    stack.pop()
                else:
                    s_characters[index]='$'

        while stack:
            index=stack.pop()

            s_characters[index]='$'

        result_characters=list()

        for character in s_characters:
            if character!='$':
                result_characters.append(character)

        result="".join(result_characters)

        return result