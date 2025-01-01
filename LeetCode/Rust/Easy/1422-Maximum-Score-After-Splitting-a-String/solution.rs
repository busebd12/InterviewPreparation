impl Solution
{
    pub fn max_score(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();

        let mut zeros_to_the_left: Vec<u32>=vec![0; n];

        let mut zeros: u32=0;

        for (index, digit) in s.char_indices()
        {
            if digit=='0'
            {
                zeros+=1;
            }

            zeros_to_the_left[index]=zeros;
        }

        let mut ones_to_the_right: Vec<u32>=vec![0; n];

        let mut ones: u32=0;

        for (index, digit) in s.char_indices().rev()
        {
            if digit=='1'
            {
                ones+=1;
            }

            ones_to_the_right[index]=ones;
        }

        for index in 1..n
        {
            zeros=zeros_to_the_left[index - 1];

            ones=ones_to_the_right[index];

            let total: u32=ones + zeros;

            result=i32::max(result, total as i32);
        }

        result
    }
}