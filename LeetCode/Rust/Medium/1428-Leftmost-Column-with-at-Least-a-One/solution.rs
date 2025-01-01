impl Solution
{
    pub fn left_most_column_with_one(binaryMatrix: &BinaryMatrix) -> i32
    {
        let mut result: i32=-1;

        let dimensions: Vec<i32>=binaryMatrix.dimensions();

        let rows: usize=dimensions[0] as usize;

        let columns: usize=dimensions[1] as usize;

        for row in 0..rows
        {   
            let left_most_column_in_row: i32=Self::search_row(&binaryMatrix, columns, row);

            if left_most_column_in_row!=-1
            {
                if result==-1
                {
                    result=left_most_column_in_row;
                }
                else
                {
                    result=i32::min(result, left_most_column_in_row);
                }
            }
        }

        result
    }

    fn search_row(binaryMatrix: &BinaryMatrix, columns: usize, row: usize) -> i32
    {
        let mut left_most_column: i32=-1;

        let mut low: i32=0;

        let mut high: i32=(columns - 1) as i32;

        while low <= high
        {
            let middle: i32=(low + (high - low)/2);

            let digit: i32=binaryMatrix.get(row as i32, middle as i32);

            if digit==1
            {
                left_most_column=middle;

                high=middle - 1;
            }
            else
            {
                low=middle + 1;
            }
        }

        left_most_column
    }
}