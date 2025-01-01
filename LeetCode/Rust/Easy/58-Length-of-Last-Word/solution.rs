impl Solution
{
    pub fn length_of_last_word(s: String) -> i32
    {
        let mut result: i32=0;

        let trimmed: String=s.trim().to_string();

        let words: Vec<String>=trimmed.split(" ").map(|part| part.to_string()).collect::<Vec<String>>();

        result=(*(words.last().unwrap())).len() as i32;

        result
    }
}

impl Solution
{
    pub fn length_of_last_word(s: String) -> i32
    {
        let mut result: i32=0;

        let trimmed: String=s.trim().to_string();

        let characters: Vec<char>=trimmed.chars().collect::<Vec<char>>();

        let c: usize=characters.len();

        let mut right: i32=(c - 1) as i32;

        while right >= 0 && characters[right as usize].is_whitespace()
        {
            right-=1;
        }

        let mut left: i32=right;

        while left >= 0 && characters[left as usize].is_alphabetic()
        {
            left-=1;
        }

        left+=1;

        result=((right - left) + 1) as i32;

        result
    }
}