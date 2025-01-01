use std::rc::Rc;
use std::cell::RefCell;
type OptionNode=Option<Rc<RefCell<TreeNode>>>;

impl Solution
{
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        Self::helper(&mut result, &root);

        result
    }

    pub fn helper(result: &mut Vec<i32>, root: &OptionNode)
    {
        if let Some(node)=root
        {
            let borrowed_root: std::cell::Ref<TreeNode>=node.borrow();

            Self::helper(result, &borrowed_root.left);

            result.push(borrowed_root.val);

            Self::helper(result, &borrowed_root.right);
        }
    }
}

impl Solution
{
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        Self::helper(&mut result, &root);

        result
    }

    pub fn helper(result: &mut Vec<i32>, root: &OptionNode) -> ()
    {
        if root.is_none()
        {
            return ();
        }

        let node: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        Self::helper(result, &node.borrow().left);

        result.push(node.borrow().val);

        Self::helper(result, &node.borrow().right);
    }
}

impl Solution
{
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>
    {
        let mut result: Vec<i32>=Vec::new();

        let mut stack: Vec<OptionNode>=Vec::new();

        let mut current: OptionNode=root;

        while !stack.is_empty() || current.is_some()
        {
            while let Some(node)=current
            {
                current=node.borrow().left.clone();
                
                stack.push(Some(node));
            }

            let node: OptionNode=stack.pop().unwrap();

            result.push(node.as_ref().unwrap().borrow().val);

            current=node.unwrap().borrow().right.clone();
        }

        result
    }
}