use std::rc::Rc;
use std::cell::RefCell;
use std::cell::RefMut;
type OptionNode=Option<Rc<RefCell<TreeNode>>>;

impl Solution
{
    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool
    {
        let mut tree1_leaf_nodes: Vec<i32>=Vec::new();

        Self::get_leaf_nodes(&root1, &mut tree1_leaf_nodes);

        let mut tree2_leaf_nodes: Vec<i32>=Vec::new();

        Self::get_leaf_nodes(&root2, &mut tree2_leaf_nodes);

        tree1_leaf_nodes==tree2_leaf_nodes
    }

    fn get_leaf_nodes(root: &OptionNode, leaf_nodes: &mut Vec<i32>)
    {
        if root.is_none()
        {
            return;
        }

        let node: &Rc<RefCell<TreeNode>>=root.as_ref().unwrap();

        let node_val: i32=node.borrow().val;

        if node.borrow().left.is_none() && node.borrow().right.is_none()
        {
            leaf_nodes.push(node_val);
        }

        Self::get_leaf_nodes(&node.borrow().left, leaf_nodes);

        Self::get_leaf_nodes(&node.borrow().right, leaf_nodes);
    }
}

impl Solution
{
    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool
    {
        let mut tree1_leaf_nodes: Vec<i32>=Vec::new();

        Self::get_leaf_nodes(root1, &mut tree1_leaf_nodes);

        let mut tree2_leaf_nodes: Vec<i32>=Vec::new();

        Self::get_leaf_nodes(root2, &mut tree2_leaf_nodes);

        tree1_leaf_nodes==tree2_leaf_nodes
    }

    fn get_leaf_nodes(root: OptionNode, leaf_nodes: &mut Vec<i32>) -> ()
    {
        if root.is_none()
        {
            return;
        }

        let mut stack: Vec<Rc<RefCell<TreeNode>>>=Vec::new();

        stack.push(root.unwrap());

        while !stack.is_empty()
        {
            let mut reference_counter: Rc<RefCell<TreeNode>>=stack.pop().unwrap();

            let mut node: RefMut<'_, TreeNode>=reference_counter.borrow_mut();

            let mut is_leaf: bool=true;

            if node.right.is_some()
            {
                is_leaf=false;

                stack.push(node.right.take().unwrap());
            }

            if node.left.is_some()
            {
                is_leaf=false;

                stack.push(node.left.take().unwrap());
            }

            if is_leaf
            {
                leaf_nodes.push(node.val);
            }
        }
    }
}