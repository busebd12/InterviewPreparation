use std::collections::HashMap;

impl Solution
{
    pub fn make_equal(words: Vec<String>) -> bool
    {
        let w: usize=words.len();

        let mut hashmap: HashMap<char, usize>=HashMap::new();

        for word in words.iter()
        {
            for character in word.chars()
            {
                hashmap.entry(character).and_modify(|frequency| *frequency+=1).or_insert(1);
            }
        }

        for frequency in hashmap.values()
        {
            if frequency % w != 0
            {
                return false;
            }
        }

        true
    }
}

impl Solution
{
    pub fn make_equal(words: Vec<String>) -> bool
    {
        let w: usize=words.len();

        let mut hashmap: Vec<u32>=vec![0; 26];

        for word in words.iter()
        {
            for character in word.chars()
            {
                let offset: usize='a' as usize;

                let ascii: usize=character as usize - offset;

                hashmap[ascii]+=1;
            }
        }

        for ascii in 0..26
        {
            if hashmap[ascii]!=0
            {
                if hashmap[ascii] as usize % w != 0
                {
                    return false;
                }
            }
        }

        true
    }
}