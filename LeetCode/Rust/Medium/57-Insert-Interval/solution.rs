impl Solution
{
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        if intervals.is_empty()
        {
            result.push(new_interval);

            return result;
        }

        let new_interval_start: i32=new_interval[0];

        let new_interval_end: i32=new_interval[1];

        let mut intermediate_intervals: Vec<Vec<i32>>=Vec::new();

        let mut overlaps: bool=false;

        for interval in intervals.iter()
        {
            let current_interval_start: i32=interval[0];

            let current_interval_end: i32=interval[1];

            if new_interval_end < current_interval_start || current_interval_end < new_interval_start
            {
                intermediate_intervals.push(interval.to_vec());
            }
            else
            {
                let merged_interval: Vec<i32>=vec![std::cmp::min(current_interval_start, new_interval_start), std::cmp::max(current_interval_end, new_interval_end)];

                intermediate_intervals.push(merged_interval);

                overlaps=true;
            }
        }

        let m: usize=intermediate_intervals.len();

        if !overlaps
        {
            let mut insertion_index: i32=-1;

            for index in 1..m
            {
                let previous_interval_start: i32=intermediate_intervals[index - 1][0];

                let previous_interval_end: i32=intermediate_intervals[index - 1][1];

                let current_interval_start: i32=intermediate_intervals[index][0];

                let current_interval_end: i32=intermediate_intervals[index][1];

                if previous_interval_end < new_interval_start && new_interval_end < current_interval_end
                {
                    insertion_index=index as i32;

                    break;
                }
            }

            if insertion_index==-1
            {
                if new_interval_end < intermediate_intervals[0][0]
                {
                    insertion_index=0;
                }
                else if intermediate_intervals[m - 1][1] < new_interval_end
                {
                    insertion_index=m as i32;
                }

            }

            for index in 0..m
            {
                if result.len()==(insertion_index as usize)
                {
                    result.push(new_interval.clone());
                }

                result.push(intermediate_intervals[index].clone());

                if result.len()==(insertion_index as usize)
                {
                    result.push(new_interval.clone());
                }
            }

            return result;
        }

        result.push(intermediate_intervals[0].clone());

        for index in 1..m
        {
            let result_interval: &Vec<i32>=result.last().unwrap();

            let result_interval_start: i32=result_interval[0];

            let result_interval_end: i32=result_interval[1];

            let current_interval_start: i32=intermediate_intervals[index][0];

            let current_interval_end: i32=intermediate_intervals[index][1];

            if result_interval_end < current_interval_start || current_interval_end < result_interval_start
            {
                result.push(intermediate_intervals[index].clone());
            }
            else
            {
                result.pop();

                let merged_interval: Vec<i32>=vec![std::cmp::min(result_interval_start, current_interval_start), std::cmp::max(result_interval_end, current_interval_end)];

                result.push(merged_interval);
            }
        }

        result
    }
}