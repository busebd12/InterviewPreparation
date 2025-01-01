use std::collections::{HashMap, VecDeque};
use std::rc::Rc;
use std::cell::{Ref, RefCell};
impl Solution
{
    pub fn vertical_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        if root.is_none()
        {
            return result;
        }

        let (hashmap, min_column, max_column): (HashMap<i32, Vec<i32>>, i32, i32)=Self::build_hashmap(root);

        for column in (min_column..=max_column).rev()
        {
            let values: Vec<i32>=(*hashmap.get(&column).unwrap()).clone();

            result.push(values);
        }

        result
    }

    fn build_hashmap(root: Option<Rc<RefCell<TreeNode>>>) -> (HashMap<i32, Vec<i32>>, i32, i32)
    {
        let mut hashmap: HashMap<i32, Vec<i32>>=HashMap::new();

        let mut min_column: i32=i32::MAX;

        let mut max_column: i32=i32::MIN;

        let mut queue: VecDeque<(Rc<RefCell<TreeNode>>, i32)>=VecDeque::new();

        queue.push_back((Rc::clone(root.as_ref().unwrap()), 0));

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                if let Some((node_rc, column))=queue.pop_front()
                {
                    let node: Ref<'_, TreeNode>=node_rc.borrow();

                    if !hashmap.contains_key(&column)
                    {
                        hashmap.insert(column, Vec::new());
                    }

                    hashmap.entry(column).and_modify(|vector| vector.push(node.val));

                    min_column=std::cmp::min(min_column, column);

                    max_column=std::cmp::max(max_column, column);

                    if node.left.is_some()
                    {
                        queue.push_back((Rc::clone(node.left.as_ref().unwrap()), column + 1));
                    }

                    if node.right.is_some()
                    {
                        queue.push_back((Rc::clone(node.right.as_ref().unwrap()), column - 1));
                    }
                }
            }
        }

        (hashmap, min_column, max_column)
    }
}