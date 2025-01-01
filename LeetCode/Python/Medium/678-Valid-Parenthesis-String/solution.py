class Solution:
    def checkValidString(self, s: str) -> bool:
        open_parenthesis_indices_stack=list()

        stars_indices_stack=list()

        stars=0

        for (index, character) in enumerate(s):
            if character=='(':
                open_parenthesis_indices_stack.append(index)
            #If the character is a closing parenthesis, there are three cases
            elif character==')':
                #1) if there is a corresponding open parenthesis before the current closing parenthesis, then we can pair them up
                if open_parenthesis_indices_stack:
                    #Remove index of corresponding open parenthesis from the stack
                    open_parenthesis_indices_stack.pop()
                else:
                    #2) We haven't seen a corresponding open parenthesis before but we have at least one * we can substitute for a open parenthesis
                    if stars > 0:
                        stars-=1

                        stars_indices_stack.pop()
                    #3) We have neither an available open parenthesis nor an available * to use. Therefore, the string is invalid and we return false.
                    else:
                        return False
            elif character=='*':
                stars+=1

                stars_indices_stack.append(index)

        #At this point, we've paired up all the closing parenthesis with either an open parenthesis or a *
        #So, the only characters left in the string are either ( or *
        #All that's left is to make sure that all the * characters come after all the ( characters
        #How do we do this? By ensuring that all * character indices come after (are greater than/are not less than) all ( indices
        while open_parenthesis_indices_stack and stars_indices_stack:
            if stars_indices_stack[-1] < open_parenthesis_indices_stack[-1]:
                return False

            open_parenthesis_indices_stack.pop()

            stars_indices_stack.pop()

        #Finally, if we've successfully paired up all ( characters with * characters, then the open parenthesis indices stack should be empty
        #If it is not, then the string is invalid and return False
        return len(open_parenthesis_indices_stack)==0