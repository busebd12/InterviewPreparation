use std::collections::HashMap;

impl Solution
{
    pub fn max_length_between_equal_characters(s: String) -> i32
    {
        let mut result: i32=-1;

        let mut hashmap: HashMap<char, usize>=HashMap::new();

        for (index, character) in s.chars().enumerate()
        {
            if !hashmap.contains_key(&character)
            {
                hashmap.insert(character, index);
            }
            else
            {
                let previous_index: usize=*hashmap.get(&character).unwrap();

                let substring_length: i32=((index - previous_index + 1) as i32) - 2;

                result=i32::max(result, substring_length);
            }
        }

        result
    }
}

impl Solution
{
    pub fn max_length_between_equal_characters(s: String) -> i32
    {
        let mut result: i32=-1;

        let mut hashmap: Vec<(usize, usize)>=vec![(usize::MAX, usize::MAX); 26];

        let offset: usize='a' as usize;

        for (index, character) in s.as_bytes().iter().enumerate()
        {
            let ascii: usize=*character as usize - offset;

            if hashmap[ascii].0==usize::MAX
            {
                hashmap[ascii].0=index;
            }
            else
            {
                hashmap[ascii].1=index;
            }
        }

        for ascii in 0..26
        {
            if hashmap[ascii].0!=usize::MAX && hashmap[ascii].1!=usize::MAX
            {
                let substring_start: usize=hashmap[ascii].0;

                let substring_end: usize=hashmap[ascii].1;
                
                let substring_length: i32=(substring_end - substring_start + 1) as i32 - 2;

                result=i32::max(result, substring_length);
            }
        }

        result
    }
}