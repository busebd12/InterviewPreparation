impl Solution
{
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=mat.len();

        let columns: usize=mat[0].len();

        let mut one_positions: Vec<(usize, usize)>=Vec::new();

        for row in 0..rows
        {
            for column in 0..columns
            {
                if mat[row][column]==1
                {
                    let position: (usize, usize)=(row, column);
                    
                    one_positions.push(position);
                }
            }
        }

        for (row, column) in one_positions.iter()
        {
            let value: usize=1;
            
            if Self::single_one_in_row(&mat, columns, *row, *column, value) && Self::single_one_in_column(&mat, rows, *row, *column, value)
            {
                result+=1;
            }
        }

        result
    }

    pub fn single_one_in_row(mat: &Vec<Vec<i32>>, columns: usize, row: usize, column: usize, value: usize) -> bool
    {
        for c in 0..column
        {
            if mat[row][c]==(value as i32)
            {
                return false;
            }
        }

        for c in column + 1..columns
        {
            if mat[row][c]==(value as i32)
            {
                return false;
            }
        }

        true
    }

    pub fn single_one_in_column(mat: &Vec<Vec<i32>>, rows: usize, row: usize, column: usize, value: usize) -> bool
    {
        for r in 0..row
        {
            if mat[r][column]==(value as i32)
            {
                return false;
            }
        }

        for r in row + 1..rows
        {
            if mat[r][column]==(value as i32)
            {
                return false;
            }
        }

        true
    }
}