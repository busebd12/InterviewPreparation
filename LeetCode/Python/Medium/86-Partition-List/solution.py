class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if head==None:
            return head

        result: ListNode=ListNode(-1)

        less_than: ListNode=ListNode(-1)

        less_than_iterator: ListNode=less_than

        current: ListNode=head

        while current is not None:
            if current.val < x:
                less_than_iterator.next=ListNode(current.val)

                less_than_iterator=less_than_iterator.next

            current=current.next

        greater_than_or_equal_to: ListNode=ListNode(-1)

        greater_than_or_equal_to_iterator: ListNode=greater_than_or_equal_to

        current=head

        while current is not None:
            if current.val >= x:
                greater_than_or_equal_to_iterator.next=ListNode(current.val)

                greater_than_or_equal_to_iterator=greater_than_or_equal_to_iterator.next
            
            current=current.next

        result_iterator: ListNode=result

        current=less_than.next

        while current is not None:
            result_iterator.next=ListNode(current.val)

            result_iterator=result_iterator.next

            current=current.next

        current=greater_than_or_equal_to.next

        while current is not None:
            result_iterator.next=ListNode(current.val)

            result_iterator=result_iterator.next

            current=current.next

        return result.next