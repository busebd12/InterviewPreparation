use std::collections::{HashSet};

impl Solution
{
    pub fn remove_zero_sum_sublists(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut hashset: HashSet<i32>=HashSet::from([0]);

        let mut stack: Vec<i32>=Vec::new();

        let mut prefix_sum: i32=0;

        let mut current: &Option<Box<ListNode>>=&head;

        while let Some(node)=current
        {
            stack.push(node.val);

            prefix_sum+=node.val;

            if hashset.contains(&prefix_sum)
            {
                let previous_prefix_sum: i32=prefix_sum;

                while let Some(number)=stack.pop()
                {
                    hashset.remove(&prefix_sum);

                    prefix_sum-=number;

                    if prefix_sum==previous_prefix_sum
                    {
                        break;
                    }
                }
            }

            hashset.insert(prefix_sum);

            current=&node.next;
        }

        let mut result: Box<ListNode>=Box::new(ListNode::new(-1));

        let mut current: &mut Box<ListNode>=&mut result;

        for number in stack.iter()
        {
            current.next=Some(Box::new(ListNode::new(*number)));

            current=current.next.as_mut().unwrap();
        }

        result.next
    }
}