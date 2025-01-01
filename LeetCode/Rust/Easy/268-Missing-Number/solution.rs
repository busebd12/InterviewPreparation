impl Solution
{
    pub fn missing_number(nums: Vec<i32>) -> i32
    {
        let mut result: i32=-1;

        let n: usize=nums.len();

        result=(0..n+1).map(|number| number as i32).sum::<i32>();

        for number in nums.iter()
        {
            result-=*number;
        }

        result
    }
}