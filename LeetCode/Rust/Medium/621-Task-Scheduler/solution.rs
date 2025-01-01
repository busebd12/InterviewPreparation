use std::collections::{BinaryHeap, HashMap, VecDeque};

impl Solution
{
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32
    {
        let mut result: i32=0;

        let mut frequencies: HashMap<char, i32>=HashMap::new();

        for task in tasks.iter()
        {
            frequencies.entry(*task).and_modify(|frequency| *frequency+=1).or_insert(1);
        }

        let mut max_heap: BinaryHeap<(i32, char)>=BinaryHeap::new();

        for (task, frequency) in frequencies.iter()
        {
            max_heap.push((*frequency, *task));
        }

        while !max_heap.is_empty()
        {
            let mut gap_between_two_of_the_same_task: i32=n + 1;

            let mut queue: VecDeque<(i32, char)>=VecDeque::new();

            while !max_heap.is_empty() && gap_between_two_of_the_same_task > 0
            {
                let (mut frequency, task): (i32, char)=max_heap.pop().unwrap();

                result+=1;

                frequency-=1;

                if frequency > 0
                {
                    queue.push_back((frequency, task));
                }

                gap_between_two_of_the_same_task-=1;
            }

            if !queue.is_empty()
            {
                for (frequency, task) in queue.iter()
                {
                    max_heap.push((*frequency, *task));
                }
            }

            if max_heap.is_empty()
            {
                break;
            }
            else
            {
                result+=gap_between_two_of_the_same_task;
            }
        }

        result
    }
}