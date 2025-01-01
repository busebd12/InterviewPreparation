use std::rc::Rc;
use std::cell::{Ref, RefCell};
use std::collections::{VecDeque};
impl Solution
{
    pub fn get_lonely_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let mut queue: VecDeque<Option<Rc<RefCell<TreeNode>>>>=VecDeque::new();

        queue.push_back(root.clone());

        while let Some(parent)=queue.pop_back()
        {
            let parent_rc: &Rc<RefCell<TreeNode>>=parent.as_ref().unwrap();

            let parent_node: Ref<'_, TreeNode>=parent_rc.borrow();

            if parent_node.left.is_some() && parent_node.right.is_none()
            {
                result.push(parent_node.left.as_ref().unwrap().borrow().val);

                queue.push_back(parent_node.left.clone());
            }
            else if parent_node.left.is_none() && parent_node.right.is_some()
            {
                result.push(parent_node.right.as_ref().unwrap().borrow().val);

                queue.push_back(parent_node.right.clone());
            }
            else if parent_node.left.is_some() && parent_node.right.is_some()
            {
                queue.push_back(parent_node.left.clone());

                queue.push_back(parent_node.right.clone());
            }
        }

        result
    }
}

impl Solution
{
    pub fn get_lonely_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let mut queue: VecDeque<Option<Rc<RefCell<TreeNode>>>>=VecDeque::new();

        queue.push_back(root);

        while let Some(parent)=queue.pop_back()
        {
            let parent_rc: &Rc<RefCell<TreeNode>>=parent.as_ref().unwrap();

            let parent_node: Ref<'_, TreeNode>=parent_rc.borrow();

            match (parent_node.left.clone(), parent_node.right.clone())
            {
                (Some(left_child), None) =>
                {
                    result.push(left_child.borrow().val);

                    queue.push_back(Some(left_child));
                },
                (None, Some(right_child)) =>
                {
                    result.push(right_child.borrow().val);

                    queue.push_back(Some(right_child));
                },
                (Some(left_child), Some(right_child)) =>
                {
                    queue.push_back(Some(left_child));

                    queue.push_back(Some(right_child));
                }
                _ => ()
            }
        }

        result
    }
}