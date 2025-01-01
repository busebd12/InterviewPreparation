class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head==None:
            return False

        if head.next==None:
            return False
        
        slow: ListNode=head

        fast: ListNode=slow.next

        while fast!=None and fast.next!=None:
            if slow==fast:
                return True

            slow=slow.next

            fast=fast.next.next

        return False