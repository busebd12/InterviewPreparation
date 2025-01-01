impl Solution
{
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32
    {
        let mut result=-1;

        let mut indegree: Vec<i32>=vec![0; (n + 1) as usize];

        let mut outdegree: Vec<i32>=vec![0; (n + 1) as usize];

        for edge in trust.iter()
        {
            let a: i32=edge[0];

            let b: i32=edge[1];

            outdegree[a as usize]+=1;

            indegree[b as usize]+=1;
        }

        for person in 1..n + 1
        {
            if outdegree[person as usize]==0 && indegree[person as usize]==n-1
            {
                result=person;

                break;
            }
        }

        result
    }
}