class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or not head.next or left==right:
            return head
        
        dummy: ListNode=ListNode(-1)

        dummy.next=head

        before_left: ListNode=dummy

        for iteration in range(0, left-1):
            before_left=before_left.next

        left_node: ListNode=before_left.next

        operations: int=right - left

        for iteration in range(0, operations):
            saved: ListNode=before_left.next

            before_left.next=left_node.next

            left_node.next=left_node.next.next

            before_left.next.next=saved

        return dummy.next