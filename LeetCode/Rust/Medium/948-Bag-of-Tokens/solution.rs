impl Solution
{
    pub fn bag_of_tokens_score(mut tokens: Vec<i32>, mut power: i32) -> i32
    {
        let mut score: i32=0;

        if tokens.is_empty()
        {
            return score;
        }

        let n: usize=tokens.len();

        tokens.sort();

        if power < tokens[0]
        {
            return score;
        }

        let mut left: usize=0;

        let mut right: i32=(n as i32) - 1;

        while left < (right as usize)
        {
            if power >= tokens[left]
            {
                power-=tokens[left];
                
                score+=1;

                left+=1;
            }
            else if score > 0
            {
                power+=tokens[right as usize];

                score-=1;

                right-=1;
            }
        }

        if power >= tokens[left]
        {
            score+=1;
        }

        score
    }
}