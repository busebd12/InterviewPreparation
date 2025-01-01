impl Solution
{
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32
    {
        let mut result: i32=0;

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

                                result=std::cmp::max(result, area);

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

            result=std::cmp::max(result, area);
        }

        result
    }
}