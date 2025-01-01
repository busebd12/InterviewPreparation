impl Solution
{
    pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let n: usize=nums.len();

        for i in 0..n
        {
            let number: i32=nums[i].abs();

            let index: usize=(number - 1) as usize;

            if nums[index] < 0
            {
                result.push(number);
            }
            else
            {
                nums[index]*=-1;
            }
        }

        result
    }
}