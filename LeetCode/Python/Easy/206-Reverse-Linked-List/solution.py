class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        
        new_head: ListNode=None

        current: ListNode=head

        next_node: ListNode=None

        while current!=None:
            next_node=current.next

            current.next=new_head

            new_head=current

            current=next_node

        return new_head