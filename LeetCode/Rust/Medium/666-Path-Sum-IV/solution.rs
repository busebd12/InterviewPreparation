use std::collections::{HashMap, VecDeque};

impl Solution
{
    pub fn path_sum(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let mut hashmap: HashMap<(i32, i32), i32>=HashMap::new();

        for number in nums.iter()
        {
            let (depth, position, value): (i32, i32, i32)=Self::get_triplet(*number);

            hashmap.insert((depth, position), value);
        }

        let (root_depth, root_position, root_value): (i32, i32, i32)=Self::get_triplet(nums[0]);

        let mut queue: VecDeque<(i32, i32, i32)>=VecDeque::new();

        queue.push_back((root_depth, root_position, root_value));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                let (node_depth, node_position, node_value): (i32, i32, i32)=queue.pop_front().unwrap();

                let child_depth: i32=node_depth + 1;

                let left_child_position: i32=(node_position * 2) - 1;

                let right_child_position: i32=node_position * 2;

                let left_child_key: (i32, i32)=(child_depth, left_child_position);

                let right_child_key: (i32, i32)=(child_depth, right_child_position);

                if !hashmap.contains_key(&left_child_key) && !hashmap.contains_key(&right_child_key)
                {
                    result+=node_value;

                    continue;
                }

                if hashmap.contains_key(&left_child_key)
                {
                    queue.push_back((child_depth, left_child_position, node_value + *hashmap.get(&left_child_key).unwrap()));
                }

                if hashmap.contains_key(&right_child_key)
                {
                    queue.push_back((child_depth, right_child_position, node_value + *hashmap.get(&right_child_key).unwrap()));
                }
            }
        }

        result
    }

    fn get_triplet(mut number: i32) -> (i32, i32, i32)
    {
        let mut depth: i32=-1;

        let mut position: i32=-1;

        let mut value: i32=-1;

        let mut count: i32=0;

        while number > 0 && count < 3
        {
            let digit: i32=number % 10;

            if count==0
            {
                value=digit;
            }
            else if count==1
            {
                position=digit;
            }
            else if count==2
            {
                depth=digit;
            }

            number/=10;

            count+=1;
        }

        (depth, position, value)
    }
}