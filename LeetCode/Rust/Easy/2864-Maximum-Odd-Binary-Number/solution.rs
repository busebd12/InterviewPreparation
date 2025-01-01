impl Solution
{
    pub fn maximum_odd_binary_number(s: String) -> String
    {
        let mut result: String=String::from("");

        let n: usize=s.len();

        let mut ones: usize=s.chars().filter(|&c| c=='1').count();

        let mut digits: Vec<char>=vec!['0'; n];

        digits[n - 1]='1';

        ones-=1;

        for index in 0..ones
        {
            digits[index]='1';
        }

        result=digits.into_iter().collect::<String>();

        result
    }
}