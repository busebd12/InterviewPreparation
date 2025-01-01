impl Solution
{
    pub fn num_decodings(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();
        
        let mut memo: Vec<i32>=vec![-1; n];

        let mut index: usize=0;

        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        result=Self::helper(&characters, &mut memo, n, index);

        result
    }

    pub fn helper(characters: &Vec<char>, memo: &mut Vec<i32>, n: usize, mut index: usize) -> i32
    {   
        if index==n
        {
            return 1;
        }

        if characters[index]=='0'
        {
            return 0;
        }

        if memo[index]!=-1
        {
            return memo[index];
        }

        let mut subproblem_solution: i32=0;

        if characters[index]=='1'
        {
            subproblem_solution+=Self::helper(characters, memo, n, index + 1);

            if index + 1 < n
            {
                subproblem_solution+=Self::helper(characters, memo, n, index + 2);
            }
        }
        else if characters[index]=='2'
        {
            subproblem_solution+=Self::helper(characters, memo, n, index + 1);

            if index + 1 < n && (characters[index + 1].to_digit(10).unwrap() >= 0 && characters[index + 1].to_digit(10).unwrap() <= 6)
            {
                subproblem_solution+=Self::helper(characters, memo, n, index + 2);
            }
        }
        else
        {
            subproblem_solution+=Self::helper(characters, memo, n, index + 1);
        }

        memo[index]=subproblem_solution;

        return subproblem_solution;
    }
}