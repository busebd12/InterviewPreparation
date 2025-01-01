impl Solution
{
    pub fn minimum_length(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut left: i32=0;

        let mut right: i32=(n - 1) as i32;

        while left < right && characters[left as usize]==characters[right as usize]
        {
            let character: char=characters[left as usize];

            while left <= right && characters[left as usize]==character
            {
                left+=1;
            }

            while right >= left && characters[right as usize]==character
            {
                right-=1;
            }
        }

        result=(right - left) + 1;

        result
    }
}