class Solution:
    def isValid(self, s: str) -> bool:
        stack: deque[chr]=deque()

        for character in s:
            if character==')':
                opening: chr='('
                
                if self.foundMatching(stack, opening)==False:
                    return False
                else:
                    stack.pop()
            elif character==']':
                opening: chr='['

                if self.foundMatching(stack, opening)==False:
                    return False
                else:
                    stack.pop()
            elif character=='}':
                opening: chr='{'

                if self.foundMatching(stack, opening)==False:
                    return False
                else:
                    stack.pop()
            else:
                stack.append(character)
        
        return len(stack)==0

    def foundMatching(self, stack: deque[chr], opening: chr) -> bool:
        return stack and stack[-1]==opening if stack else False