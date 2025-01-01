use std::collections::{HashMap, VecDeque};
use std::rc::Rc;
use std::cell::{RefCell, RefMut};
type OptionNode=Option<Rc<RefCell<TreeNode>>>;

impl Solution
{
    pub fn amount_of_time(root: Option<Rc<RefCell<TreeNode>>>, start: i32) -> i32
    {
        let mut result: i32=0;

        let hashmap: HashMap<i32, Vec<i32>>=Self::build_hashmap(root, start);

        result=Self::bfs(&hashmap, start);

        result
    }

    fn build_hashmap(root: OptionNode, start: i32) -> HashMap<i32, Vec<i32>>
    {
        let mut hashmap: HashMap<i32, Vec<i32>>=HashMap::new();

        let mut queue: VecDeque<Rc<RefCell<TreeNode>>>=VecDeque::new();

        queue.push_back(root.unwrap());

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                let reference_counter: Rc<RefCell<TreeNode>>=queue.pop_front().unwrap();

                let mut parent: RefMut<'_, TreeNode>=reference_counter.borrow_mut();

                if !hashmap.contains_key(&parent.val)
                {
                    hashmap.insert(parent.val, vec![]);
                }

                if parent.left.is_some()
                {
                    let left_node_value: i32=parent.left.as_mut().unwrap().borrow().val;
                    
                    hashmap.entry(parent.val).or_insert(vec![]).push(left_node_value);
                    
                    if !hashmap.contains_key(&left_node_value)
                    {
                        hashmap.insert(left_node_value, vec![]);
                    }

                    hashmap.entry(left_node_value).or_insert(vec![]).push(parent.val);

                    queue.push_back(parent.left.take().unwrap());
                }

                if parent.right.is_some()
                {
                    let right_node_value: i32=parent.right.as_mut().unwrap().borrow().val;
                    
                    hashmap.entry(parent.val).or_insert(vec![]).push(right_node_value);
                    
                    if !hashmap.contains_key(&right_node_value)
                    {
                        hashmap.insert(right_node_value, vec![]);
                    }

                    hashmap.entry(right_node_value).or_insert(vec![]).push(parent.val);

                    queue.push_back(parent.right.take().unwrap());
                }
            }
        }

        hashmap
    }

    fn bfs(hashmap: &HashMap<i32, Vec<i32>>, start: i32) -> i32
    {
        let mut total_time: i32=0;

        let limit: usize=usize::pow(10, 5) + 1;

        let mut visited: Vec<bool>=vec![false; limit];

        let mut queue: VecDeque<i32>=VecDeque::new();

        visited[start as usize]=true;

        queue.push_back(start);

        while !queue.is_empty()
        {
            let q_size: usize=queue.len();

            for iteration in 0..q_size
            {
                let node: i32=queue.pop_front().unwrap();

                for neighbour in hashmap.get(&node).unwrap()
                {
                    if !visited[*neighbour as usize]
                    {
                        visited[*neighbour as usize]=true;

                        queue.push_back(*neighbour);
                    }
                }
            }

            if !queue.is_empty()
            {
                total_time+=1;
            }
        }

        total_time
    }
}