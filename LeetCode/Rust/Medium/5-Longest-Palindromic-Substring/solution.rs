impl Solution
{
    pub fn longest_palindrome(s: String) -> String
    {
        let mut result: String=String::new();

        let n: usize=s.len();

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut substring_start: i32=-1;

        let mut substring_end: i32=-1;

        let mut max_substring_length: i32=0;

        for index in 0..n
        {
            let mut left: i32=index as i32;

            let mut right: i32=index as i32;

            Self::expand_around_center(&characters, n, &mut max_substring_length, &mut substring_start, &mut substring_end, left, right);

            right+=1;

            Self::expand_around_center(&characters, n, &mut max_substring_length, &mut substring_start, &mut substring_end, left, right);
        }

        result=s[substring_start as usize..=substring_end as usize].to_string();

        result
    }

    pub fn expand_around_center(characters: &Vec<char>, n: usize, max_substring_length: &mut i32, substring_start: &mut i32, substring_end: &mut i32, mut left: i32, mut right: i32) -> ()
    {
        while left >= 0 && (right as usize) < n && characters[left as usize]==characters[right as usize]
        {   
            left-=1;

            right+=1;
        }

        left+=1;

        right-=1;

        let substring_length: i32=(right - left) + 1;

        if substring_length > *max_substring_length
        {
            *max_substring_length=substring_length;

            *substring_start=left;

            *substring_end=right;
        }
    }
}