use std::collections::{VecDeque};

impl Solution
{
    pub fn kth_palindrome(queries: Vec<i32>, int_length: i32) -> Vec<i64>
    {
        let mut result: Vec<i64>=Vec::new();

        let q: usize=queries.len();

        result=vec![-1; q];

        let half_of_palindrome_length: i32=(int_length + 1) / 2;

        let first_palindrome_half: i32=i32::pow(10, (half_of_palindrome_length - 1) as u32);

        let last_palindrome_half: i32=i32::pow(10, (half_of_palindrome_length) as u32) - 1;

        let number_of_palindromes: i32=(last_palindrome_half - first_palindrome_half) + 1;

        for index in 0..q
        {
            let query: i32=queries[index];

            if query <= number_of_palindromes
            {
                let mut first_half_of_palindrome: i32=first_palindrome_half + query - 1;

                let mut first_half_of_palindrome_digits: VecDeque<i32>=VecDeque::new();

                while first_half_of_palindrome > 0
                {
                    first_half_of_palindrome_digits.push_front(first_half_of_palindrome % 10);

                    first_half_of_palindrome/=10;
                }

                let mut middle: i32=-1;

                if (int_length % 2)==1
                {
                    middle=half_of_palindrome_length - 1;
                }
                else
                {
                    middle=half_of_palindrome_length;
                }

                let mut second_half_of_palindrome_digits: VecDeque<i32>=VecDeque::new();

                for iteration in 0..middle
                {
                    second_half_of_palindrome_digits.push_back(first_half_of_palindrome_digits[iteration as usize]);
                }

                let mut combined_palindrome_digits: VecDeque<i32>=VecDeque::new();

                while !first_half_of_palindrome_digits.is_empty()
                {
                    combined_palindrome_digits.push_back(first_half_of_palindrome_digits.pop_front().unwrap());
                }

                while !second_half_of_palindrome_digits.is_empty()
                {
                    combined_palindrome_digits.push_back(second_half_of_palindrome_digits.pop_back().unwrap());
                }

                let mut combined: i64=0;

                while let Some(digit)=combined_palindrome_digits.pop_front()
                {
                    combined=(combined * 10) + digit as i64
                }

                result[index]=combined;
            }
        }

        result
    }
}