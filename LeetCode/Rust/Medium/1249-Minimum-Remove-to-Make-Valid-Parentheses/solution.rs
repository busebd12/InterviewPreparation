impl Solution
{
    pub fn min_remove_to_make_valid(s: String) -> String
    {
        let mut result: String=String::from("");

        let mut s_characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut stack: Vec<usize>=Vec::new();

        for (index, character) in s.char_indices()
        {
            if character=='('
            {
                stack.push(index);
            }
            else if character==')'
            {
                if !stack.is_empty()
                {
                    stack.pop();
                }
                else
                {
                    s_characters[index]='$';
                }
            }
        }

        while let Some(index)=stack.pop()
        {
            s_characters[index]='$';
        }

        result=s_characters.into_iter().filter(|character| *character!='$').collect::<String>();

        result
    }
}