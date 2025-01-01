use std::collections::{VecDeque};

impl Solution
{
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let rows: usize=land.len();

        let columns: usize=land[0].len();

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if land[row][column]==1
                {
                    let mut coordinates: Vec<i32>=vec![row as i32, column as i32, row as i32, column as i32];
                    
                    Solution::dfs(&mut land, &directions, &mut coordinates, rows, columns, row, column);

                    result.push(coordinates.clone());
                }
            }
        }

        result
    }

    fn dfs(land: &mut Vec<Vec<i32>>, directions: &Vec<(i32, i32)>, coordinates: &mut Vec<i32>, rows: usize, columns: usize, row: usize, column: usize) -> ()
    {
        land[row][column]=2;

        for (row_offset, column_offset) in directions.iter()
        {
            let next_row: i32=(row as i32 + *row_offset);

            let next_column: i32=(column as i32 + *column_offset);

            let is_valid: bool=Solution::is_valid_position(rows, columns, next_row, next_column);

            if is_valid && land[next_row as usize][next_column as usize]==1
            {
                coordinates[2]=std::cmp::max(coordinates[2], next_row);

                coordinates[3]=std::cmp::max(coordinates[3], next_column);

                Solution::dfs(land, directions, coordinates, rows, columns, next_row as usize, next_column as usize);
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
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let rows: usize=land.len();

        let columns: usize=land[0].len();

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if land[row][column]==1
                {
                    let mut coordinates: Vec<i32>=vec![row as i32, column as i32, row as i32, column as i32];
                    
                    Solution::dfs(&mut land, &directions, &mut coordinates, rows, columns, row, column);

                    result.push(coordinates.clone());
                }
            }
        }

        result
    }

    fn dfs(land: &mut Vec<Vec<i32>>, directions: &Vec<(i32, i32)>, coordinates: &mut Vec<i32>, rows: usize, columns: usize, row: usize, column: usize) -> ()
    {
        let mut stack: Vec<(usize, usize)>=Vec::new();
        
        land[row][column]=2;

        stack.push((row, column));
        
        while let Some((row, column))=stack.pop()
        {
            for (row_offset, column_offset) in directions.iter()
            {
                let next_row: i32=(row as i32 + *row_offset);

                let next_column: i32=(column as i32 + *column_offset);

                let is_valid: bool=Solution::is_valid_position(rows, columns, next_row, next_column);

                if is_valid && land[next_row as usize][next_column as usize]==1
                {
                    coordinates[2]=std::cmp::max(coordinates[2], next_row);

                    coordinates[3]=std::cmp::max(coordinates[3], next_column);

                    land[next_row as usize][next_column as usize]=2;

                    stack.push((next_row as usize, next_column as usize));
                }
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
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let rows: usize=land.len();

        let columns: usize=land[0].len();

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if land[row][column]==1
                {
                    let mut coordinates: Vec<i32>=vec![row as i32, column as i32, row as i32, column as i32];
                    
                    Solution::bfs(&mut land, &directions, &mut coordinates, rows, columns, row, column);

                    result.push(coordinates.clone());
                }
            }
        }

        result
    }

    fn bfs(land: &mut Vec<Vec<i32>>, directions: &Vec<(i32, i32)>, coordinates: &mut Vec<i32>, rows: usize, columns: usize, row: usize, column: usize) -> ()
    {
        let mut queue: VecDeque<(usize, usize)>=VecDeque::new();
        
        land[row][column]=2;

        queue.push_back((row, column));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some((row, column))=queue.pop_back()
                {
                    for (row_offset, column_offset) in directions.iter()
                    {
                        let next_row: i32=(row as i32 + *row_offset);

                        let next_column: i32=(column as i32 + *column_offset);

                        let is_valid: bool=Solution::is_valid_position(rows, columns, next_row, next_column);

                        if is_valid && land[next_row as usize][next_column as usize]==1
                        {
                            coordinates[2]=std::cmp::max(coordinates[2], next_row);

                            coordinates[3]=std::cmp::max(coordinates[3], next_column);

                            land[next_row as usize][next_column as usize]=2;

                            queue.push_back((next_row as usize, next_column as usize));
                        }
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