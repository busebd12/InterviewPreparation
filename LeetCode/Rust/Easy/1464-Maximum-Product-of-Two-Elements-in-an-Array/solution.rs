impl Solution
{
    pub fn max_product(nums: Vec<i32>) -> i32
    {
        let mut result=0;

        let n: usize=nums.len();

        let limit: usize=usize::pow(10, 3) + 1;

        let mut frequencies: Vec<usize>=vec![0; limit];

        for &number in nums.iter()
        {
            frequencies[number as usize]+=1;
        }

        let mut largest: usize=0;

        let mut second_largest: usize=0;

        for index in (0..limit).rev()
        {
            if frequencies[index] > 0
            {
                if frequencies[index]==1
                {
                    largest=index;
                }
                else
                {
                    largest=index;

                    second_largest=index;
                }

                break;
            }
        }

        if second_largest==0
        {
            for index in (0..limit).rev()
            {
                if frequencies[index] > 0 && index!=largest
                {
                    second_largest=index;

                    break;
                }
            }
        }

        result=(largest - 1) as i32 * (second_largest - 1) as i32;

        result
    }
}