impl Solution
{
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32
    {
        let mut result: i32=0;

        if s.is_empty()
        {
            return result
        }

        g.sort();

        s.sort();

        let n: usize=g.len();

        let m: usize=s.len();

        let mut greed_index: usize=0;

        let mut cookie_index: usize=0;

        while greed_index < n && cookie_index < m
        {
            if s[cookie_index] >= g[greed_index]
            {
                result+=1;

                greed_index+=1;
            }

            cookie_index+=1;
        }

        result
    }
}