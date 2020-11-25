class ListNode
{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

/*
    Solution: we use the merge sort algorithm to merge the two lists together as we iterate through the two lists to create the new, merged list.
    The only bookeeping item to be aware of is in the situation where the two lists are not the same size. After iterating over the shortest list,
    we need to attach the remainder of the longer list to the new, merged list.

    Time complexity: O(min(m, n)) [where m is the length of the first list and n is the length of the second list]
    Space complexity: O(m + n);
*/

class Solution
{
    public ListNode mergeTwoLists(ListNode l1, ListNode l2)
    {
        if(l1==null && l2==null)
        {
            return null;
        }
        
        if(l1==null)
        {
            return l2;
        }
        
        if(l2==null)
        {
            return l1;
        }
        
        ListNode current=new ListNode(0, null);
        
        ListNode merged=current;
        
        while(l1!=null && l2!=null)
        {
            if(l1.val < l2.val)
            {
                current.next=l1;
                
                l1=l1.next;
            }
            else
            {
                current.next=l2;
                
                l2=l2.next;
            }
            
            current=current.next;
        }
        
        if(l1!=null)
        {
            current.next=l1;
        }
        else
        {
            current.next=l2;
        }
        
        return merged.next;
    }
}