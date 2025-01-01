impl Solution
{
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32
    {
        let mut result: i32=0;

        let rows: usize=matrix.len();

        let columns: usize=matrix[0].len();

        let mut heights: Vec<i32>=vec![0; columns];

        for row in 0..rows
        {
            Self::update_heights(&matrix, &mut heights, columns, row);

            let max_rectangle_area_in_histogram: i32=Self::get_max_rectangle_area_in_histogram(&heights);

            result=std::cmp::max(result, max_rectangle_area_in_histogram);
        }

        result
    }

    fn update_heights(matrix: &Vec<Vec<char>>, heights: &mut Vec<i32>, columns: usize, row: usize) -> ()
    {
        for column in 0..columns
        {
            let digit: u32=matrix[row][column].to_digit(10).unwrap();

            match digit
            {
                0 =>
                {
                    heights[column]=0;
                },
                _ =>
                {
                    heights[column]+=1;
                }
            }
        }
    }

    fn get_max_rectangle_area_in_histogram(heights: &Vec<i32>) -> i32
    {
        let mut max_area: i32=0;

        let h: usize=heights.len();

        let mut staircase: Vec<(usize, i32)>=Vec::new();

        for (index, step) in heights.iter().enumerate()
        {
            let mut staircase_start_index: usize=index;

            match (staircase.is_empty())
            {
                true =>
                {
                    staircase.push((staircase_start_index, *step));
                },
                false =>
                {
                    match (*step < (*(staircase.last().unwrap())).1)
                    {
                        true =>
                        {
                            while(!staircase.is_empty() && *step < (*(staircase.last().unwrap())).1)
                            {
                                let (i, height): (usize, i32)=staircase.pop().unwrap();

                                let width: i32=(index - i) as i32;

                                let area: i32=width * height;

                                max_area=std::cmp::max(max_area, area);

                                staircase_start_index=i;
                            }

                            staircase.push((staircase_start_index, *step));
                        },
                        false =>
                        {
                            staircase.push((staircase_start_index, *step));
                        }
                    }
                }
            }
        }

        while let Some((i, height))=staircase.pop()
        {
            let width: i32=(h - i) as i32;

            let area: i32=width * height;

            max_area=std::cmp::max(max_area, area);
        }

        max_area
    }
}