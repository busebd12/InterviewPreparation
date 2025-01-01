'''
Video on evaluating postfix: https://www.youtube.com/watch?v=84BsI5VJPq4
Video on converting from infix to postfix: https://www.youtube.com/watch?v=vq-nUF0G4fI
Infix to postfix conversion and postfix evaluation: https://runestone.academy/ns/books/published/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html
'''
class Solution:
    def calculate(self, s: str) -> int:
        result=0

        infix=self.preprocess(s)

        postfix=self.convert_to_postfix(infix)

        if postfix.isdigit():
            result=int(postfix)

            return result

        result=self.evaluate_postfix_expression(postfix)

        return result

    def preprocess(self, infix: str) -> str:
        characters=list()

        for character in infix:
            if character.isspace():
                continue
            elif character=='-':
                if not characters or characters[-1]=='(':
                    characters.append('0')

                characters.append(character)
            else:
                characters.append(character)

        return "".join(characters)

    def convert_to_postfix(self, infix: str) -> str:
        postfix_characters=list()

        stack=list()

        n=len(infix)

        index=0

        while index < n:
            character=infix[index]

            if character.isspace():
                continue
            elif self.is_operator(character):
                while stack and stack[-1]!='(' and self.has_higher_precedence(stack[-1], character):
                    postfix_characters.append(stack[-1])

                    postfix_characters.append('$')

                    stack.pop()

                stack.append(character)

                index+=1
            elif character.isdigit():
                number=0

                i=index

                while i < n and infix[i].isdigit():
                    number=(number * 10) + int(infix[i])
                    
                    i+=1

                postfix_characters.append(str(number))

                postfix_characters.append('$')

                index=i
            elif character=='(':
                stack.append(character)

                index+=1
            elif character==')':
                while stack and stack[-1]!='(':
                    postfix_characters.append(stack[-1])

                    postfix_characters.append('$')

                    stack.pop()

                stack.pop()

                index+=1

        while stack:
            postfix_characters.append(stack[-1])

            postfix_characters.append('$')

            stack.pop()

        if postfix_characters[-1]=='$':
            postfix_characters.pop()

        return "".join(postfix_characters)

    def is_operator(self, character: chr) -> bool:
        return character=='+' or character=='-' or character=='*' or character=='/'

    def has_higher_precedence(self, operator1: chr, operator2: chr) -> bool:
        operator1_precedence=self.get_operator_weight(operator1)

        operator2_precedence=self.get_operator_weight(operator2)

        return operator1_precedence >= operator2_precedence

    def get_operator_weight(self, op: chr) -> int:
        weight=-1
        
        if op=='+' or op=='-':
            weight=2
        elif op=='*' or op=='/':
            weight=3

        return weight

    def evaluate_postfix_expression(self, postfix: str) -> int:
        expression_result=0

        stack=list()

        tokens=postfix.split('$')

        for token in tokens:
            if token.isdigit():
                stack.append(int(token))
            elif self.is_operator(token):
                operator_right_side=int(stack.pop())

                operator_left_side=int(stack.pop())

                intermediate_result=self.get_operation_result(token, operator_left_side, operator_right_side)

                expression_result=intermediate_result

                stack.append(intermediate_result)

        return expression_result

    def get_operation_result(self, op: chr, operator_left_side: int, operator_right_side: int) -> int:
        operation_result=-1

        if op=='+':
            operation_result=operator_left_side + operator_right_side
        elif op=='-':
            operation_result=operator_left_side - operator_right_side
        elif op=='*':
            operation_result=operator_left_side * operator_right_side
        elif op=='/':
            negative_result=((operator_left_side < 0 and operator_right_side > 0) or (operator_left_side > 0 and operator_right_side < 0))

            if operator_left_side < 0:
                operator_left_side*=-1

            if operator_right_side < 0:
                operator_right_side*=-1

            operation_result=operator_left_side // operator_right_side

            if operation_result > 0 and negative_result:
                operation_result*=-1

        return operation_result