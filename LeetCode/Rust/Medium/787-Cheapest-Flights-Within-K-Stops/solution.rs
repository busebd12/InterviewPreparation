use std::collections::{HashMap, VecDeque};

impl Solution
{
    pub fn find_cheapest_price(n: i32, flights: Vec<Vec<i32>>, src: i32, dst: i32, k: i32) -> i32
    {
        let mut result: i32=-1;

        let mut graph: HashMap<i32, Vec<(i32, i32)>>=HashMap::new();

        for flight in flights.iter()
        {
            let source: i32=flight[0];

            let destination: i32=flight[1];

            let cost: i32=flight[2];

            graph.entry(source).or_insert(Vec::new()).push((destination, cost));
        }

        let mut costs: Vec<i32>=vec![i32::MAX; n as usize];

        costs[src as usize]=0;

        let mut k: i32=k + 1;

        let mut queue: VecDeque<(i32, i32)>=VecDeque::new();

        queue.push_back((src, 0));

        while !queue.is_empty() && k > 0
        {
            for iteration in 0..queue.len()
            {
                if let Some((city, cost))=queue.pop_front()
                {
                    if let Some(neighbours)=graph.get(&city)
                    {
                        for neighbour in neighbours.iter()
                        {
                            let next_city: i32=neighbour.0;

                            let next_city_cost: i32=neighbour.1;

                            let next_cost: i32=cost + next_city_cost;

                            if costs[next_city as usize] > next_cost
                            {
                                costs[next_city as usize]=next_cost;

                                queue.push_back((next_city, next_cost));
                            }
                        }
                    }
                }
            }

            k-=1;
        }

        if costs[dst as usize]!=i32::MAX
        {
            result=costs[dst as usize];
        }

        result
    }
}