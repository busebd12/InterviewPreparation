impl Solution
{
    pub fn number_of_beams(bank: Vec<String>) -> i32
    {
        let mut result: i32=0;

        let mut ones_in_previous_row: i32=0;

        for row in bank.iter()
        {
            let ones: i32=row.chars().filter(|&digit| digit=='1').count() as i32;

            if ones==0
            {
                continue;
            }

            let product: i32=ones * ones_in_previous_row;

            result+=product;

            ones_in_previous_row=ones;
        }

        result
    }
}