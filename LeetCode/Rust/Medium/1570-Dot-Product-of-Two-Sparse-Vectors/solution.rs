use std::collections::{HashMap};

struct SparseVector
{
	non_zero_hashmap: HashMap<usize, i32>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SparseVector
{
    fn new(nums: Vec<i32>) -> Self
    {   
        let mut _non_zero_hashmap: HashMap<usize, i32>=nums.into_iter().enumerate().filter(|(index, number)| *number!=0).collect::<HashMap<usize, i32>>();

        Self
        {
            non_zero_hashmap: _non_zero_hashmap
        }
    }
	
    // Return the dotProduct of two sparse vectors
    fn dot_product(&self, vec: SparseVector) -> i32
    {
        let mut dot_product: i32=0;

        for (index, number) in self.non_zero_hashmap.iter()
        {
            match (vec.non_zero_hashmap.get(index))
            {
                Some(value) =>
                {
                    let product: i32=(*number) * value;

                    dot_product+=product;
                },
                None => ()
            }
        }

        dot_product
    }
}