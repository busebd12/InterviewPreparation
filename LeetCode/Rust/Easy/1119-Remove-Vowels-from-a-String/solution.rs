use std::collections::{HashSet};

impl Solution
{
    pub fn remove_vowels(s: String) -> String
    {
        let mut result: String=String::from("");

        let mut lowercase_vowels: HashSet<char>=HashSet::from(['a', 'e', 'i', 'o', 'u']);

        for character in s.chars()
        {
            if !lowercase_vowels.contains(&character)
            {
                result.push(character);
            }
        }

        result
    }
}

impl Solution
{
    pub fn remove_vowels(s: String) -> String
    {
        let mut result: String=String::from("");

        let mut lowercase_vowels: String=String::from("aeiou");

        for character in s.chars()
        {
            if !lowercase_vowels.contains(character)
            {
                result.push(character);
            }
        }

        result
    }
}