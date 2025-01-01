use std::cmp;
use std::rc::Rc;
use std::cell::{Ref, RefCell};
impl Solution
{
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let mut result=0;

        Self::helper(&root, &mut result);

        result
    }

    fn helper(root: &Option<Rc<RefCell<TreeNode>>>, result: &mut i32) -> i32
    {
        if root.is_none()
        {
            return 0;
        }

        let root_rc: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        let node: Ref<'_, TreeNode>=root_rc.borrow();

        let left_subtree_path_length: i32=Self::helper(&node.left, result);

        let right_subtree_path_length: i32=Self::helper(&node.right, result);

        let path_length: i32=left_subtree_path_length + right_subtree_path_length;

        *result=std::cmp::max(*result, path_length);

        1 + std::cmp::max(left_subtree_path_length, right_subtree_path_length)
    }
}