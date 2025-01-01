use std::collections::HashMap;

impl Solution
{
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let mut hashmap: HashMap<i64, Vec<usize>>=HashMap::new();

        for (index, number) in nums.iter().enumerate()
        {
            hashmap.entry(*number as i64).or_insert(vec![]).push(index);
        }

        let mut memo: HashMap<(i64, usize), i32>=HashMap::new();

        for i in 0..n
        {
            for j in i + 1..n
            {
                let difference: i64=nums[j] as i64 - nums[i] as i64;

                let target: i64=nums[j] as i64 + difference;

                result+=Self::helper(&nums, &mut memo, &hashmap, n, difference, target, j);
            }
        }     

        result
    }

    fn helper(nums: &Vec<i32>, memo: &mut HashMap<(i64, usize), i32>, hashmap: &HashMap<i64, Vec<usize>>, n: usize, difference: i64, target: i64, index: usize) -> i32
    {
        if index==n
        {
            return 0;
        }

        if !hashmap.contains_key(&target)
        {
            return 0;
        }

        let key: (i64, usize)=(target, index);

        if memo.contains_key(&key)
        {
            return *memo.get(&key).unwrap();
        }

        let mut subproblem_solution: i32=0;

        for i in hashmap.get(&target).unwrap().iter()
        {
            if *i > index
            {
                let next_target: i64=nums[*i] as i64 + difference;
                
                subproblem_solution+=1 + Self::helper(nums, memo, hashmap, n, difference, next_target, *i);
            }
        }

        memo.insert(key, subproblem_solution);

        subproblem_solution
    }
}