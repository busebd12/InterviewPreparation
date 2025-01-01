use std::cmp;

impl Solution
{
    pub fn min_cost(mut costs: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let n: usize=costs.len();

        for row in 1..n
        {
            costs[row][0]+=cmp::min(costs[row - 1][1], costs[row - 1][2]);

            costs[row][1]+=cmp::min(costs[row - 1][0], costs[row - 1][2]);

            costs[row][2]+=cmp::min(costs[row - 1][0], costs[row - 1][1]);
        }

        result=*costs[n - 1].iter().min().unwrap();

        result
    }
}