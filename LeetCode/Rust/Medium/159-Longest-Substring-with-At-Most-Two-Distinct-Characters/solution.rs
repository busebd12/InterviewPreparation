use std::collections::HashMap;

impl Solution
{
    pub fn length_of_longest_substring_two_distinct(s: String) -> i32
    {
        let result: i32=0;

        let n: usize=s.len();

        let k: usize=2;

        let mut hashmap: HashMap<char, u32>=HashMap::new();

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut substring_start: i32=-1;

        let mut substring_end: i32=-1;

        let mut max_length: usize=0;

        let mut left: usize=0;

        for right in 0..n
        {
            let letter: char=characters[right];

            hashmap.entry(letter).and_modify(|frequency| *frequency+=1).or_insert(1);

            while left < right && hashmap.len() > k
            {
                if let Some(frequency)=hashmap.get_mut(&characters[left])
                {
                    *frequency-=1;

                    if *frequency==0
                    {
                        hashmap.remove(&characters[left]);
                    }
                }

                left+=1;
            }

            let substring_length: usize=(right - left) + 1;

            if substring_length > max_length
            {
                max_length=substring_length;

                substring_start=left as i32;

                substring_end=right as i32;
            }
        }

        //let substring: &str=&s[substring_start as usize..=substring_end as usize];

        //println!("substring: {}", substring);

        max_length as i32
    }
}

impl Solution
{
    pub fn length_of_longest_substring_two_distinct(s: String) -> i32
    {
        let n: usize=s.len();

        let k: usize=2;

        let mut hashmap: Vec<u32>=vec![0; 123];

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let mut substring_start: i32=-1;

        let mut substring_end: i32=-1;

        let mut max_length: usize=0;

        let mut left: usize=0;

        for right in 0..n
        {
            let letter: char=characters[right];

            let ascii: usize=letter as usize;

            hashmap[ascii]+=1;

            while left < right && Self::get_number_of_unique_letters(&hashmap) > k
            {
                let left_index: usize=characters[left] as usize;

                if hashmap[left_index] > 0
                {
                    hashmap[left_index]-=1;
                }

                left+=1;
            }

            let substring_length: usize=(right - left) + 1;

            if substring_length > max_length
            {
                max_length=substring_length;

                substring_start=left as i32;

                substring_end=right as i32;
            }
        }

        //let substring: &str=&s[substring_start as usize..=substring_end as usize];

        //println!("substring: {}", substring);

        max_length as i32
    }

    pub fn get_number_of_unique_letters(hashmap: &Vec<u32>) -> usize
    {
        let mut unique_letters: usize=0;

        for index in 0..123
        {
            if hashmap[index] > 0
            {
                unique_letters+=1;
            }
        }

        unique_letters
    }
}