use std::rc::Rc;
use std::cell::{Ref, RefCell};

impl Solution
{
    pub fn equal_to_descendants(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        Self::helper(&root, &mut result);

        result
    }

    fn helper(root: &Option<Rc<RefCell<TreeNode>>>, result: &mut i32) -> i32
    {
        if root.is_none()
        {
            return 0;
        }

        let mut descendants_sum: i32=0;

        let reference_counter: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        let node: Ref<'_, TreeNode>=reference_counter.borrow();

        let left_subtree_sum: i32=Self::helper(&node.left, result);

        let right_subtree_sum: i32=Self::helper(&node.right, result);

        descendants_sum+=left_subtree_sum;

        descendants_sum+=right_subtree_sum;

        if descendants_sum==node.val
        {
            *result+=1;
        }

        let subtree_sum: i32=descendants_sum + node.val;

        subtree_sum
    }
}

impl Solution
{
    pub fn equal_to_descendants(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        Self::helper(&root, &mut result);

        result
    }

    fn helper(root: &Option<Rc<RefCell<TreeNode>>>, result: &mut i32) -> i32
    {
        match root
        {
            Some(root) =>
            {
                let mut descendants_sum: i32=0;

                let node: Ref<'_, TreeNode>=root.borrow();

                let left_subtree_sum: i32=Self::helper(&node.left, result);

                let right_subtree_sum: i32=Self::helper(&node.right, result);

                descendants_sum+=left_subtree_sum;

                descendants_sum+=right_subtree_sum;

                if descendants_sum==node.val
                {
                    *result+=1;
                }

                let subtree_sum: i32=descendants_sum + node.val;

                return subtree_sum;
            },
            None =>
            {
                return 0;
            }
        }
    }
}