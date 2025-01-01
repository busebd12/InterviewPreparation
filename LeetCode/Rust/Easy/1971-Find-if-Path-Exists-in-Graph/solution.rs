use std::collections::{VecDeque};

impl Solution
{
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool
    {
        let mut graph: Vec<Vec<i32>>=vec![vec![]; n as usize];

        for edge in &edges
        {
            let u: i32=edge[0];

            let v: i32=edge[1];

            graph[u as usize].push(v);

            graph[v as usize].push(u);
        }

        let mut visited: Vec<bool>=vec![false; n as usize];

        Solution::dfs(&graph, &mut visited, source, destination)
    }

    fn dfs(graph: &Vec<Vec<i32>>, visited: &mut Vec<bool>, source: i32, destination: i32) -> bool
    {
        if visited[source as usize]
        {
            return false;
        }

        if source==destination
        {
            return true;
        }

        visited[source as usize]=true;

        for neighbour in &graph[source as usize]
        {
            if Solution::dfs(graph, visited, *neighbour, destination)
            {
                return true;
            }
        }

        return false;
    }
}

impl Solution
{
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool
    {
        let mut graph: Vec<Vec<i32>>=vec![vec![]; n as usize];

        for edge in &edges
        {
            let u: i32=edge[0];

            let v: i32=edge[1];

            graph[u as usize].push(v);

            graph[v as usize].push(u);
        }

        Solution::dfs(&graph, n, source, destination)
    }

    fn dfs(graph: &Vec<Vec<i32>>, n: i32, source: i32, destination: i32) -> bool
    {
        let mut stack: Vec<i32>=Vec::new();

        let mut visited: Vec<bool>=vec![false; n as usize];

        visited[source as usize]=true;

        stack.push(source);

        while let Some(node)=stack.pop()
        {
            if node==destination
            {
                return true;
            }

            for neighbour in &graph[node as usize]
            {
                if visited[*neighbour as usize]==false
                {
                    visited[*neighbour as usize]=true;

                    stack.push(*neighbour);
                }
            }
        }

        return false;
    }
}

impl Solution
{
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool
    {
        let mut graph: Vec<Vec<i32>>=vec![vec![]; n as usize];

        for edge in &edges
        {
            let u: i32=edge[0];

            let v: i32=edge[1];

            graph[u as usize].push(v);

            graph[v as usize].push(u);
        }

        Solution::bfs(&graph, n, source, destination)
    }

    fn bfs(graph: &Vec<Vec<i32>>, n: i32, source: i32, destination: i32) -> bool
    {
        let mut queue: VecDeque<i32>=VecDeque::new();

        let mut visited: Vec<bool>=vec![false; n as usize];

        visited[source as usize]=true;

        queue.push_back(source);

        while let Some(node)=queue.pop_back()
        {
            if node==destination
            {
                return true;
            }

            for neighbour in &graph[node as usize]
            {
                if visited[*neighbour as usize]==false
                {
                    visited[*neighbour as usize]=true;

                    queue.push_back(*neighbour);
                }
            }
        }

        return false;
    }
}