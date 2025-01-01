impl Solution
{
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut result: Option<Box<ListNode>>=None;

        let length: usize=Self::get_length(&head);

        let middle: usize=length / 2;

        let mut current: &Option<Box<ListNode>>=&head;

        for iteration in 0..middle
        {
            current=&current.as_ref().unwrap().next;
        }

        result=current.clone();

        result
    }

    fn get_length(head: &Option<Box<ListNode>>) -> usize
    {
        let mut length: usize=0;

        let mut current: &Option<Box<ListNode>>=head;

        while current.is_some()
        {
            length+=1;

            current=&current.as_ref().unwrap().next;
        }

        length
    }
}