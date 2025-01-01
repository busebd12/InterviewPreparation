use std::collections::{HashMap};

impl Solution
{
    pub fn min_window(s: String, t: String) -> String
    {
        let mut result: String=String::from("");

        let n: usize=s.len();

        let m: usize=t.len();

        if n < m
        {
            return result;
        }

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut t_frequencies: HashMap<char, usize>=HashMap::new();

        for character in t.chars()
        {
            t_frequencies.entry(character).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        let required: usize=t_frequencies.len();

        let mut unique_t_characters_found: usize=0;

        let mut hashmap: HashMap<char, usize>=HashMap::new();

        let mut substring_start: usize=usize::MAX;

        let mut min_length: usize=usize::MAX;

        let mut left: usize=0;

        let mut right: usize=0;

        while right < n
        {
            let character: char=characters[right];

            hashmap.entry(character).and_modify(|frequency| *frequency+=1).or_insert(1);

            if t_frequencies.contains_key(&character) && *t_frequencies.get(&character).unwrap()==*hashmap.get(&character).unwrap()
            {   
                unique_t_characters_found+=1;
            }

            while left <= right && unique_t_characters_found==required
            {
                let length: usize=(right - left) + 1;

                if length < min_length
                {
                    substring_start=left;

                    min_length=length;
                }

                let left_character: char=characters[left];

                hashmap.entry(left_character).and_modify(|frequency| *frequency-=1);

                if t_frequencies.contains_key(&left_character) && *hashmap.get(&left_character).unwrap() < *t_frequencies.get(&left_character).unwrap()
                {
                    unique_t_characters_found-=1;
                }

                left+=1;
            }

            right+=1;
        }

        if min_length!=usize::MAX && substring_start!=usize::MAX
        {
            let substring_end: usize=substring_start + min_length;
            
            result=s[substring_start..substring_end].to_string();
        }

        result
    }
}