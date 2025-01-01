use std::cmp;

impl Solution
{
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=text1.len();

        let m: usize=text2.len();

        let mut memo: Vec<Vec<i32>>=vec![vec![-1; m]; n];

        let text1_characters: Vec<char>=text1.chars().collect::<Vec<char>>();

        let text2_characters: Vec<char>=text2.chars().collect::<Vec<char>>();

        let mut i: usize=0;

        let mut j: usize=0;

        result=Self::helper(&text1_characters, &text2_characters, &mut memo, n, m, i, j);

        result
    }

    fn helper(text1_characters: &Vec<char>, text2_characters: &Vec<char>, memo: &mut Vec<Vec<i32>>, n: usize, m: usize, i: usize, j: usize) -> i32
    {
        if i >= n || j >= m
        {
            return 0;
        }

        if memo[i][j]!=-1
        {
            return memo[i][j];
        }

        let mut subproblem_solution: i32=0;

        if text1_characters[i]==text2_characters[j]
        {
            subproblem_solution=1 + Self::helper(text1_characters, text2_characters, memo, n, m, i + 1, j + 1);
        }
        else
        {
            subproblem_solution=std::cmp::max(Self::helper(text1_characters, text2_characters, memo, n, m, i + 1, j), Self::helper(text1_characters, text2_characters, memo, n, m, i, j + 1));
        }

        memo[i][j]=subproblem_solution;

        subproblem_solution
    }
}