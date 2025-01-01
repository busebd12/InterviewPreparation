impl Solution
{
    pub fn is_anagram(s: String, t: String) -> bool
    {
        let s_frequencies: Vec<usize>=Self::get_frequencies(&s);

        let t_frequencies: Vec<usize>=Self::get_frequencies(&t);

        s_frequencies==t_frequencies
    }

    pub fn get_frequencies(string: &String) -> Vec<usize>
    {
        let mut frequencies: Vec<usize>=vec![0; 26];

        for character in string.chars()
        {
            let ascii: usize=character as usize - 'a' as usize;

            frequencies[ascii]+=1;
        }

        frequencies
    }
}