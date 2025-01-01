use std::rc::Rc;
use std::cell::{Ref, RefCell, RefMut};
impl Solution
{
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let (tree_flag, result): (bool, i32)=Solution::in_order_traversal(root.as_ref(), false);

        result
    }

    fn in_order_traversal(root: Option<&Rc<RefCell<TreeNode>>>, came_from_left: bool) -> (bool, i32)
    {
        match root
        {
            Some(root_rc) =>
            {
                let node: Ref<'_, TreeNode>=root_rc.borrow();

                if node.left.is_none() && node.right.is_none()
                {
                    if came_from_left
                    {
                        return (true, node.val);
                    }
                    else
                    {
                        return (false, 0);
                    }
                }

                let mut subtree_total: i32=0;

                let mut subtree_flag: bool=false;

                let (left_subtree_flag, left_subtree_total): (bool, i32)=Solution::in_order_traversal(node.left.as_ref(), true);

                let (right_subtree_flag, right_subtree_total): (bool, i32)=Solution::in_order_traversal(node.right.as_ref(), false);

                if left_subtree_flag
                {
                    subtree_total+=left_subtree_total;

                    subtree_flag=true;
                }

                if right_subtree_flag
                {
                    subtree_total+=right_subtree_total;

                    subtree_flag=true;
                }

                (subtree_flag, subtree_total)
            },
            None => (false, 0)
        }
    }
}

impl Solution
{
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        let mut stack: Vec<(Option<Rc<RefCell<TreeNode>>>, bool)>=Vec::new();

        stack.push((root, false));

        while let Some((parent_option, came_from_left))=stack.pop()
        {
            match parent_option
            {
                Some(parent_rc) =>
                {   
                    let mut parent: RefMut<'_, TreeNode>=parent_rc.borrow_mut();

                    match (parent.left.take(), parent.right.take())
                    {
                        (Some(left_child), Some(right_child)) =>
                        {
                            stack.push((Some(left_child), true));

                            stack.push((Some(right_child), false));
                        },
                        (Some(left_child), None) =>
                        {
                            stack.push((Some(left_child), true));
                        },
                        (None, Some(right_child)) =>
                        {
                            stack.push((Some(right_child), false));
                        },
                        (None, None) =>
                        {
                            if came_from_left
                            {
                                result+=parent.val;
                            }
                        },
                        _ => ()
                    }
                },
                None => continue
            }
        }

        result
    }
}

impl Solution
{
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        let mut stack: Vec<(Option<Rc<RefCell<TreeNode>>>, bool)>=Vec::new();

        stack.push((root, false));

        while let Some((parent_option, came_from_left))=stack.pop()
        {
            match parent_option
            {
                Some(parent_rc) =>
                {   
                    let parent: Ref<'_, TreeNode>=parent_rc.borrow();

                    match (parent.left.clone(), parent.right.clone())
                    {
                        (Some(left_child), Some(right_child)) =>
                        {
                            stack.push((parent.left.clone(), true));

                            stack.push((parent.right.clone(), false));
                        },
                        (Some(left_child), None) =>
                        {
                            stack.push((parent.left.clone(), true));
                        },
                        (None, Some(right_child)) =>
                        {
                            stack.push((parent.right.clone(), false));
                        },
                        (None, None) =>
                        {
                            if came_from_left
                            {
                                result+=parent.val;
                            }
                        },
                        _ => ()
                    }
                },
                None => continue
            }
        }

        result
    }
}