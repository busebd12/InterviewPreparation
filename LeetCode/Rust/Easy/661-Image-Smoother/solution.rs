impl Solution
{
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let rows: usize=img.len();

        let columns: usize=img[0].len();

        result=vec![vec![0; columns]; rows];

        for row in 0..rows
        {
            for column in 0..columns
            {
                let average: i32=Self::get_average(&img, rows, columns, row, column);

                result[row][column]=average;
            }
        }

        result
    }

    pub fn get_average(img: &Vec<Vec<i32>>, rows: usize, columns: usize, row: usize, column: usize) -> i32
    {
        let mut directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, 1), (1, -1), (-1, -1)];

        let mut total: u32=img[row][column] as u32;

        let mut neighbours: u32=1;

        for (row_offset, column_offset) in directions
        {
            let next_row: usize=row + row_offset as usize;

            let next_column: usize=column + column_offset as usize;

            let valid_neighbour: bool=((next_row >= 0 && next_row < rows) && (next_column >= 0 && next_column < columns));

            if valid_neighbour
            {
                total+=img[next_row][next_column] as u32;

                neighbours+=1
            }
        }

        (f64::from(total) / f64::from(neighbours)).floor() as i32
    }
}