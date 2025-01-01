impl Solution
{
    pub fn is_power_of_two(mut n: i32) -> bool
    {
        let mut set_bits: i32=0;

        while n > 0
        {
            let right_most_bit: i32=n & 1;

            if right_most_bit==1
            {
                set_bits+=1;
            }

            n=n >> 1;
        }

        set_bits==1
    }
}