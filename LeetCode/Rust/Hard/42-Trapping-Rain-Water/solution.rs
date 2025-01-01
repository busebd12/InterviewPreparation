impl Solution
{
    pub fn trap(height: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let h: usize=height.len();

        let mut left_boundary: Vec<i32>=vec![0; h];

        left_boundary[0]=height[0];

        for index in 1..h
        {
            left_boundary[index]=std::cmp::max(left_boundary[index - 1], height[index]);
        }

        let mut right_boundary: Vec<i32>=vec![0; h];

        right_boundary[h - 1]=height[h - 1];

        if (h - 2) as i32 > 0
        {
            for index in (0..=h-2).rev()
            {
                right_boundary[index]=std::cmp::max(right_boundary[index + 1], height[index]);
            }
        }

        for index in 0..h
        {
            let max_left_boundary: i32=left_boundary[index];

            let max_right_boundary: i32=right_boundary[index];

            let fill_line: i32=std::cmp::min(max_left_boundary, max_right_boundary);

            let water_trapped: i32=fill_line - height[index];

            if water_trapped > 0
            {
                result+=water_trapped;
            }
        }

        result
    }
}