use std::collections::{HashMap};

impl Solution
{
    pub fn frequencies_of_elements(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut result: Option<Box<ListNode>>=Some(Box::new(ListNode::new(-1)));

        let mut frequencies: HashMap<i32, i32>=HashMap::new();

        let mut current: &Option<Box<ListNode>>=&head;

        while let Some(node)=current
        {
            frequencies.entry(node.val).and_modify(|frequency| *frequency+=1).or_insert(1);

            current=&node.next;
        }

        let mut current=&mut result;

        for frequency in frequencies.values()
        {
            let next_node: Option<Box<ListNode>>=Some(Box::new(ListNode::new(*frequency)));
            
            current.as_mut().unwrap().next=next_node;

            current=&mut current.as_mut().unwrap().next;
        }

        result.unwrap().next
    }
}

impl Solution
{
    pub fn frequencies_of_elements(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut result: Option<Box<ListNode>>=Some(Box::new(ListNode::new(-1)));

        let max_value: usize=usize::pow(10, 5);

        let mut frequencies: Vec<i32>=vec![0; max_value + 1];

        let mut current: &Option<Box<ListNode>>=&head;

        while let Some(node)=current
        {
            frequencies[node.val as usize]+=1;

            current=&node.next;
        }

        let mut current=&mut result;

        for number in 1..max_value+1
        {
            let frequency: i32=frequencies[number as usize];

            if frequency > 0
            {
                let next_node: Option<Box<ListNode>>=Some(Box::new(ListNode::new(frequency)));
            
                current.as_mut().unwrap().next=next_node;

                current=&mut current.as_mut().unwrap().next;
            }
        }

        result.unwrap().next
    }
}