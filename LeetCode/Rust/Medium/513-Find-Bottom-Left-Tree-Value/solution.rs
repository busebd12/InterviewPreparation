use std::collections::{VecDeque};
use std::cmp;
use std::rc::Rc;
use std::cell::{Ref, RefCell};
impl Solution
{
    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result=-1;

        let height: i32=Self::get_height(&root);

        result=Self::get_leftmost_node_in_bottom_row(&root, height);

        result
    }

    fn get_height(root: &Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        if root.is_none()
        {
            return 0;
        }

        let root_reference_counter: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        let root_ref: Ref<'_, TreeNode>=root_reference_counter.borrow();

        let left_subtree_height: i32=Self::get_height(&root_ref.left);

        let right_subtree_height: i32=Self::get_height(&root_ref.right);

        1 + std::cmp::max(left_subtree_height, right_subtree_height)
    }

    fn get_leftmost_node_in_bottom_row(root: &Option<Rc<RefCell<TreeNode>>>, last_level: i32) -> i32
    {
        let mut leftmost_node: i32=-1;

        let mut queue: VecDeque<Rc<RefCell<TreeNode>>>=VecDeque::new();

        queue.push_back(Rc::clone(root.as_ref().unwrap()));

        let mut level: i32=1;

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some(node)=queue.pop_front()
                {
                    let node_ref: Ref<'_, TreeNode>=node.borrow();

                    if iteration==0 && level==last_level
                    {
                        leftmost_node=node_ref.val;

                        break;
                    }

                    if node_ref.left.is_some()
                    {
                        queue.push_back(Rc::clone(node_ref.left.as_ref().unwrap()));
                    }

                    if node_ref.right.is_some()
                    {
                        queue.push_back(Rc::clone(node_ref.right.as_ref().unwrap()));
                    }
                }
            }

            if !queue.is_empty()
            {
                level+=1;
            }
        }

        leftmost_node
    }
}