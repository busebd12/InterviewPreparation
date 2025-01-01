use std::collections::{BTreeSet, HashMap};

impl Solution
{
    pub fn close_strings(word1: String, word2: String) -> bool
    {
        let w1: usize=word1.len();

        let w2: usize=word2.len();

        if w1!=w2
        {
            return false;
        }
        
        let word1_frequency_map: HashMap<char, usize>=Self::build_frequency_map(&word1);

        let word2_frequency_map:HashMap<char, usize>=Self::build_frequency_map(&word2);

        for character in word1_frequency_map.keys()
        {
            if !word2_frequency_map.contains_key(&character)
            {
                return false;
            }
        }

        let word1_frequencies: Vec<usize>=Self::build_frequency_set(&word1_frequency_map);

        let word2_frequencies: Vec<usize>=Self::build_frequency_set(&word2_frequency_map);

        word1_frequencies==word2_frequencies
    }

    fn build_frequency_map(word: &String) -> HashMap<char, usize>
    {
        let mut frequency_map: HashMap<char, usize>=HashMap::new();
        
        for character in word.chars()
        {
            frequency_map.entry(character).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        frequency_map
    }

    fn build_frequency_set(frequency_map: &HashMap<char, usize>) -> Vec<usize>
    {
        let mut frequency_set: Vec<usize>=Vec::new();

        for frequency in frequency_map.values()
        {
            frequency_set.push(*frequency);
        }

        frequency_set.sort();

        frequency_set
    }
}

impl Solution
{
    pub fn close_strings(word1: String, word2: String) -> bool
    {
        let w1: usize=word1.len();

        let w2: usize=word2.len();

        if w1!=w2
        {
            return false;
        }

        let max_ascii_value: usize=128;

        let mut max_frequency: usize=0;
        
        let word1_frequency_map: Vec<usize>=Self::build_frequency_map(&word1, &mut max_frequency, max_ascii_value);

        let word2_frequency_map: Vec<usize>=Self::build_frequency_map(&word2, &mut max_frequency, max_ascii_value);

        for ascii in 0..max_ascii_value + 1
        {
            if word1_frequency_map[ascii] > 0
            {
                if word2_frequency_map[ascii]==0
                {
                    return false;
                }
            }
        }

        let word1_frequencies: Vec<usize>=Self::build_frequency_set(&word1_frequency_map, max_ascii_value, max_frequency);

        let word2_frequencies: Vec<usize>=Self::build_frequency_set(&word2_frequency_map, max_ascii_value, max_frequency);

        word1_frequencies==word2_frequencies
    }

    fn build_frequency_map(word: &String, max_frequency: &mut usize, max_ascii_value: usize) -> Vec<usize>
    {
        let mut frequency_map: Vec<usize>=vec![0; max_ascii_value + 1];
        
        for character in word.chars()
        {
            let ascii: usize=character as usize;

            frequency_map[ascii]+=1;

            *max_frequency=usize::max(*max_frequency, frequency_map[ascii])
        }

        frequency_map
    }

    fn build_frequency_set(frequency_map: &Vec<usize>, max_ascii_value: usize, max_frequency: usize) -> Vec<usize>
    {
        let mut frequency_set: Vec<usize>=Vec::new();

        let mut frequency_buckets: Vec<usize>=vec![0; max_frequency + 1];

        for ascii in 0..max_ascii_value
        {
            let frequency: usize=frequency_map[ascii];

            frequency_buckets[frequency]+=1;
        }

        for frequency in 0..max_frequency + 1
        {
            if frequency_buckets[frequency] > 0
            {
                for count in 0..frequency_buckets[frequency]
                {
                    frequency_set.push(frequency);
                }
            }
        }

        frequency_set
    }
}