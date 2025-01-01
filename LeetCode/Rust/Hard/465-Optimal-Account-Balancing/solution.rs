use std::collections::{HashMap};
use std::cmp;

impl Solution
{
    pub fn min_transfers(transactions: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        let mut hashmap: HashMap<i32, i32>=HashMap::new();

        for transaction in transactions.iter()
        {
            let person_giving_money: i32=transaction[0];

            let person_receiving_money: i32=transaction[1];

            let amount: i32=transaction[2];

            if !hashmap.contains_key(&person_giving_money)
            {
                hashmap.insert(person_giving_money, 0);
            }

            hashmap.entry(person_giving_money).and_modify(|balance| *balance-=amount);

            if !hashmap.contains_key(&person_receiving_money)
            {
                hashmap.insert(person_receiving_money, 0);
            }

            hashmap.entry(person_receiving_money).and_modify(|balance| *balance+=amount);
        }

        let mut debt_amounts: Vec<i32>=Vec::new();

        for balance in hashmap.values()
        {
            if *balance!=0
            {
                debt_amounts.push(*balance);
            }   
        }

        let d: usize=debt_amounts.len();

        let mut person: usize=0;

        result=Self::helper(&mut debt_amounts, d, person);

        result
    }

    fn helper(debt_amounts: &mut Vec<i32>, d: usize, person: usize) -> i32
    {
        if person==d
        {
            return 0;
        }

        if debt_amounts[person]==0
        {
            return Self::helper(debt_amounts, d, person + 1);
        }

        let mut subproblem_solution: i32=i32::MAX;

        for other_person in person+1..d
        {
            if debt_amounts[person] * debt_amounts[other_person] < 0
            {
                debt_amounts[other_person]+=debt_amounts[person];

                subproblem_solution=std::cmp::min(subproblem_solution, 1 + Self::helper(debt_amounts, d, person + 1));

                debt_amounts[other_person]-=debt_amounts[person];
            }
        }

        subproblem_solution
    }
}