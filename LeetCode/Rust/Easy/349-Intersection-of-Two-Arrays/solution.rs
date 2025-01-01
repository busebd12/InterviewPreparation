use std::collections::{HashSet};

impl Solution
{
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let nums2_hashset: HashSet<i32>=nums2.iter().copied().collect::<HashSet<i32>>();

        let mut intersection: HashSet<i32>=HashSet::new();

        for number in nums1.iter()
        {
            if nums2_hashset.contains(number) && !intersection.contains(number)
            {
                intersection.insert(*number);

                result.push(*number);
            }
        }

        result
    }
}