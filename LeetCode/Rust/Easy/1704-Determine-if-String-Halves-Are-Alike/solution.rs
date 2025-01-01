use std::collections::{BTreeSet};

impl Solution
{
    pub fn halves_are_alike(s: String) -> bool
    {
        let n: usize=s.len();

        let half: usize=n / 2;

        let vowels: Vec<char>=vec!['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];

        let mut vowels_set: BTreeSet<char>=vowels.into_iter().collect::<BTreeSet<char>>();

        let mut first_half_vowels: usize=0;

        let mut second_half_vowels: usize=0;

        for (index, character) in s.chars().enumerate()
        {
            if vowels_set.contains(&character)
            {
                if index < half
                {
                    first_half_vowels+=1;
                }
                else
                {
                    second_half_vowels+=1;
                }
            }
        }

        first_half_vowels==second_half_vowels
    }
}