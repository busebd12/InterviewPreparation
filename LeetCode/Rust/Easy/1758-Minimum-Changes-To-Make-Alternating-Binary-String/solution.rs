impl Solution
{
    pub fn min_operations(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();

        let digits: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut start: char='0';

        let mut alternating: Vec<char>=Self::generate_alternating(n, start);

        result=Self::count_differences(&digits, &alternating, n) as i32;

        start='1';

        alternating=Self::generate_alternating(n, start);

        result=i32::min(result, Self::count_differences(&digits, &alternating, n) as i32);

        result
    }

    pub fn generate_alternating(n: usize, start: char) -> Vec<char>
    {
        let mut alternating: Vec<char>=vec!['$'; n];

        alternating[0]=start;

        for index in 1..n
        {
            if alternating[index - 1]=='0'
            {
                alternating[index]='1';    
            }
            else
            {
                alternating[index]='0';
            }
        }

        alternating
    }

    pub fn count_differences(digits: &Vec<char>, alternating: &Vec<char>, n: usize) -> u32
    {
        let mut differences: u32=0;

        for index in 0..n
        {
            if digits[index]!=alternating[index]
            {
                differences+=1;
            }
        }

        differences
    }
}