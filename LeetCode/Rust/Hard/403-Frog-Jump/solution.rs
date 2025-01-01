use std::collections::{HashMap, HashSet};

impl Solution
{
    pub fn can_cross(stones: Vec<i32>) -> bool
    {
        let mut result: bool=false;

        let n: usize=stones.len();

        let valid_stones: HashSet<i32>=stones.clone().into_iter().collect::<HashSet<i32>>();

        let mut memo: HashMap<(i32, i32), bool>=HashMap::new();

        let last_stone: i32=stones[n - 1];

        let k: i32=0;

        let stone: i32=0;

        result=Self::helper(&valid_stones, &mut memo, k, last_stone, stone);

        result
    }

    fn helper(valid_stones: &HashSet<i32>, memo: &mut HashMap<(i32, i32), bool>, k: i32, last_stone: i32, stone: i32) -> bool
    {
        if stone==last_stone
        {
            return true;
        }

        if !valid_stones.contains(&stone)
        {
            return false;
        }

        let key: (i32, i32)=(stone, k);

        if memo.contains_key(&key)
        {
            return *memo.get(&key).unwrap();
        }

        let mut subproblem_solution: bool=false;

        for jump in k-1..k+2
        {
            if jump > 0
            {
                subproblem_solution=subproblem_solution || Self::helper(valid_stones, memo, jump, last_stone, stone + jump);
            }
        }

        memo.insert(key, subproblem_solution);

        subproblem_solution
    }
}

impl Solution
{
    pub fn can_cross(stones: Vec<i32>) -> bool
    {
        let mut result: bool=false;

        let n: usize=stones.len();

        let mut valid_stones: HashSet<i32>=HashSet::new();

        for stone in &stones
        {
            valid_stones.insert(*stone);
        }

        let mut memo: HashMap<(i32, i32), bool>=HashMap::new();

        let last_stone: i32=stones[n - 1];

        let k: i32=0;

        let stone: i32=0;

        result=Self::helper(&valid_stones, &mut memo, k, last_stone, stone);

        result
    }

    fn helper(valid_stones: &HashSet<i32>, memo: &mut HashMap<(i32, i32), bool>, k: i32, last_stone: i32, stone: i32) -> bool
    {
        if stone==last_stone
        {
            return true;
        }

        if !valid_stones.contains(&stone)
        {
            return false;
        }

        let key: (i32, i32)=(stone, k);

        if memo.contains_key(&key)
        {
            return *memo.get(&key).unwrap();
        }

        let mut subproblem_solution: bool=false;

        for jump in k-1..k+2
        {
            if jump > 0
            {
                subproblem_solution=subproblem_solution || Self::helper(valid_stones, memo, jump, last_stone, stone + jump);
            }
        }

        memo.insert(key, subproblem_solution);

        subproblem_solution
    }
}