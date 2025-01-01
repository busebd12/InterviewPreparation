use std::collections::{VecDeque};

impl Solution
{
    pub fn count_students(mut students: Vec<i32>, mut sandwiches: Vec<i32>) -> i32
    {
        let mut stack: Vec<i32>=sandwiches.clone();

        stack.reverse();

        let mut queue: VecDeque<i32>=students.clone().into_iter().collect::<VecDeque<i32>>();

        while !stack.is_empty()
        {
            let mut students_ate: bool=false;

            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some(student)=queue.pop_front()
                {
                    if (*stack.last().unwrap())==student
                    {
                        students_ate=true;

                        stack.pop();
                    }
                    else
                    {
                        queue.push_back(student);
                    }
                }
            }

            if !students_ate
            {
                break;
            }
        }

        queue.len() as i32
    }
}