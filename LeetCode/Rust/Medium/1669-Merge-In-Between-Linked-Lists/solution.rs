use std::mem;

impl Solution
{
    pub fn merge_in_between(list1: Option<Box<ListNode>>, mut a: i32, mut b: i32, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut head=list1.unwrap();

        let mut current: &mut ListNode=head.as_mut();

        //Move current to the node right before the node at position a in list1
        for iteration in 0..(a-1)
        {
            current=current.next.as_mut().unwrap();
        }

        //After using mem::swap(), current.next will point to list2 and list2 will point to the remaining part of list1
        mem::swap(&mut current.next, &mut list2);

        //Move the end of list1
        //Because of the mem::swap() call above, we are iterating through the entirety of list2
        while current.next.is_some()
        {
            current=current.next.as_mut().unwrap();
        }

        //Number of list1 nodes between positions a and b inclusive
        let number_of_list1_nodes_to_skip: i32=(b - a) + 1;

        //Remember: because of the mem::swap() call, list2 is pointing to the remaining part of list1 starting at position a
        //The for loop will iterate through the list1 nodes in the range [a, b]
        for iteration in 0..number_of_list1_nodes_to_skip
        {
            list2=list2.unwrap().next;
        }

        //At this point, current is pointing to the last node in list1 which is the last node in list2
        //Doing current.next=list2 is setting the next pointer of the last node in list2 to point to the remaining portion of list1 after the node at position b
        current.next=list2;

        Some(head)
    }
}