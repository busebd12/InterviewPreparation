impl Solution
{
    pub fn generate_possible_next_moves(current_state: String) -> Vec<String>
    {
        let mut result: Vec<String>=Vec::new();

        let n: usize=current_state.len();

        let mut can_flip: bool=false;

        let characters: Vec<char>=current_state.chars().collect::<Vec<char>>();

        for index in 1..n
        {
            if characters[index]=='+' && characters[index - 1]=='+'
            {
                can_flip=true;

                break;
            }
        }

        if !can_flip
        {
            return result;
        }

        let mut indices_to_flip: Vec<(usize, usize)>=vec![];

        for index in 1..n
        {
            if characters[index]=='+' && characters[index - 1]=='+'
            {
                indices_to_flip.push((index - 1, index));
            }
        }

        for count in 0..indices_to_flip.len()
        {
            let mut signs: Vec<char>=characters.clone();

            let first_index: usize=indices_to_flip[count].0;

            let second_index: usize=indices_to_flip[count].1;

            signs[first_index]='-';

            signs[second_index]='-';

            let next_state: String=signs.into_iter().collect::<String>();

            result.push(next_state);
        }

        result
    }
}