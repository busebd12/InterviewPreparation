use std::rc::Rc;
use std::cell::{RefCell, RefMut};
type OptionNode=Option<Rc<RefCell<TreeNode>>>;

impl Solution
{
    pub fn max_ancestor_diff(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result: i32=0;

        Self::helper(root, &mut result);

        result
    }

    fn helper(root: OptionNode, result: &mut i32) -> (i32, i32)
    {
        if root.is_none()
        {
            return (i32::MAX, i32::MIN);
        }

        let reference_counter: Rc<RefCell<TreeNode>>=root.unwrap();

        let mut node: RefMut<'_, TreeNode>=reference_counter.borrow_mut();

        let mut left_subtree_tuple: (i32, i32)=Self::helper(node.left.take(), result);

        let mut left_subtree_min_value: i32=left_subtree_tuple.0;

        let mut left_subtree_max_value: i32=left_subtree_tuple.1;

        let mut right_subtree_tuple: (i32, i32)=Self::helper(node.right.take(), result);

        let mut right_subtree_min_value: i32=right_subtree_tuple.0;

        let mut right_subtree_max_value: i32=right_subtree_tuple.1;

        let mut current_subtree_min_value: i32=i32::min(node.val, i32::min(left_subtree_min_value, right_subtree_min_value));

        let mut current_subtree_max_value: i32=i32::max(node.val, i32::max(left_subtree_max_value, right_subtree_max_value));

        *result=i32::max(*result, i32::max((current_subtree_min_value - node.val).abs(), (current_subtree_max_value - node.val).abs()));

        (current_subtree_min_value, current_subtree_max_value)
    }
}