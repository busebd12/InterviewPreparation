use std::rc::Rc;
use std::cell::RefCell;
type OptionNode=Option<Rc<RefCell<TreeNode>>>;

impl Solution
{
    pub fn maximum_average_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> f64
    {
        let mut result: f64=0.0;

        Self::helper(&root, &mut result);

        result
    }

    pub fn helper(root: &OptionNode, result: &mut f64) -> (u32, u32)
    {
        if let Some(node)=root
        {
            let mut nodes_in_subtree: u32=1;

            let left_subtree_tuple: (u32, u32)=Self::helper(&node.borrow().left.clone(), result);

            let right_subtree_tuple: (u32, u32)=Self::helper(&node.borrow().right.clone(), result);

            let left_subtree_nodes: u32=left_subtree_tuple.0;

            let left_subtree_total: u32=left_subtree_tuple.1;

            let right_subtree_nodes: u32=right_subtree_tuple.0;

            let right_subtree_total: u32=right_subtree_tuple.1;

            nodes_in_subtree+=left_subtree_nodes;

            nodes_in_subtree+=right_subtree_nodes;

            let subtree_total: u32=node.borrow().val as u32 + left_subtree_total + right_subtree_total;

            let subtree_average: f64=(subtree_total as f64 / nodes_in_subtree as f64);

            *result=f64::max(*result, subtree_average);

            (nodes_in_subtree, subtree_total)
        }
        else
        {
            (0, 0)
        }
    }
}

impl Solution
{
    pub fn maximum_average_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> f64
    {
        let mut result: f64=0.0;

        Self::helper(&root, &mut result);

        result
    }

    pub fn helper(root: &OptionNode, result: &mut f64) -> (u32, u32)
    {
        if root.is_none()
        {
            return (0, 0);
        }

        let node: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();
        
        let mut nodes_in_subtree: u32=1;

        let left_subtree_tuple: (u32, u32)=Self::helper(&node.borrow().left, result);

        let right_subtree_tuple: (u32, u32)=Self::helper(&node.borrow().right, result);

        let left_subtree_nodes: u32=left_subtree_tuple.0;

        let left_subtree_total: u32=left_subtree_tuple.1;

        let right_subtree_nodes: u32=right_subtree_tuple.0;

        let right_subtree_total: u32=right_subtree_tuple.1;

        nodes_in_subtree+=left_subtree_nodes;

        nodes_in_subtree+=right_subtree_nodes;

        let subtree_total: u32=node.borrow().val as u32 + left_subtree_total + right_subtree_total;

        let subtree_average: f64=(subtree_total as f64 / nodes_in_subtree as f64);

        *result=f64::max(*result, subtree_average);

        (nodes_in_subtree, subtree_total)
    }
}