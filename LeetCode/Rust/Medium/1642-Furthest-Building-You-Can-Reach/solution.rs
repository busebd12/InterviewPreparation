use std::collections::{BinaryHeap};
use std::cmp;

impl Solution
{
    pub fn furthest_building(heights: Vec<i32>, mut bricks: i32, mut ladders: i32) -> i32
    {
        let mut result: i32=0;

        let n: usize=heights.len();

        let mut jumps: BinaryHeap<cmp::Reverse<i32>>=BinaryHeap::new();

        for index in 1..n
        {
            let difference: i32=heights[index] - heights[index - 1];

            if difference > 0
            {
                bricks-=difference;

                jumps.push(cmp::Reverse(-difference));

                if bricks < 0
                {
                    if ladders==0
                    {
                        return (index - 1) as i32;
                    }
                    else
                    {
                        let jump: i32=jumps.pop().unwrap().0;

                        bricks-=jump;

                        ladders-=1;
                    }
                }
            }
        }

        (n - 1) as i32
    }
}