class Solution:
    def parseTernary(self, expression: str) -> str:
        result: str=""

        n: int=len(expression)

        stack: List[chr]=list()

        for index in range(n-1, -1, -1):
            character: chr=expression[index]
            
            if character=='T' or character=='F':
                if index + 1 < n and expression[index + 1]=='?':
                    true_option: chr=stack.pop()
                    
                    false_option: chr=stack.pop()

                    if character=='T':
                        stack.append(true_option)
                    else:
                        stack.append(false_option)
                else:
                    stack.append(character)
            elif character!='?' and character!=':':
                stack.append(character)

        result=''.join(stack)

        return result

class Solution:
    def parseTernary(self, expression: str) -> str:
        result: str=""

        n: int=len(expression)

        stack: List[chr]=list()

        for (index, character) in enumerate(reversed(expression)):
            if character=='T' or character=='F':
                after_index: int=n - index
                if after_index < n and expression[after_index]=='?':
                    true_option: chr=stack.pop()

                    false_option: chr=stack.pop()

                    if character=='T':
                        stack.append(true_option)
                    else:
                        stack.append(false_option)
                else:
                    stack.append(character)
            elif character!='?' and character!=':':
                stack.append(character)

        result=''.join(stack)

        return result