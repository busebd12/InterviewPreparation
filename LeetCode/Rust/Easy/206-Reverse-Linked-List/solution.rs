impl Solution
{
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        if head.is_none()
        {
            return head;
        }

        let head_box_node: &Box<ListNode>=head.as_ref().unwrap();

        if head_box_node.next.is_none()
        {
            return head;
        }

        let mut new_head: Option<Box<ListNode>>=None;

        let mut next_node: Option<Box<ListNode>>=None;

        let mut current: Option<Box<ListNode>>=head;

        while current.is_some()
        {
            let mut pointer: Box<ListNode>=current.unwrap();
            
            next_node=pointer.next.take();

            pointer.next=new_head.take();

            new_head=Some(pointer);

            current=next_node;
        }

        new_head
    }
}