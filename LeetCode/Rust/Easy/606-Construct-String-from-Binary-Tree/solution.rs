use std::rc::Rc;
use std::cell::RefCell;
type OptionNode=Option<Rc<RefCell<TreeNode>>>;
impl Solution
{
    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String
    {
        let mut result:String=Self::helper(&root);

        result
    }

    pub fn helper(root: &OptionNode) -> String
    {
        if root.is_none()
        {
            return String::new();
        }

        let node: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        let root_string: String=node.borrow().val.to_string();

        let left_subtree_string: String=Self::helper(&node.borrow().left);

        let right_subtree_string: String=Self::helper(&node.borrow().right);

        if !left_subtree_string.is_empty() && !right_subtree_string.is_empty()
        {
            return format!("{}({})({})", root_string, left_subtree_string, right_subtree_string);
        }
        else if !left_subtree_string.is_empty() && right_subtree_string.is_empty()
        {
            return format!("{}({})",root_string, left_subtree_string);
        }
        else if left_subtree_string.is_empty() && !right_subtree_string.is_empty()
        {
            return format!("{}()({})", root_string, right_subtree_string);
        }

        root_string
    }
}