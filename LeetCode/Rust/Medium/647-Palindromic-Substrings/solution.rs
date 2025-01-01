impl Solution
{
    pub fn count_substrings(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        for index in 0..n
        {
            Self::expand_around_center(&characters, &mut result, n, index as i32, index);

            Self::expand_around_center(&characters, &mut result, n, index as i32, index + 1);
        }

        result
    }

    fn expand_around_center(characters: &Vec<char>, result: &mut i32, n: usize, mut left: i32, mut right: usize) -> ()
    {
        while left >= 0 && right < n && characters[left as usize]==characters[right]
        {
            *result+=1;
            
            left-=1;

            right+=1;
        }
    }
}