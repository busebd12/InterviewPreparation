use std::collections::{BinaryHeap};
use std::cmp;

impl Solution
{
    pub fn min_meeting_rooms(mut intervals: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let n: usize=intervals.len();

        intervals.sort_by(|interval1, interval2| interval1[0].cmp(&interval2[0]));

        let mut min_heap: BinaryHeap<std::cmp::Reverse<i32>>=BinaryHeap::new();

        for interval in intervals.iter()
        {
            let interval_start: i32=interval[0];

            let interval_end: i32=interval[1];

            if min_heap.is_empty()
            {
                min_heap.push(std::cmp::Reverse(interval_end));

                result+=1;
            }
            else
            {
                let ending_time_of_meeting_ending_soonest: i32=(*min_heap.peek().unwrap()).0;

                if ending_time_of_meeting_ending_soonest <= interval_start
                {
                    min_heap.pop();
                }
                else
                {
                    result+=1;
                }

                min_heap.push(std::cmp::Reverse(interval_end));
            }
        }

        result
    }
}