use std::cmp;
use std::collections::{BinaryHeap};

impl Solution
{
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let mut min_heap: BinaryHeap<std::cmp::Reverse<(i32)>>=BinaryHeap::new();

        for number in nums.iter()
        {
            let square: i32=number * number;

            min_heap.push(std::cmp::Reverse(square));
        }

        while let Some(std::cmp::Reverse(square))=min_heap.pop()
        {
            result.push(square);
        }

        result
    }
}

impl Solution
{
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        for number in nums.iter()
        {
            let square: i32=number * number;

            result.push(square);
        }

        result.sort();

        result
    }
}

impl Solution
{
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let limit: usize=usize::pow(10, 4) + 1;

        let mut buckets: Vec<i32>=vec![0; limit];

        for number in nums.iter()
        {
            let mut index: i32=*number;

            if index < 0
            {
                index*=-1;
            }
            
            buckets[index as usize]+=1;
        }

        for number in 0..limit
        {
            let frequency: i32=buckets[number];
            
            if frequency > 0
            {
                let square: i32=(number * number) as i32;
                
                for iteration in 0..frequency
                {
                    result.push(square);
                }
            }
        }

        result
    }
}