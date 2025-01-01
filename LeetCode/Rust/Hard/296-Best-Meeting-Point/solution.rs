impl Solution
{
    pub fn min_total_distance(grid: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        let mut x_coordinates: Vec<i32>=Vec::new();

        for row in 0..rows
        {
            for column in 0..columns
            {
                if grid[row][column]==1
                {
                    x_coordinates.push(row as i32);
                }
            }
        }

        let mut y_coordinates: Vec<i32>=Vec::new();

        for column in 0..columns
        {
            for row in 0..rows
            {
                if grid[row][column]==1
                {
                    y_coordinates.push(column as i32);
                }
            }
        }

        let midpoint: usize=x_coordinates.len() / 2;

        let x_coordinates_middle: i32=x_coordinates[midpoint];

        let y_coordinates_middle: i32=y_coordinates[midpoint];

        for row in 0..rows
        {
            for column in 0..columns
            {
                if grid[row][column]==1
                {
                    let manhattan_distance: i32=Self::get_manhattan_distance(row as i32, column as i32, x_coordinates_middle, y_coordinates_middle);

                    result+=manhattan_distance;
                }
            }
        }

        result
    }

    pub fn get_manhattan_distance(x1: i32, y1: i32, x2: i32, y2: i32) -> i32
    {
        let x_coordinate_difference: i32=x1 - x2;

        let y_coordinate_difference: i32=y1 - y2;

        let manhattan_distance: i32=x_coordinate_difference.abs() + y_coordinate_difference.abs();

        manhattan_distance
    }
}