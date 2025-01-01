impl Solution
{
    pub fn cherry_pickup(grid: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        let mut memo: Vec<Vec<Vec<i32>>>=vec![vec![vec![-1; columns]; columns]; rows];

        let directions: Vec<(i32, i32)>=vec![(1, -1), (1, 0), (1, 1)];

        let mut row: i32=0;

        let robot1_column: i32=0;

        let robot2_column: i32=(columns - 1) as i32;

        result=Self::helper(&grid, &mut memo, &directions, rows, columns, row, robot1_column, robot2_column);

        result
    }

    fn helper(grid: &Vec<Vec<i32>>, memo: &mut Vec<Vec<Vec<i32>>>, directions: &Vec<(i32, i32)>, rows: usize, columns: usize, row: i32, robot1_column: i32, robot2_column: i32) -> i32
    {
        if !Self::is_valid(rows, columns, row, robot1_column) || !Self::is_valid(rows, columns, row, robot2_column)
        {
            return 0;
        }

        if memo[row as usize][robot1_column as usize][robot2_column as usize]!=-1
        {
            return memo[row as usize][robot1_column as usize][robot2_column as usize];
        }

        let mut subproblem_solution: i32=0;

        subproblem_solution+=grid[row as usize][robot1_column as usize];

        if robot1_column!=robot2_column
        {
            subproblem_solution+=grid[row as usize][robot2_column as usize];
        }

        let mut max_cherries: i32=0;

        for (robot1_row_offset, robot1_column_offset) in directions.iter()
        {
            let next_robot1_column: i32=robot1_column + robot1_column_offset;
            
            for (robot2_row_offset, robot2_column_offset) in directions.iter()
            {
                let next_robot2_column: i32=robot2_column + robot2_column_offset;

                max_cherries=std::cmp::max(max_cherries, Self::helper(grid, memo, directions, rows, columns, row + 1, next_robot1_column, next_robot2_column));
            }
        }

        subproblem_solution+=max_cherries;

        memo[row as usize][robot1_column as usize][robot2_column as usize]=subproblem_solution;

        subproblem_solution
    }

    fn is_valid(rows: usize, columns: usize, robot_row: i32, robot_column: i32) -> bool
    {
        let valid_row: bool=((robot_row as usize) >= 0 && (robot_row as usize) < rows);

        let valid_column: bool=((robot_column as usize) >= 0 && (robot_column as usize) < columns);
        
        valid_row && valid_column
    }
}