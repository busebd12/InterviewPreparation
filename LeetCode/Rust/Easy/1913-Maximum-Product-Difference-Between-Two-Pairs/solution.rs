impl Solution
{
    pub fn max_product_difference(mut nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        nums.sort();

        let first: i32=nums[n - 1] * nums[n - 2];

        let second: i32=nums[0] * nums[1];

        result=first - second;

        result
    }
}

impl Solution
{
    pub fn max_product_difference(mut nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let limit: u32=10u32.pow(4) + 1;

        let mut buckets: Vec<u32>=vec![0; limit as usize];

        for &number in nums.iter()
        {
            buckets[number as usize]+=1
        }

        let first: i32=Solution::get_max_pair_product(&nums, &buckets, limit);

        let second: i32=Solution::get_min_pair_produce(&nums, &buckets, limit);

        result=first - second;

        result
    }

    pub fn get_max_pair_product(nums: &Vec<i32>, buckets: &Vec<u32>, limit: u32) -> i32
    {
        let mut first: i32=-1;

        let mut largest: i32=-1;

        let mut second_largest: i32=-1;

        for number in (1..limit).rev()
        {
            if buckets[number as usize] > 0
            {
                if buckets[number as usize]==1
                {
                    if largest==-1 && second_largest==-1
                    {
                        largest=number as i32;
                    }
                    else if second_largest==-1
                    {
                        second_largest=number as i32;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if largest==-1 && second_largest==-1
                    {
                        largest=number as i32;

                        second_largest=number as i32;
                    }
                    else if second_largest==-1
                    {
                        second_largest=number as i32;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        first=largest * second_largest;

        first
    }

    pub fn get_min_pair_produce(nums: &Vec<i32>, buckets: &Vec<u32>, limit: u32) -> i32
    {
        let mut second: i32=-1;

        let mut smallest: i32=-1;

        let mut second_smallest: i32=-1;

        for number in 1..limit
        {
            if buckets[number as usize] > 0
            {
                if buckets[number as usize]==1
                {
                    if smallest==-1 && second_smallest==-1
                    {
                        smallest=number as i32;
                    }
                    else if second_smallest==-1
                    {
                        second_smallest=number as i32;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if smallest==-1 && second_smallest==-1
                    {
                        smallest=number as i32;

                        second_smallest=number as i32;
                    }
                    else if second_smallest==-1
                    {
                        second_smallest=number as i32;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        second=smallest * second_smallest;

        second
    }
}