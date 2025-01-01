use std::collections::HashMap;

impl Solution
{
    pub fn min_operations(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let max_value: usize=usize::pow(10, 6);

        let mut frequencies: Vec<usize>=vec![0; max_value + 1];

        for number in nums.iter()
        {
            frequencies[*number as usize]+=1;
        }

        let mut min_frequency: usize=usize::MAX;

        for number in 1..max_value + 1
        {
            if frequencies[number]==1
            {
                return -1;
            }
        }

        for number in 1..max_value + 1
        {
            let frequency: i32=frequencies[number] as i32;
            
            if frequency > 0
            {
                let times: i32=frequency / 3;

                let left_over: i32=frequency % 3;

                if left_over==0
                {
                    result+=times;
                }
                else if left_over==1
                {
                    result+=(times - 1);

                    result+=2;
                }
                else if left_over==2
                {
                    result+=times;

                    result+=1;
                }
            }
        }

        result
    }
}

impl Solution
{
    pub fn min_operations(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let max_value: usize=usize::pow(10, 6);

        let mut hashmap: HashMap<i32, usize>=HashMap::new();

        for number in nums.iter()
        {
            hashmap.entry(*number).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        let mut min_frequency: usize=usize::MAX;

        for value in hashmap.values()
        {
            let frequency: i32=*value as i32;
            
            if frequency==1
            {
                return -1;
            }
        }

        for value in hashmap.values()
        {
            let mut frequency: i32=*value as i32;
            
            if frequency > 0
            {
                let times: i32=frequency / 3;

                let left_over: i32=frequency % 3;

                if left_over==0
                {
                    result+=times;
                }
                else if left_over==1
                {
                    result+=(times - 1);

                    result+=2;
                }
                else if left_over==2
                {
                    result+=times;

                    result+=1;
                }
            }
        }

        result
    }
}