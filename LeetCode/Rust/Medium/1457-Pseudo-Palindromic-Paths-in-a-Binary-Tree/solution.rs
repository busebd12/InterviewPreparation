use std::collections::{VecDeque};
use std::rc::Rc;
use std::cell::Ref;
use std::cell::RefCell;

impl Solution
{
    pub fn pseudo_palindromic_paths (root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        let mut queue: VecDeque<(Rc<RefCell<TreeNode>>, Vec<usize>)>=VecDeque::new();

        let mut hashmap: Vec<usize>=vec![0; 10];

        hashmap[root.unwrap().borrow().val]+=1;

        queue.push_back((root.unwrap(), hashmap));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for count in 0..q_size
            {
                let (node, current_hashmap)=queue.pop_front().unwrap();

                let node_ref=node.borrow();

                if node_ref.left.is_none() && node_ref.right.is_none()
                {
                    if Self::is_palindrome(&current_hashmap)
                    {
                        result+=1;
                    }
                }

                if node_ref.left.is_some()
                {
                    let mut left_child_hashmap: Vec<usize>=current_hashmap.clone();

                    left_child_hashmap[node_ref.left.unwrap().borrow().val]+=1;

                    queue.push_back((node_ref.left.clone(), left_child_hashmap));
                }

                if node_ref.right.is_some()
                {
                    let mut right_child_hashmap: Vec<usize>=current_hashmap.clone();

                    right_child_hashmap[node_ref.right.unwrap().borrow().val]+=1;

                    queue.push_back((node_ref.right.clone(), right_child_hashmap));
                }
            }
        }

        result
    }

    fn is_palindrome(hashmap: &Vec<usize>) -> bool
    {
        let mut odd_frequencies: usize=0;
        
        for digit in 0..10
        {
            let frequency: usize=hashmap[digit];
            
            if frequency % 2 == 1
            {
                odd_frequencies+=1;
            }

            if odd_frequencies > 1
            {
                return false;
            }
        }

        true
    }
}


impl Solution
{
    pub fn pseudo_palindromic_paths (root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        let mut queue: VecDeque<(Rc<RefCell<TreeNode>>, Vec<usize>)>=VecDeque::new();

        let mut hashmap: Vec<usize>=vec![0; 10];

        if let Some(root)=&root
        {
            hashmap[root.borrow().val as usize]+=1;

            queue.push_back((Rc::clone(root), hashmap));
        }

        while let Some((node, mut current_hashmap))=queue.pop_front()
        {
            let node_ref: Ref<'_, TreeNode>=node.borrow();

            if node_ref.left.is_none() && node_ref.right.is_none()
            {
                if Self::is_palindrome(&current_hashmap)
                {
                    result+=1;
                }
            }

            if let Some(left_child)=&node_ref.left
            {
                let left_child_value: usize=left_child.borrow().val as usize;

                current_hashmap[left_child_value]+=1;

                queue.push_back((Rc::clone(left_child), current_hashmap.clone()));

                current_hashmap[left_child_value]-=1;
            }

            if let Some(right_child)=&node_ref.right
            {
                let right_child_value: usize=right_child.borrow().val as usize;

                current_hashmap[right_child_value]+=1;

                queue.push_back((Rc::clone(right_child), current_hashmap.clone()));

                current_hashmap[right_child_value]-=1;
            }
        }

        result
    }

    fn is_palindrome(hashmap: &Vec<usize>) -> bool
    {
        let odd_frequencies: usize=(0..10).filter(|&digit| hashmap[digit] % 2 == 1).count();

        odd_frequencies <= 1
    }
}