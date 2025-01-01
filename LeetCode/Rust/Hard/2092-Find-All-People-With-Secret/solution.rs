use std::collections::{BinaryHeap};
use std::cmp;

impl Solution
{
    pub fn find_all_people(n: i32, meetings: Vec<Vec<i32>>, first_person: i32) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let mut graph: Vec<Vec<(i32, i32)>>=vec![vec![]; n as usize];

        for meeting in meetings.iter()
        {
            let x: i32=meeting[0];

            let y: i32=meeting[1];

            let time: i32=meeting[2];

            graph[x as usize].push((y, time));

            graph[y as usize].push((x, time));
        }

        let mut knows_secret: Vec<bool>=vec![false; n as usize];

        let mut min_heap: BinaryHeap<std::cmp::Reverse<(i32, i32)>>=BinaryHeap::new();

        min_heap.push(std::cmp::Reverse((0, 0)));

        min_heap.push(std::cmp::Reverse((0, first_person)));

        while let Some(std::cmp::Reverse((time, person)))=min_heap.pop()
        {   
            if knows_secret[person as usize]==true
            {
                continue;
            }

            result.push(person);

            knows_secret[person as usize]=true;

            if graph[person as usize].is_empty()
            {
                continue;
            }

            for element in graph[person as usize].iter()
            {
                let next_person: i32=element.0;

                let meeting_time: i32=element.1;

                if knows_secret[next_person as usize]==true || meeting_time < time
                {
                    continue;
                }
                
                min_heap.push(std::cmp::Reverse((meeting_time, next_person)));
            }
        }

        result
    }
}