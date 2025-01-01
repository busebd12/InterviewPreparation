use std::collections::{VecDeque};

impl Solution
{
    pub fn deck_revealed_increasing(mut deck: Vec<i32>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        /*deck.sort();

        deck.reverse();*/

        deck.sort_by(|a, b| b.cmp(a));

        let mut queue: VecDeque<i32>=deck.clone().into_iter().collect::<VecDeque<i32>>();

        let mut ordering: VecDeque<i32>=VecDeque::new();

        while let Some(current)=queue.pop_front()
        {
            match (ordering.is_empty())
            {
                true =>
                {
                    ordering.push_back(current);
                },
                false =>
                {
                    let last: i32=ordering.pop_back().unwrap();

                    ordering.push_front(last);

                    ordering.push_front(current);
                }
            }
        }

        while let Some(number)=ordering.pop_front()
        {
            result.push(number);
        }

        result
    }
}