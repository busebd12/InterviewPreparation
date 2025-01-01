impl Solution
{
    pub fn length_of_lis(nums: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let n: usize=nums.len();

        let mut memo: Vec<i32>=vec![-1; n];

        for index in 0..n
        {
            let length: i32=1 + Self::dfs(&nums, &mut memo, n, index);

            result=i32::max(result, length);
        }

        result
    }

    fn dfs(nums: &Vec<i32>, memo: &mut Vec<i32>, n: usize, index: usize) -> i32
    {
        if index==n
        {
            return 0;
        }

        if memo[index]!=-1
        {
            return memo[index];
        }

        let mut subproblem_solution: i32=0;

        for i in index + 1..n
        {
            if nums[i] > nums[index]
            {
                subproblem_solution=i32::max(subproblem_solution, 1 + Self::dfs(nums, memo, n, i));
            }
        }

        memo[index]=subproblem_solution;

        subproblem_solution
    }
}