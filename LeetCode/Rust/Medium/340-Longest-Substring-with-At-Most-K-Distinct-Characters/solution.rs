use std::collections::{HashMap};

impl Solution
{
    pub fn length_of_longest_substring_k_distinct(s: String, k: i32) -> i32
    {
        let mut result: i32=0;

        if k==0
        {
            return result;
        }

        let n: usize=s.len();

        let mut hashmap: HashMap<char, i32>=HashMap::new();

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut left: usize=0;

        let mut right: usize=0;

        while right < n
        {
            let right_character: char=characters[right];

            hashmap.entry(right_character).and_modify(|frequency| *frequency+=1).or_insert(1);

            while (hashmap.len() as i32) > k
            {
                let left_character: char=characters[left];

                hashmap.entry(left_character).and_modify(|frequency| *frequency-=1);

                if *hashmap.get(&left_character).unwrap()==0
                {
                    hashmap.remove(&left_character);
                }

                left+=1;
            }

            let length: usize=(right - left) + 1;

            result=std::cmp::max(result, length as i32);

            right+=1;
        }

        result
    }
}