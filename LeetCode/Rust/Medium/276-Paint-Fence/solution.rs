impl Solution
{
    pub fn num_ways(n: i32, k: i32) -> i32
    {
        let mut result: i32=0;

        let mut memo: Vec<Vec<i32>>=vec![vec![-1; 2]; (n + 1) as usize];

        let mut previous_color: i32=-1;

        let previous_two_posts_the_same_color: i32=0;

        result=Self::helper(&mut memo, n, k, previous_color, previous_two_posts_the_same_color);

        result
    }

    fn helper(memo: &mut Vec<Vec<i32>>, n: i32, k: i32, previous_color: i32, previous_two_posts_the_same_color: i32) -> i32
    {
        if n==0
        {
            return 1;
        }

        if memo[n as usize][previous_two_posts_the_same_color as usize]!=-1
        {
            return memo[n as usize][previous_two_posts_the_same_color as usize];
        }

        let mut subproblem_solution: i32=0;

        for next_color in 0..k
        {
            if previous_color==next_color && previous_two_posts_the_same_color==1
            {
                continue;
            }

            subproblem_solution+=Self::helper(memo, n - 1, k, next_color, (previous_color==next_color) as i32);
        }

        memo[n as usize][previous_two_posts_the_same_color as usize]=subproblem_solution;

        return subproblem_solution;
    }
}