use std::collections::{HashMap, VecDeque};

impl Solution
{
    pub fn num_buses_to_destination(routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32
    {
        let mut result: i32=0;

        if source==target
        {
            return result;
        }

        let n: usize=routes.len();

        let mut graph: HashMap<i32, Vec<i32>>=HashMap::new();

        for route in 0..n
        {
            for stop in &routes[route]
            {
                if !graph.contains_key(stop)
                {
                    graph.insert(*stop, Vec::new());
                }

                graph.entry(*stop).and_modify(|value| value.push(route as i32));
            }
        }

        if !graph.contains_key(&source) || !graph.contains_key(&target)
        {
            return -1;
        }

        let mut visited: Vec<bool>=vec![false; n];

        let mut queue: VecDeque<i32>=VecDeque::new();

        queue.push_back(source);

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                let current_stop: i32=queue.pop_front().unwrap();

                if current_stop==target
                {
                    return result;
                }

                for route in &(*graph.get(&current_stop).unwrap())
                {
                    if visited[*route as usize]
                    {
                        continue;
                    }

                    visited[*route as usize]=true;

                    for next_stop in &routes[*route as usize]
                    {
                        queue.push_back(*next_stop);
                    }
                }
            }

            if !queue.is_empty()
            {
                result+=1;
            }
        }

        -1
    }
}