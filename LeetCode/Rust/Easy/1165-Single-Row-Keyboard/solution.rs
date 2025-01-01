impl Solution
{
    pub fn calculate_time(keyboard: String, word: String) -> i32
    {
        let mut result: i32=0;

        let mut hashmap: Vec<usize>=vec![0; 26];

        let offset: usize='a' as usize;

        for (index, character) in keyboard.chars().enumerate()
        {
            let ascii_index: usize=character as usize - offset;

            hashmap[ascii_index]=index;
        }

        let mut previous_key_index: usize=0;

        for character in word.chars()
        {
            let ascii: usize=character as usize - offset;

            let key_index: usize=hashmap[ascii];

            let difference: i32=(key_index as i32 - previous_key_index as i32).abs();

            result+=difference;

            previous_key_index=key_index;
        }

        result
    }
}