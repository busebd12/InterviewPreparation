class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        result=list()

        n=len(currentState)

        can_flip=False

        for index in range(1, n):
            if currentState[index]=='+' and currentState[index - 1]=='+':
                can_flip=True

                break
        
        if not can_flip:
            return result

        indices_to_flip=list()

        for index in range(1, n):
            if currentState[index]=='+' and currentState[index - 1]=='+':
                indices_to_flip.append((index - 1, index))

        for count in range(0, len(indices_to_flip)):
            signs=[currentState[index] for index in range(0, n)]

            first_index=indices_to_flip[count][0]

            second_index=indices_to_flip[count][1]

            signs[first_index]='-'

            signs[second_index]='-'

            next_state=''.join(signs)

            result.append(next_state)

        return result