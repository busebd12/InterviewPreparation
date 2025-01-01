use std::rc::Rc;
use std::cell::Ref;
use std::cell::RefCell;
impl Solution
{
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool
    {
        Self::helper(&p, &q)
    }

    fn helper(p: &Option<Rc<RefCell<TreeNode>>>, q: &Option<Rc<RefCell<TreeNode>>>) -> bool
    {
        if p.is_none() && q.is_none()
        {
            return true;
        }

        if p.is_none() || q.is_none()
        {
            return false;
        }

        let p_rc: &Rc<RefCell<TreeNode>>=p.as_ref().unwrap();

        let q_rc: &Rc<RefCell<TreeNode>>=q.as_ref().unwrap();

        let p_node: Ref<'_, TreeNode>=p_rc.borrow();

        let q_node: Ref<'_, TreeNode>=q_rc.borrow();

        p_node.val==q_node.val && Self::helper(&p_node.left, &q_node.left) && Self::helper(&p_node.right, &q_node.right)
    }
}