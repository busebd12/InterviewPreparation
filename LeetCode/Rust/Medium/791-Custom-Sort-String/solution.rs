use std::collections::{HashMap, HashSet};

impl Solution
{
    pub fn custom_sort_string(order: String, s: String) -> String
    {
        let mut result: String=String::from("");

        let mut hashmap: HashMap<char, i32>=HashMap::new();

        for character in s.chars()
        {
            hashmap.entry(character).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        let mut used: HashSet<char>=HashSet::new();

        for character in order.chars()
        {
            if hashmap.contains_key(&character)
            {
                let frequency: i32=*hashmap.get(&character).unwrap();

                for iteration in 0..frequency
                {
                    result.push(character);
                }

                used.insert(character);
            }
        }

        for character in s.chars()
        {
            if !used.contains(&character)
            {
                result.push(character);
            }
        }

        result
    }
}

impl Solution
{
    pub fn custom_sort_string(order: String, s: String) -> String
    {
        let mut result: String=String::from("");

        let mut hashmap: Vec<i32>=vec![0; 26];

        for character in s.chars()
        {
            let ascii: usize=character as usize - 'a' as usize;

            hashmap[ascii]+=1;
        }

        let mut used: Vec<bool>=vec![false; 26];

        for character in order.chars()
        {
            let ascii: usize=character as usize - 'a' as usize;

            let frequency: i32=hashmap[ascii];

            if frequency > 0
            {
                for iteration in 0..frequency
                {
                    result.push(character);
                }

                used[ascii]=true;
            }
        }

        for character in s.chars()
        {
            let ascii: usize=character as usize - 'a' as usize;

            if used[ascii]==false
            {
                result.push(character);
            }
        }

        result
    }
}