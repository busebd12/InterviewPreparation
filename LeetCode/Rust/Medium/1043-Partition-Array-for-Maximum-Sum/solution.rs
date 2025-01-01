impl Solution
{
    pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32
    {
        let mut result: i32=0;

        let n: usize=arr.len();

        let mut memo: Vec<i32>=vec![-1; n];

        let mut index: usize=0;

        result=Self::helper(&arr, &mut memo, n, k, index);

        result
    }

    fn helper(arr: &Vec<i32>, memo: &mut Vec<i32>, n: usize, k: i32, index: usize) -> i32
    {
        if index >= n
        {
            return 0;
        }

        if memo[index]!=-1
        {
            return memo[index];
        }

        let mut subproblem_solution: i32=0;

        let stop: usize=usize::min(index + (k as usize), n);

        let mut subarray_max: i32=0;

        for i in index..stop
        {
            subarray_max=i32::max(subarray_max, arr[i]);

            let subarray_length: usize=(i - index) + 1;

            let subarray_total: i32=subarray_max * (subarray_length as i32);

            let recursive_call_solution: i32=subarray_total + Self::helper(arr, memo, n, k, i + 1);

            subproblem_solution=i32::max(subproblem_solution, recursive_call_solution);
        }

        memo[index]=subproblem_solution;

        subproblem_solution
    }
}