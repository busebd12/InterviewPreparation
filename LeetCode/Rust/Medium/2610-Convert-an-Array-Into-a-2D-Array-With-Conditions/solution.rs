impl Solution
{
    pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();
        
        let MAX_VALUE: usize=200;

        let mut buckets: Vec<usize>=vec![0; MAX_VALUE + 1];

        let mut max_frequency: usize=0;

        for number in nums.iter()
        {
            buckets[*number as usize]+=1;

            max_frequency=usize::max(max_frequency, buckets[*number as usize]);
        }

        result=vec![vec![]; max_frequency];

        let mut ordered_frequencies: Vec<Vec<usize>>=vec![vec![]; max_frequency + 1];

        for number in 0..201
        {
            let index: usize=number as usize;
            
            let frequency: usize=buckets[index];

            if frequency > 0
            {
                ordered_frequencies[frequency].push(number);
            }
        }

        for frequency in (0..max_frequency + 1).rev()
        {
            let index: usize=frequency as usize;
            
            if !ordered_frequencies[index].is_empty()
            {
                for number in ordered_frequencies[index].iter()
                {
                    for iteration in 0..frequency
                    {
                        result[iteration as usize].push(*number as i32);
                    }
                }
            }
        }

        result
    }
}