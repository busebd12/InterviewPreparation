impl Solution
{
    pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        result=vec![vec![0; columns]; rows];

        let value: usize=1;

        let ones_rows_hashmap: Vec<usize>=Self::create_rows_hashmap(&grid, rows, columns, value);

        let ones_columns_hashmap: Vec<usize>=Self::create_columns_hashmap(&grid, rows, columns, value);

        for row in 0..rows
        {
            for column in 0..columns
            {
                let ones_in_row: usize=ones_rows_hashmap[row];

                let ones_in_column: usize=ones_columns_hashmap[column];

                let zeros_in_row: usize=columns - ones_in_row;

                let zeros_in_column: usize=rows - ones_in_column;

                let difference: usize=ones_in_row + ones_in_column - zeros_in_row - zeros_in_column;

                result[row][column]=difference as i32;
            }
        }

        result
    }

    pub fn create_rows_hashmap(grid: &Vec<Vec<i32>>, rows: usize, columns: usize, value: usize) -> Vec<usize>
    {
        let mut rows_hashmap: Vec<usize>=vec![0; rows];

        for row in 0..rows
        {
            let mut count: usize=0;

            for column in 0..columns
            {
                if grid[row][column]==(value as i32)
                {
                    count+=1;
                }
            }

            rows_hashmap[row]=count;
        }

        rows_hashmap
    }

    pub fn create_columns_hashmap(grid: &Vec<Vec<i32>>, rows: usize, columns: usize, value: usize) -> Vec<usize>
    {
        let mut columns_hashmap: Vec<usize>=vec![0; columns];

        for column in 0..columns
        {
            let mut count: usize=0;

            for row in 0..rows
            {
                if grid[row][column]==(value as i32)
                {
                    count+=1;
                }
            }

            columns_hashmap[column]=count;
        }

        columns_hashmap
    }
}