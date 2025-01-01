use std::collections::HashMap;

impl Solution
{
    pub fn assign_bikes(workers: Vec<Vec<i32>>, bikes: Vec<Vec<i32>>) -> i32
    {
        let mut memo: HashMap<usize, i32>=HashMap::new();

        let w: usize=workers.len();

        let b: usize=bikes.len();

        let mut worker_index: usize=0;

        let mask: usize=0;

        Self::dfs(&workers, &bikes, &mut memo, w, b, mask, worker_index)
    }

    fn dfs(workers: &Vec<Vec<i32>>, bikes: &Vec<Vec<i32>>, memo: &mut HashMap<usize, i32>, w: usize, b: usize, mask: usize, worker_index: usize) -> i32
    {
        if worker_index==w
        {
            return 0;
        }

        if memo.contains_key(&mask)
        {
            return *memo.get(&mask).unwrap();
        }

        let mut subproblem_solution: i32=i32::MAX;

        for bike_index in 0..b
        {
            let bike_assigned: usize=mask & (1 << bike_index);
            
            if bike_assigned==0
            {
                let manhattan_distance: i32=Self::get_manhattan_distance(workers[worker_index][0], workers[worker_index][1], bikes[bike_index][0], bikes[bike_index][1]);

                let next_mask: usize=mask | (1 << bike_index);

                let next_call: i32=manhattan_distance + Self::dfs(workers, bikes, memo, w, b, next_mask, worker_index + 1);

                subproblem_solution=i32::min(subproblem_solution, next_call);
            }
        }

        memo.insert(mask, subproblem_solution);

        subproblem_solution
    }

    fn get_manhattan_distance(x1: i32, y1: i32, x2: i32, y2: i32) -> i32
    {
        let mut x_difference=x1 - x2;

        let mut y_difference=y1 - y2;

        x_difference.abs() + y_difference.abs()
    }
}

impl Solution
{
    pub fn assign_bikes(workers: Vec<Vec<i32>>, bikes: Vec<Vec<i32>>) -> i32
    {
        let w: usize=workers.len();

        let b: usize=bikes.len();

        let mut memo: Vec<i32>=vec![i32::MAX; 1 << 10];

        let mut worker_index: usize=0;

        let mask: usize=0;

        Self::dfs(&workers, &bikes, &mut memo, w, b, mask, worker_index)
    }

    fn dfs(workers: &Vec<Vec<i32>>, bikes: &Vec<Vec<i32>>, memo: &mut Vec<i32>, w: usize, b: usize, mask: usize, worker_index: usize) -> i32
    {
        if worker_index==w
        {
            return 0;
        }

        if memo[mask]!=i32::MAX
        {
            return memo[mask];
        }

        let mut subproblem_solution: i32=i32::MAX;

        for bike_index in 0..b
        {
            let bike_assigned: usize=mask & (1 << bike_index);
            
            if bike_assigned==0
            {
                let manhattan_distance: i32=Self::get_manhattan_distance(workers[worker_index][0], workers[worker_index][1], bikes[bike_index][0], bikes[bike_index][1]);

                let next_mask: usize=mask | (1 << bike_index);

                let next_call: i32=manhattan_distance + Self::dfs(workers, bikes, memo, w, b, next_mask, worker_index + 1);

                subproblem_solution=i32::min(subproblem_solution, next_call);
            }
        }

        memo[mask]=subproblem_solution;

        subproblem_solution
    }

    fn get_manhattan_distance(x1: i32, y1: i32, x2: i32, y2: i32) -> i32
    {
        let mut x_difference=x1 - x2;

        let mut y_difference=y1 - y2;

        x_difference.abs() + y_difference.abs()
    }
}