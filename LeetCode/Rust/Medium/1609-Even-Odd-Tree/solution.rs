use std::collections::{VecDeque};
use std::rc::Rc;
use std::cell::{Ref, RefCell};
impl Solution
{
    pub fn is_even_odd_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool
    {
        let mut queue: VecDeque<(Rc<RefCell<TreeNode>>, i32)>=VecDeque::new();

        queue.push_back((Rc::clone(root.as_ref().unwrap()), 0));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            let mut previous: i32=-1;

            for iteration in 0..q_size
            {
                if let Some((node_reference_counter, level))=queue.pop_front()
                {
                    let node: Ref<'_, TreeNode>=node_reference_counter.borrow();

                    let is_valid: bool=Self::is_valid_node(node.val, level, &mut previous);

                    if !is_valid
                    {
                        return false;
                    }

                    if node.left.is_some()
                    {
                        queue.push_back((Rc::clone(node.left.as_ref().unwrap()), level + 1));
                    }

                    if node.right.is_some()
                    {
                        queue.push_back((Rc::clone(node.right.as_ref().unwrap()), level + 1));
                    }
                }
            }
        }

        true
    }

    fn is_valid_node(node_val: i32, level: i32, previous: &mut i32) -> bool
    {
        if level % 2 == 0
        {
            if node_val % 2 == 0
            {
                *previous=-1;

                return false;
            }

            if *previous==-1
            {
                *previous=node_val;
            }
            else
            {
                if node_val <= *previous
                {
                    *previous=-1;

                    return false;
                }

                *previous=node_val;
            }
        }
        else
        {
            if node_val % 2 == 1
            {
                *previous=-1;

                return false;
            }

            if *previous==-1
            {
                *previous=node_val;
            }
            else
            {
                if node_val >= *previous
                {
                    *previous=-1;

                    return false;
                }

                *previous=node_val;
            }     
        }

        true
    }
}