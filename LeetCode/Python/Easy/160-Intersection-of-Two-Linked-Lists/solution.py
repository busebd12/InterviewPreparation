class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        result: Optional[ListNode]=None

        headA_length: int=self.get_length(headA)

        headB_length: int=self.get_length(headB)

        difference: int=abs(headA_length - headB_length)

        node1: Optional[ListNode]=headA

        node2: Optional[ListNode]=headB

        if headA_length < headB_length:
            for iteration in range(0, difference):
                node2=node2.next
        elif headA_length > headB_length:
            for iteration in range(0, difference):
                node1=node1.next

        while node1 and node2 and node1!=node2:
            node1=node1.next

            node2=node2.next

        result=node1

        return result

    def get_length(self, root: Optional[ListNode]) -> int:
        length: int=0
        
        current: Optional[ListNode]=root

        while current:
            length+=1

            current=current.next

        return length