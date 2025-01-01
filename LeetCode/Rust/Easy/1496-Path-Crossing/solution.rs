use std::collections::HashSet;

impl Solution
{
    pub fn is_path_crossing(path: String) -> bool
    {
        let mut visited: HashSet<(i32, i32)>=HashSet::new();

        visited.insert((0, 0));

        let mut current_x: i32=0;

        let mut current_y: i32=0;

        for direction in path.chars()
        {
            match direction
            {
                'N' =>
                {
                    current_x-=1;
                }
                'S' =>
                {
                    current_x+=1;
                }
                'E' =>
                {
                    current_y+=1;
                }
                'W' =>
                {
                    current_y-=1;
                }
                _ =>
                {
                    ()
                }
            }

            let next_point: (i32, i32)=(current_x, current_y);

            if visited.contains(&next_point)
            {
                return true;
            }

            visited.insert(next_point);
        }

        false
    }
}