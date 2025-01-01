impl Solution
{
    pub fn find_duplicate(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let limit: usize=usize::pow(10, 5) + 1;

        let mut seen: Vec<bool>=vec![false; limit];

        for number in nums.iter()
        {   
            match seen[*number as usize]
            {
                true =>
                {
                    result=*number;

                    break;
                },
                false =>
                {
                    seen[*number as usize]=true;
                }
            };
        }

        result
    }
}

impl Solution
{
    pub fn find_duplicate(mut nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        for i in 0..n
        {
            let number: i32=nums[i].abs();
            
            let index: usize=(number - 1) as usize;

            nums[index]*=-1;

            if nums[index] > 0
            {
                result=number;

                break;
            }
        }

        result
    }
}