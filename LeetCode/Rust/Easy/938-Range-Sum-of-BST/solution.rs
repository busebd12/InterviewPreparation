use std::rc::Rc;
use std::cell::RefCell;
type OptionNode=Option<Rc<RefCell<TreeNode>>>;

impl Solution
{
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32
    {
        let mut result: i32=0;

        Self::helper(&root, &mut result, low, high);

        result
    }

    fn helper(root: &OptionNode, result: &mut i32, low: i32, high: i32) -> ()
    {
        if root.is_none()
        {
            return ();
        }

        let node: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        let node_val: i32=node.borrow().val;

        if low <= node_val && node_val <= high
        {
            *result+=node_val;

            Self::helper(&node.borrow().left, result, low, high);

            Self::helper(&node.borrow().right, result, low, high);
        }
        else if node_val < low
        {
            Self::helper(&node.borrow().right, result, low, high);
        }
        else if node_val > high
        {
            Self::helper(&node.borrow().left, result, low, high);
        }
    }
}