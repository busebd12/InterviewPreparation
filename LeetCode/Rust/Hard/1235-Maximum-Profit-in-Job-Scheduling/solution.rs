use std::cmp::Ordering;

#[derive(Debug)]
struct Job
{
    start_time: i32,

    end_time: i32,

    profit: i32,
}

impl Solution
{
    pub fn job_scheduling(mut start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=start_time.len();

        let mut memo: Vec<i32>=vec![-1; n];

        let mut jobs: Vec<Job>=start_time.into_iter().zip(end_time.into_iter().zip(profit)).map(|(start_time, (end_time, profit))| Job {start_time, end_time, profit}).collect::<Vec<Job>>();

        jobs.sort_unstable_by_key(|job| job.start_time);

        let mut index: usize=0;

        result=Self::helper(&jobs, &mut memo, n, index);

        result
    }

    fn helper(jobs: &Vec<Job>, memo: &mut Vec<i32>, n: usize, index: usize) -> i32
    {   
        if index >= n
        {
            return 0;
        }

        if memo[index]!=-1
        {
            return memo[index];
        }

        let mut subproblem_solution: i32=0;

        let current_job_end_time: i32=jobs[index].end_time;

        let next_start_index: usize=Self::get_next_start_index(jobs, n, index, current_job_end_time);

        let current_job_profit: i32=jobs[index].profit;

        let include: i32=current_job_profit + Self::helper(jobs, memo, n, next_start_index);

        let exclude: i32=Self::helper(jobs, memo, n, index + 1);

        subproblem_solution=i32::max(include, exclude);

        memo[index]=subproblem_solution;

        subproblem_solution
    }

    fn get_next_start_index(jobs: &Vec<Job>, n: usize, previous_start_index: usize, current_job_end_time: i32) -> usize
    {
        let mut low: usize=previous_start_index + 1;

        let mut high: usize=n - 1;

        while low < high
        {
            let middle: usize=low + (high - low) / 2;

            match jobs[middle].start_time.cmp(&current_job_end_time)
            {
                Ordering::Less =>
                {
                    low=middle + 1
                },
                Ordering::Equal | Ordering::Greater =>
                {
                    high=middle
                }
            }
        }

        if jobs[high].start_time < current_job_end_time
        {
            return n;
        }

        high
    }
}