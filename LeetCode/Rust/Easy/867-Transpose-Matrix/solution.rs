impl Solution
{
    pub fn transpose(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let rows: usize=matrix.len();

        let columns: usize=matrix[0].len();

        result=vec![vec![0; rows]; columns];

        for row in 0..rows
        {
            for column in 0..columns
            {
                result[column][row]=matrix[row][column];
            }
        }

        result
    }
}