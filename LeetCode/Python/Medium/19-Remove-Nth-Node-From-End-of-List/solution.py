class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return head

        length=self.get_length(head)

        if n==length:
            head=head.next

            return head

        current=head

        removal_position=length - n

        target_position=removal_position - 1

        for iteration in range(0, target_position):
            current=current.next

        current.next=current.next.next

        return head

    def get_length(self, head: Optional[TreeNode]) -> int:
        length=0

        current=head

        while current:
            length+=1

            current=current.next

        return length