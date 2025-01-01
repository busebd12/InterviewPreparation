impl Solution
{
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i64
    {
        let mut result: i64=-1;

        let n: usize=nums.len();

        nums.sort();

        let mut prefix_sums: Vec<i64>=vec![0; n];

        prefix_sums[0]=nums[0] as i64;

        for index in 1..n
        {
            prefix_sums[index]=prefix_sums[index - 1] + (nums[index] as i64);
        }

        for index in 2..n
        {
            let largest_side: i64=prefix_sums[index] - prefix_sums[index - 1];

            let sum_of_remaining_sides: i64=prefix_sums[index - 1];

            if largest_side < sum_of_remaining_sides
            {
                result=std::cmp::max(result, prefix_sums[index]);
            }
        }

        result
    }
}