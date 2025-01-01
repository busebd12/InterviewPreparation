use std::collections::{HashMap};
use std::cmp;

impl Solution
{
    pub fn find_max_length(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let mut prefix_sums: Vec<i32>=vec![0; n];

        if nums[0]==0
        {
            prefix_sums[0]-=1;
        }
        else
        {
            prefix_sums[0]+=1;
        }

        for index in 1..n
        {
            if nums[index]==1
            {
                prefix_sums[index]=prefix_sums[index - 1] + 1;
            }
            else
            {
                prefix_sums[index]=prefix_sums[index - 1] - 1;
            }
        }

        let mut hashmap: HashMap<i32, i32>=HashMap::new();

        for index in 0..n
        {
            if !hashmap.contains_key(&prefix_sums[index])
            {
                if prefix_sums[index]==0
                {
                    let length: i32=(index + 1) as i32;

                    result=std::cmp::max(result, length);
                }
                else
                {
                    hashmap.insert(prefix_sums[index], index as i32);
                }
            }
            else
            {
                let previous_index: i32=*hashmap.get(&prefix_sums[index]).unwrap();

                let length: i32=index as i32 - previous_index;

                result=std::cmp::max(result, length);
            }
        }

        result
    }
}