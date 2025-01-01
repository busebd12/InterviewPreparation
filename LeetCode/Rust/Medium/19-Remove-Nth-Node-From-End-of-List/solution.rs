// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution
{
    pub fn remove_nth_from_end(mut head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>>
    {
        if head.is_none()
        {
            return head;
        }

        let length: usize=Self::get_length(&head);
        
        if n==(length as i32)
        {
            head=head.unwrap().next;

            return head;
        }

        let mut current: &mut Option<Box<ListNode>>=&mut head;

        let removal_position: usize=length - (n as usize);

        let target_position: usize=removal_position - 1;

        for iteration in 0..target_position
        {
            if let Some(node)=current
            {
                current=&mut node.next;
            }
        }

        if let Some(node)=current
        {
            node.next=node.next.take().unwrap().next;
        }
        
        head
    }

    fn get_length(head: &Option<Box<ListNode>>) -> usize
    {
        let mut length: usize=0;

        let mut current: &Option<Box<ListNode>>=head;

        while let Some(node)=current
        {   
            length+=1;

            current=&node.next;
        }

        length
    }
}