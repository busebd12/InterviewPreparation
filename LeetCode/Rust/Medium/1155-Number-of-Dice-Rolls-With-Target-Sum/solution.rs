impl Solution
{
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32
    {
        let mut result: i32=0;

        let mut memo: Vec<Vec<i32>>=vec![vec![-1; (target + 1) as usize]; (n + 1) as usize];

        let MOD: i32=i32::pow(10, 9) + 7;
        
        let mut result: i32=Self::helper(&mut memo, MOD, n, k, target);

        result
    }

    pub fn helper(memo: &mut Vec<Vec<i32>>, MOD: i32, mut n: i32, k: i32, mut target: i32) -> i32
    {
        if target < 0
        {
            return 0;
        }

        if n==1 && k < target && target > 0
        {
            return 0;
        }

        if n==1 && k >= target && target > 0
        {
            return 1;
        }

        if memo[n as usize][target as usize]!=-1
        {
            return memo[n as usize][target as usize];
        }

        let mut subproblem_solution: i32=0;

        for face in 1..=k
        {
            subproblem_solution+=Self::helper(memo, MOD, n - 1, k, target - face);

            subproblem_solution%=MOD;
        }

        memo[n as usize][target as usize]=subproblem_solution;

        subproblem_solution
    }
}