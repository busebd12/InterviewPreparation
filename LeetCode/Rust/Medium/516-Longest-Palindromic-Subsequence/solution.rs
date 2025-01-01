impl Solution
{
    pub fn longest_palindrome_subseq(s: String) -> i32
    {
        let characters: Vec<char>=s.chars().collect::<Vec<char>>();

        let n: usize=characters.len();

        let mut memo: Vec<Vec<i32>>=vec![vec![-1; n]; n];

        let mut left: usize=0;

        let mut right: usize=n - 1;

        let result: i32=Self::helper(&mut memo, &characters, left, right);

        result
    }

    pub fn helper(memo: &mut Vec<Vec<i32>>, characters: &Vec<char>, left: usize, right: usize) -> i32
    {
        if left==right
        {
            return 1;
        }

        if left > right
        {
            return 0;
        }

        if memo[left as usize][right as usize]!=-1
        {
            return memo[left as usize][right as usize];
        }

        let mut subproblem_solution: i32=0;

        if characters[left as usize]==characters[right as usize]
        {
            subproblem_solution=2 + Self::helper(memo, characters, left + 1, right - 1);
        }
        else
        {
            let pick_left_character: i32=Self::helper(memo, characters, left, right - 1);

            let pick_right_character: i32=Self::helper(memo, characters, left + 1, right);

            subproblem_solution=i32::max(pick_left_character, pick_right_character);
        }

        memo[left as usize][right as usize]=subproblem_solution;

        subproblem_solution
    }
}