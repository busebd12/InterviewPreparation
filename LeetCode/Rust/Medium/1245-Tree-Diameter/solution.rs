use std::collections::{HashSet, VecDeque};

impl Solution
{
    pub fn tree_diameter(edges: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let n: usize=edges.len();

        let mut graph: Vec<Vec<i32>>=vec![vec![]; n + 1];

        for edge in edges.iter()
        {
            let a: i32=edge[0];

            let b: i32=edge[1];

            graph[a as usize].push(b);

            graph[b as usize].push(a);
        }

        let start: i32=0;

        let (path_length, first_farthest_node): (i32, i32)=Self::bfs(&graph, n, start);

        let (path_length, second_farthest_node): (i32, i32)=Self::bfs(&graph, n, first_farthest_node);

        path_length
    }

    fn bfs(graph: &Vec<Vec<i32>>, start: i32) -> (i32, i32)
    {
        let mut queue: VecDeque<i32>=VecDeque::new();

        let mut visited: HashSet<i32>=HashSet::new();

        visited.insert(start);

        queue.push_back(start);

        let mut furthest_node_from_start: i32=0;

        let mut level: i32=0;

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some(node)=queue.pop_front()
                {
                    furthest_node_from_start=node;

                    for neighbour in graph[node as usize].iter()
                    {
                        if !visited.contains(&neighbour)
                        {
                            visited.insert(*neighbour);

                            queue.push_back(*neighbour);
                        }
                    }
                }
            }
            
            if !queue.is_empty()
            {
                level+=1;
            }
        }

        (level, furthest_node_from_start)
    }

    fn bfs(graph: &Vec<Vec<i32>>, n: usize, start: i32) -> (i32, i32)
    {
        let mut queue: VecDeque<i32>=VecDeque::new();

        let mut visited: Vec<bool>=vec![false; n + 1];

        visited[start as usize]=true;

        queue.push_back(start);

        let mut furthest_node_from_start: i32=0;

        let mut level: i32=0;

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some(node)=queue.pop_front()
                {
                    furthest_node_from_start=node;

                    for neighbour in graph[node as usize].iter()
                    {
                        if !visited[*neighbour as usize]
                        {
                            visited[*neighbour as usize]=true;

                            queue.push_back(*neighbour);
                        }
                    }
                }
            }
            
            if !queue.is_empty()
            {
                level+=1;
            }
        }

        (level, furthest_node_from_start)
    }
}