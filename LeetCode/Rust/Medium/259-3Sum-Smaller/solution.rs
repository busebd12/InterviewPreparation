impl Solution
{
    pub fn three_sum_smaller(mut nums: Vec<i32>, target: i32) -> i32
    {
        let mut result: i32=0;

        if nums.is_empty()
        {
            return result;
        }

        let n: usize=nums.len();

        if n < 3
        {
            return result;
        }

        nums.sort();

        for index in 0..n-2
        {
            let mut left: usize=index + 1;

            let mut right: usize=n - 1;

            let desired_sum: i32=target - nums[index];

            while left < right
            {
                let current_sum: i32=nums[left] + nums[right];

                if current_sum < desired_sum
                {
                    let pairs: i32=(right - left) as i32;

                    result+=pairs;

                    left+=1;
                }
                else
                {
                    right-=1;
                }
            }
        }

        result
    }
}