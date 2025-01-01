impl Solution
{
    pub fn is_valid(s: String) -> bool
    {
        let mut stack: Vec<char>=Vec::new();

        for character in s.chars()
        {
            if character==')'
            {
                let matching: char='(';

                if Solution::contains_matching(&stack, &matching)==false
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else if character==']'
            {
                let matching: char='[';

                if Solution::contains_matching(&stack, &matching)==false
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else if character=='}'
            {
                let matching: char='{';

                if Solution::contains_matching(&stack, &matching)==false
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else
            {
                stack.push(character);
            }
        }

        stack.is_empty()
    }

    pub fn contains_matching(stack: &Vec<char>, matching: &char) -> bool
    {
        if stack.is_empty()
        {
            return false;
        }

        let top: &char=stack.last().unwrap();

        top==matching
    }
}

impl Solution
{
    pub fn is_valid(s: String) -> bool
    {
        let mut stack: Vec<char>=Vec::new();

        for character in s.chars()
        {
            match(character)
            {
                '{' =>
                {
                    stack.push(character);
                },

                '[' =>
                {
                    stack.push(character);
                },

                '(' =>
                {
                    stack.push(character);
                },

                '}' =>
                {
                    if Some('{')!=stack.pop()
                    {
                        return false;
                    }
                },

                ']' =>
                {
                    if Some('[')!=stack.pop()
                    {
                        return false;
                    }
                },

                ')' =>
                {
                    if Some('(')!=stack.pop()
                    {
                        return false;
                    }
                },

                _ => (),
            }
        }

        stack.is_empty()
    }
}