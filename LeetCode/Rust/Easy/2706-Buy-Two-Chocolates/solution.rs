impl Solution
{
    pub fn buy_choco(mut prices: Vec<i32>, money: i32) -> i32
    {
        let mut total: i32=0;

        let n: usize=prices.len();

        let limit: u32=10u32.pow(2) + 1;

        let mut buckets: Vec<u32>=vec![0; limit as usize];

        for &price in prices.iter()
        {
            buckets[price as usize]+=1;
        }

        let mut smallest: i32=-1;

        let mut second_smallest: i32=-1;

        for price in 1..limit
        {
            let index: usize=price as usize;
            
            if buckets[index] > 0
            {
                if buckets[index]==1
                {
                    if smallest==-1 && second_smallest==-1
                    {
                        smallest=price as i32;
                    }
                    else if smallest!=-1 && second_smallest==-1
                    {
                        second_smallest=price as i32;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if smallest==-1 && second_smallest==-1
                    {
                        smallest=price as i32;

                        second_smallest=price as i32;
                    }
                    else if smallest!=-1 && second_smallest==-1
                    {
                        second_smallest=price as i32;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        total=smallest + second_smallest;

        let result: i32=if money - total >= 0 {money - total} else{money};

        result
    }
}

impl Solution
{
    pub fn buy_choco(mut prices: Vec<i32>, money: i32) -> i32
    {
        let mut total: i32=0;

        let n: usize=prices.len();

        prices.sort();

        let smallest: i32=prices[0];

        let second_smallest: i32=prices[1];

        total=smallest + second_smallest;

        let result: i32=if money - total >= 0 {money - total} else{money};

        result
    }
}