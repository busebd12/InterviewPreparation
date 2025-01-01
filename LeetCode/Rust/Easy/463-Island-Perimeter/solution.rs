use std::collections::{VecDeque};

impl Solution
{
    pub fn island_perimeter(mut grid: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if grid[row][column]==1
                {
                    Solution::dfs(&mut grid, &directions, &mut result, rows, columns, row, column);
                }
            }
        }

        result
    }

    fn dfs(grid: &mut Vec<Vec<i32>>, directions: &Vec<(i32, i32)>, result: &mut i32, rows: usize, columns: usize, row: usize, column: usize) -> ()
    {
        grid[row][column]=2;

        for (row_offset, column_offset) in directions.iter()
        {
            let next_row: i32=(row as i32 + *row_offset);

            let next_column: i32=(column as i32 + *column_offset);

            let is_valid: bool=Solution::is_valid_position(rows, columns, next_row, next_column);

            if !is_valid
            {
                *result+=1;

                continue;
            }

            if is_valid && grid[next_row as usize][next_column as usize]==0
            {
                *result+=1;

                continue;
            }

            if is_valid && grid[next_row as usize][next_column as usize]==2
            {
                continue;
            }

            grid[next_row as usize][next_column as usize]=2;

            Solution::dfs(grid, directions, result, rows, columns, next_row as usize, next_column as usize);
        }
    }

    fn is_valid_position(rows: usize, columns: usize, row: i32, column: i32) -> bool
    {
        (row >= 0 && row < (rows as i32)) && (column >= 0 && column < (columns as i32))
    }
}

impl Solution
{
    pub fn island_perimeter(mut grid: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if grid[row][column]==1
                {
                    Solution::dfs(&mut grid, &directions, &mut result, rows, columns, row, column);
                }
            }
        }

        result
    }

    fn dfs(grid: &mut Vec<Vec<i32>>, directions: &Vec<(i32, i32)>, result: &mut i32, rows: usize, columns: usize, row: usize, column: usize) -> ()
    {
        let mut stack: Vec<(usize, usize)>=Vec::new();
        
        grid[row][column]=2;

        stack.push((row, column));

        while let Some((row, column))=stack.pop()
        {
            for (row_offset, column_offset) in directions.iter()
            {
                let next_row: i32=(row as i32 + *row_offset);

                let next_column: i32=(column as i32 + *column_offset);

                let is_valid: bool=Solution::is_valid_position(rows, columns, next_row, next_column);

                if !is_valid
                {
                    *result+=1;

                    continue;
                }

                if is_valid && grid[next_row as usize][next_column as usize]==0
                {
                    *result+=1;

                    continue;
                }

                if is_valid && grid[next_row as usize][next_column as usize]==2
                {
                    continue;
                }

                grid[next_row as usize][next_column as usize]=2;

                stack.push((next_row as usize, next_column as usize));
            }
        }
    }

    fn is_valid_position(rows: usize, columns: usize, row: i32, column: i32) -> bool
    {
        (row >= 0 && row < (rows as i32)) && (column >= 0 && column < (columns as i32))
    }
}

impl Solution
{
    pub fn island_perimeter(mut grid: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if grid[row][column]==1
                {
                    Solution::bfs(&mut grid, &directions, &mut result, rows, columns, row, column);
                }
            }
        }

        result
    }

    fn bfs(grid: &mut Vec<Vec<i32>>, directions: &Vec<(i32, i32)>, result: &mut i32, rows: usize, columns: usize, row: usize, column: usize) -> ()
    {
        let mut queue: VecDeque<(usize, usize)>=VecDeque::new();
        
        grid[row][column]=2;

        queue.push_back((row, column));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some((row, column))=queue.pop_front()
                {
                    for (row_offset, column_offset) in directions.iter()
                    {
                        let next_row: i32=(row as i32 + *row_offset);

                        let next_column: i32=(column as i32 + *column_offset);

                        let is_valid: bool=Solution::is_valid_position(rows, columns, next_row, next_column);

                        if !is_valid
                        {
                            *result+=1;

                            continue;
                        }

                        if is_valid && grid[next_row as usize][next_column as usize]==0
                        {
                            *result+=1;

                            continue;
                        }

                        if is_valid && grid[next_row as usize][next_column as usize]==2
                        {
                            continue;
                        }

                        grid[next_row as usize][next_column as usize]=2;

                        queue.push_back((next_row as usize, next_column as usize));
                    }
                }
            }
        }
    }

    fn is_valid_position(rows: usize, columns: usize, row: i32, column: i32) -> bool
    {
        (row >= 0 && row < (rows as i32)) && (column >= 0 && column < (columns as i32))
    }
}