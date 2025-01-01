impl Solution
{
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        let characters: Vec<char>=colors.chars().collect::<Vec<char>>();

        let n: usize=characters.len();

        let mut i: usize=0;

        while i < n
        {
            let mut j: usize=i + 1;

            let mut running_sum: i32=needed_time[i];

            let mut max_time: i32=needed_time[i];

            let mut count: u32=1;

            while j < n && characters[i]==characters[j]
            {
                count+=1;

                running_sum+=needed_time[j];

                max_time=i32::max(max_time, needed_time[j]);

                j+=1;
            }

            if count > 1
            {
                running_sum-=max_time;

                result+=running_sum;
            }

            i=j;
        }

        result
    }
}