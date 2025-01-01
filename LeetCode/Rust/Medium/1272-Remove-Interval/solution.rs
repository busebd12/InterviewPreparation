impl Solution
{
    pub fn remove_interval(intervals: Vec<Vec<i32>>, to_be_removed: Vec<i32>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let to_be_removed_start: i32=to_be_removed[0];

        let to_be_removed_end: i32=to_be_removed[1];

        for interval in intervals.iter()
        {
            let current_interval_start: i32=interval[0];

            let current_interval_end: i32=interval[1];

            if (to_be_removed_start < current_interval_start && to_be_removed_end < current_interval_start) || (current_interval_end < to_be_removed_start && current_interval_end < to_be_removed_end)
            {
                result.push(interval.to_vec());
            }
            else if to_be_removed_start <= current_interval_start && current_interval_end <= to_be_removed_end
            {
                continue;
            }
            else if (current_interval_start < to_be_removed_start && to_be_removed_start < current_interval_end) && (current_interval_start < to_be_removed_end && to_be_removed_end < current_interval_end)
            {
                result.push(vec![current_interval_start, to_be_removed_start]);

                result.push(vec![to_be_removed_end, current_interval_end]);
            }
            else if (to_be_removed_start <= current_interval_start) && (current_interval_start <= to_be_removed_end && to_be_removed_end < current_interval_end)
            {
                result.push(vec![std::cmp::max(current_interval_start, to_be_removed_end), current_interval_end]);
            }
            else if (to_be_removed_end >= current_interval_end) && (current_interval_start < to_be_removed_start && to_be_removed_start <= current_interval_end)
            {
                result.push(vec![current_interval_start, std::cmp::min(current_interval_end, to_be_removed_start)]);
            }
        }

        result
    }
}