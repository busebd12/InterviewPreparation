use std::collections::{HashMap};

impl Solution
{
    pub fn majority_element(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let mut hashmap: HashMap<i32, usize>=HashMap::new();

        for number in nums.iter()
        {
            hashmap.entry(*number).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        let target_frequency: usize=n / 2;

        for (number, frequency) in hashmap.iter()
        {
            if *frequency > target_frequency
            {
                result=*number;

                break;
            }
        }

        result
    }
}

impl Solution
{
    pub fn majority_element(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let mut hashmap: HashMap<i32, usize>=HashMap::new();

        nums.iter().for_each(|&number| {hashmap.entry(number).and_modify(|frequency| *frequency+=1).or_insert(1);});

        let target_frequency: usize=n / 2;

        for (number, frequency) in hashmap.iter()
        {
            if *frequency > target_frequency
            {
                result=*number;

                break;
            }
        }

        result
    }
}

impl Solution
{
    pub fn majority_element(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let majority: usize=(n / 2) + 1;

        let mut set_bits_per_position: Vec<usize>=vec![0; 32];

        let sign: i32=1;

        for bit_position in 0..32
        {
            let mut set_bits: usize=0;

            for number in nums.iter()
            {
                let bit: usize=((number >> bit_position) & 1) as usize;

                if bit==1
                {
                    set_bits+=1;
                }
            }

            set_bits_per_position[bit_position]+=set_bits;
        }

        for bit_position in 0..32
        {
            if set_bits_per_position[bit_position] >= majority
            {
                result=result | (1 << bit_position);
            }
        }

        result
    }
}