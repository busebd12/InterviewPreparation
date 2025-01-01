impl Solution
{
    pub fn make_good(s: String) -> String
    {
        let mut stack: Vec<char>=Vec::new();

        for character in s.chars()
        {
            if stack.is_empty()
            {
                stack.push(character);
            }
            else
            {
                let top_of_stack: char=*(stack.last().unwrap());
                
                if (top_of_stack.is_ascii_lowercase() && character.is_ascii_uppercase()) || (top_of_stack.is_ascii_uppercase() && character.is_ascii_lowercase())
                {
                    if top_of_stack.to_ascii_lowercase()==character.to_ascii_lowercase()
                    {
                        stack.pop();
                    }
                    else
                    {
                        stack.push(character);
                    }
                }
                else
                {
                    stack.push(character);
                }
            }
        }

        stack.into_iter().collect::<String>()
    }
}