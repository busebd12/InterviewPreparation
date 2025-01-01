use std::collections::HashMap;

impl Solution
{
    pub fn find_special_integer(arr: Vec<i32>) -> i32
    {
        let mut result: i32=-1;

        let n: usize=arr.len();

        let mut frequencies: HashMap<i32, usize>=HashMap::new();

        for number in arr.iter()
        {
            if !frequencies.contains_key(number)
            {
                frequencies.insert(*number, 1);
            }
            else
            {
                frequencies.entry(*number).and_modify(|value| {*value+=1;});
            }
        }

        let max_frequency: f64=n as f64 * 0.25;

        for (number, frequency) in frequencies.iter()
        {
            if *frequency as f64 > max_frequency
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
    pub fn find_special_integer(arr: Vec<i32>) -> i32
    {
        let mut result: i32=-1;

        let n: usize=arr.len();

        let limit: usize=usize::pow(10, 5) + 1;

        let mut frequencies: Vec<usize>=vec![0; limit];

        for &number in arr.iter()
        {
            frequencies[number as usize]+=1;
        }

        let max_frequency: f64=n as f64 * 0.25;

        for number in 0..limit
        {
            if frequencies[number as usize] as f64 > max_frequency
            {
                result=number as i32;

                break;
            }
        }

        result
    }
}