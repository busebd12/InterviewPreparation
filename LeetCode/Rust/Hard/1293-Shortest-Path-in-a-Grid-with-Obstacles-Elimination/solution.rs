use std::collections::{HashSet, VecDeque};

impl Solution
{
    pub fn shortest_path(grid: Vec<Vec<i32>>, k: i32) -> i32
    {
        let mut result: i32=0;

        let rows: usize=grid.len();

        let columns: usize=grid[0].len();

        let mut seen_states: HashSet<String>=HashSet::new();

        seen_states.insert(rows.to_string() + columns.to_string().as_str() + k.to_string().as_str());

        let directions: Vec<(i32, i32)>=vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        let mut queue: VecDeque<(i32, i32, i32)>=VecDeque::new();

        queue.push_back((0, 0, k));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                let (row, column, obstacles_we_can_clear): (i32, i32, i32)=queue.pop_front().unwrap();

                if row==((rows-1) as i32) && column==((columns-1) as i32)
                {
                    return result;
                }

                for (row_offset, column_offset) in &directions
                {
                    let next_row: i32=row + row_offset;

                    let next_column: i32=column + column_offset;

                    let is_valid: bool=((next_row >= 0 && next_row < rows as i32) && (next_column >= 0 && next_column < columns as i32));

                    if is_valid
                    {
                        let remaining_obstacles_we_can_clear: i32=obstacles_we_can_clear - grid[next_row as usize][next_column as usize];

                        if remaining_obstacles_we_can_clear >= 0
                        {
                            let next_state: String=next_row.to_string() + next_column.to_string().as_str() + remaining_obstacles_we_can_clear.to_string().as_str();

                            if !seen_states.contains(&next_state)
                            {
                                seen_states.insert(next_state);

                                queue.push_back((next_row, next_column, remaining_obstacles_we_can_clear));
                            }
                        }
                    }
                }
            }

            if !queue.is_empty()
            {
                result+=1;
            }
        }

        -1
    }
}