use std::collections::{BinaryHeap};
use std::cmp;

impl Solution
{
    pub fn connect_sticks(sticks: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let mut min_heap: BinaryHeap<cmp::Reverse<i32>>=BinaryHeap::new();

        for &stick in sticks.iter()
        {
            min_heap.push(cmp::Reverse(stick));
        }

        while min_heap.len() > 1
        {
            let x: i32=min_heap.pop().unwrap().0;

            let y: i32=min_heap.pop().unwrap().0;

            let total: i32=x + y;

            result+=total;

            min_heap.push(cmp::Reverse(total));
        }

        result
    }
}