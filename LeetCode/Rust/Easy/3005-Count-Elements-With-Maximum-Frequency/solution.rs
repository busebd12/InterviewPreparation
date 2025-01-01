use std::collections::{HashMap};
use std::cmp;

impl Solution
{
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let mut frequencies: HashMap<i32, i32>=HashMap::new();

        for number in nums.iter()
        {
            frequencies.entry(*number).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        let mut max_frequency: i32=0;

        for (number, frequency) in frequencies.iter()
        {
            max_frequency=std::cmp::max(max_frequency, *frequency);
        }

        for (number, frequency) in frequencies.iter()
        {
            if *frequency==max_frequency
            {
                result+=*frequency;
            }
        }

        result
    }
}

impl Solution
{
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let max_value: i32=101;

        let mut frequencies: Vec<i32>=vec![0; max_value as usize];

        for number in nums.iter()
        {
            frequencies[*number as usize]+=1;
        }

        let mut max_frequency: i32=0;

        for number in 0..max_value
        {
            max_frequency=std::cmp::max(max_frequency, frequencies[number as usize]);
        }

        for number in 0..max_value
        {
            if frequencies[number as usize]==max_frequency
            {
                result+=frequencies[number as usize];
            }
        }

        result
    }
}