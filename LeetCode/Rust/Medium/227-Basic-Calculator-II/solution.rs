/*
Video on evaluating postfix: https://www.youtube.com/watch?v=84BsI5VJPq4
Video on converting from infix to postfix: https://www.youtube.com/watch?v=vq-nUF0G4fI
Infix to postfix conversion and postfix evaluation: https://runestone.academy/ns/books/published/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html
*/
impl Solution
{
    pub fn calculate(s: String) -> i32
    {
        let mut result: i32=0;

        let infix: String=Self::preprocess(s);

        let postfix: String=Self::convert_to_postfix(infix);

        if postfix.chars().all(|character| character.is_digit(10))
        {
            result=postfix.parse().unwrap();

            return result;
        }

        result=Self::evaluate_postfix_expression(postfix);

        result
    }

    fn preprocess(infix: String) -> String
    {
        let mut processed: String=String::from("");

        let mut characters: Vec<char>=Vec::new();

        for character in infix.chars()
        {
            if character.is_whitespace()
            {
                continue;
            }
            else if character=='-'
            {
                if characters.is_empty() || *characters.last().unwrap()=='('
                {
                    characters.push('0');
                }

                characters.push(character);
            }
            else
            {
                characters.push(character);
            }
        }

        characters.into_iter().collect::<String>()
    }

    fn convert_to_postfix(infix: String) -> String
    {
        let mut postfix: String=String::new();

        let mut stack: Vec<char>=Vec::new();

        let n: usize=infix.len();

        let infix_characters: Vec<char>=infix.chars().collect::<Vec<char>>();

        let mut index: usize=0;

        while index < n
        {
            let character: char=infix_characters[index];

            if Self::is_operator(character)
            {
                while !stack.is_empty() && stack[stack.len() - 1]!='(' && Self::has_higher_precedence(stack[stack.len() - 1], character)
                {
                    postfix.push(stack[stack.len() - 1]);

                    postfix.push('$');

                    stack.pop();
                }

                stack.push(character);

                index+=1;
            }
            else if character.is_digit(10)
            {   
                let mut number: i32=0;

                let mut i: usize=index;

                while i < n && infix_characters[i].is_digit(10)
                {
                    let digit: u32=infix_characters[i] as u32 - '0' as u32;
                    
                    number=(number * 10) + (digit as i32);

                    i+=1;
                }

                postfix.push_str(number.to_string().as_str());

                postfix.push('$');

                index=i;
            }
            else if character=='('
            {
                stack.push(character);

                index+=1;
            }
            else if character==')'
            {
                while !stack.is_empty() && stack[stack.len() - 1]!='('
                {
                    postfix.push(stack[stack.len() - 1]);

                    postfix.push('$');

                    stack.pop();
                }

                stack.pop();

                index+=1;
            }
        }

        while let Some(character)=stack.pop()
        {
            postfix.push(character);

            postfix.push('$');
        }

        if postfix.ends_with('$')
        {
            postfix.pop();
        }

        postfix
    }

    fn is_operator(character: char) -> bool
    {
        character=='+' || character=='-' || character=='*' || character=='/'
    }

    fn has_higher_precedence(operator1: char, operator2: char) -> bool
    {
        let operator1_weight: i32=Self::get_operator_weight(operator1);

        let operator2_weight: i32=Self::get_operator_weight(operator2);

        operator1_weight >= operator2_weight
    }

    fn get_operator_weight(operator: char) -> i32
    {
        let mut weight: i32=-1;

        if operator=='+' || operator=='-'
        {
            weight=2;
        }
        else if operator=='*' || operator=='/'
        {
            weight=3;
        }

        weight
    }

    fn evaluate_postfix_expression(postfix: String) -> i32
    {
        let mut expression_result: i32=0;

        let mut stack: Vec<i32>=Vec::new();

        let tokens: Vec<String>=postfix.split('$').map(|element| element.to_string()).collect::<Vec<String>>();

        for token in &tokens
        {
            if (*token).chars().all(|character| character.is_digit(10))
            {
                stack.push(token.parse().unwrap());
            }
            else
            {
                let operator_right_side: i32=stack.pop().unwrap();

                let operator_left_side: i32=stack.pop().unwrap();
                
                let operator: char=(*token).chars().next().unwrap();

                let intermediate_result: i32=Self::get_operation_result(operator, operator_left_side, operator_right_side);

                expression_result=intermediate_result;

                stack.push(intermediate_result);
            }
        }

        expression_result
    }

    fn get_operation_result(operator: char, operator_left_side: i32, operator_right_side: i32) -> i32
    {
        let mut operation_result: i32=0;

        match operator
        {
            '+' =>
            {
                operation_result=operator_left_side + operator_right_side;
            },
            '-' =>
            {
                operation_result=operator_left_side - operator_right_side;   
            },
            '*' =>
            {
                operation_result=operator_left_side * operator_right_side;
            },
            '/' =>
            {
                operation_result=operator_left_side / operator_right_side;
            },
            _ => ()
        }

        operation_result
    }
}