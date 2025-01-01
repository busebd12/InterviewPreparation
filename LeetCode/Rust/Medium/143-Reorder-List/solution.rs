use std::collections::{VecDeque};

impl Solution
{
    pub fn reorder_list(mut head: &mut Option<Box<ListNode>>)
    {
        let mut values: VecDeque<i32>=VecDeque::new();

        let mut current: Option<&Box<ListNode>>=head.as_ref();

        while let Some(node)=current
        {
            values.push_back(node.val);

            current=node.next.as_ref();
        }

        let mut index: i32=0;

        let mut current: Option<&mut Box<ListNode>>=head.as_mut();

        while let Some(node)=current
        {
            match (index % 2)==0
            {
                true =>
                {
                    node.val=values.pop_front().unwrap()
                },
                false =>
                {
                    node.val=values.pop_back().unwrap()
                }
            };

            current=node.next.as_mut();

            index+=1;
        }
    }
}