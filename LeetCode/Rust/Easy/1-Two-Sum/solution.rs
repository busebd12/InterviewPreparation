use std::collections::HashMap;

impl Solution
{
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        result.resize(2, -1);

        let n: usize=nums.len();

        let mut hashmap: HashMap<i32, i32>=HashMap::new();

        for index in 0..n
        {
            if hashmap.contains_key(&nums[index])
            {
                let i: &i32=hashmap.get(&nums[index]).unwrap();

                result[0]=*i;

                result[1]=index as i32
            }
            else
            {
                let difference: i32=target - nums[index];

                hashmap.insert(difference, index as i32);
            }
        }

        result
    }
}

impl Solution
{
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        result.resize(2, -1);

        let n: usize=nums.len();

        let mut hashmap: HashMap<i32, i32>=HashMap::new();

        for (index, number) in nums.iter().enumerate()
        {
            if hashmap.contains_key(number)
            {
                let i: &i32=hashmap.get(number).unwrap();

                result[0]=*i;

                result[1]=index as i32
            }
            else
            {
                let difference: i32=target - number;

                hashmap.insert(difference, index as i32);
            }
        }

        result
    }
}