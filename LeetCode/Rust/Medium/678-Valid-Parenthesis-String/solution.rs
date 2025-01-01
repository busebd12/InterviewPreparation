impl Solution
{
    pub fn check_valid_string(s: String) -> bool
    {
        let mut open_parenthesis_indices_stack: Vec<usize>=Vec::new();

        let mut stars_indices_stack: Vec<usize>=Vec::new();

        let mut stars: i32=0;

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        for (index, character) in s.char_indices()
        {
            match character
            {
                '(' =>
                {
                    open_parenthesis_indices_stack.push(index);
                },
                ')' =>
                {
                    match open_parenthesis_indices_stack.last()
                    {
                        Some(i) =>
                        {
                            open_parenthesis_indices_stack.pop();
                        },
                        None =>
                        {
                            if stars > 0
                            {
                                stars-=1;

                                stars_indices_stack.pop();
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                },
                '*' =>
                {
                    stars_indices_stack.push(index);

                    stars+=1;
                },
                _ => ()
            }
        }

        while !open_parenthesis_indices_stack.is_empty() && !stars_indices_stack.is_empty()
        {
            let open_parenthesis_index: usize=*(open_parenthesis_indices_stack.last().unwrap());

            let star_index: usize=*(stars_indices_stack.last().unwrap());
            
            match (open_parenthesis_index > star_index)
            {
                true =>
                {
                    return false;
                }
                false =>
                {
                    open_parenthesis_indices_stack.pop();

                    stars_indices_stack.pop();
                }
            }
        }

        open_parenthesis_indices_stack.len()==(0 as usize)
    }
}