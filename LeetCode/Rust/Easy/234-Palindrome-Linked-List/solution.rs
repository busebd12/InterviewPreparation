impl Solution
{
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool
    {
        let mut stack: Vec<i32>=Vec::new();

        let length: usize=Solution::get_length(head.as_ref());

        let middle: usize=length / 2;

        let mut current: Option<&Box<ListNode>>=head.as_ref();

        for counter in 0..middle
        {
            stack.push(current.unwrap().val);

            current=current.unwrap().next.as_ref();
        }

        if length % 2 == 1
        {
            current=current.unwrap().next.as_ref();
        }

        while let Some(node)=current
        {
            let top: i32=stack.pop().unwrap();

            if top!=node.val
            {
                return false;
            }

            current=node.next.as_ref();
        }

        true
    }

    pub fn get_length(head: Option<&Box<ListNode>>) -> usize
    {
        let mut length: usize=0;

        let mut current: Option<&Box<ListNode>>=head;

        while let Some(node)=current
        {
            length+=1;

            current=node.next.as_ref();
        }

        length
    }
}