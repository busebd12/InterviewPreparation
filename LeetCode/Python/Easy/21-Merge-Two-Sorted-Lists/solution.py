class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        result: ListNode=None

        current: ListNode=ListNode()

        result=current

        pointer1: ListNode=list1

        pointer2: ListNode=list2

        while pointer1 is not None and pointer2 is not None:
            if pointer1.val <= pointer2.val:
                current.next=ListNode(pointer1.val, None)

                pointer1=pointer1.next
            else:
                current.next=ListNode(pointer2.val, None)

                pointer2=pointer2.next

            current=current.next

        while pointer1 is not None:
            current.next=ListNode(pointer1.val, None)

            pointer1=pointer1.next

            current=current.next

        while pointer2 is not None:
            current.next=ListNode(pointer2.val, None)

            pointer2=pointer2.next

            current=current.next

        return result.next