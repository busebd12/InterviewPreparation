use std::collections::{HashMap};

impl Solution
{
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>>
    {
        let mut result: Vec<Vec<String>>=Vec::new();

        let mut hashmap: HashMap<String, Vec<String>>=HashMap::new();

        for string in strs.iter()
        {
            let mut letters: Vec<char>=string.chars().collect::<Vec<char>>();

            letters.sort();

            let sorted_string: String=letters.into_iter().collect::<String>();

            hashmap.entry(sorted_string).and_modify(|values| values.push(string.to_string())).or_insert(vec![string.to_string()]);
        }

        for (key, values) in hashmap.iter()
        {
            result.push(values.to_vec());
        }

        result
    }
}

impl Solution
{
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>>
    {
        let mut result: Vec<Vec<String>>=Vec::new();

        let mut hashmap: HashMap<String, Vec<String>>=HashMap::new();

        for string in strs.iter()
        {
            let mut letters: Vec<char>=string.chars().collect::<Vec<char>>();

            letters.sort();

            let sorted_string: String=letters.into_iter().collect::<String>();

            hashmap.entry(sorted_string).or_insert(vec![]).push(string.to_string());
        }

        for (key, values) in hashmap.iter()
        {
            result.push(values.to_vec());
        }

        result
    }
}