use std::collections::{VecDeque};

impl Solution
{
    pub fn rearrange_array(nums: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let mut negatives: VecDeque<i32>=VecDeque::new();

        let mut positives: VecDeque<i32>=VecDeque::new();

        for number in nums.iter()
        {
            match number
            {
                number if *number > 0 =>
                {
                    positives.push_back(*number);
                },
                number if *number < 0 =>
                {
                    negatives.push_back(*number);
                },
                _ => ()
            }
        }

        while let (Some(positive), Some(negative))=(positives.pop_front(), negatives.pop_front())
        {
            result.push(positive);

            result.push(negative);
        }

        result
    }
}