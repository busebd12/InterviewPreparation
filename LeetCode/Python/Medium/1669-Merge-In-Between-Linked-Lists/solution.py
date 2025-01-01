class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        first=list1

        for iteration in range(0, a-1):
            first=first.next

        second=list1

        for iteration in range(0, b + 1):
            second=second.next

        list2_pointer=list2

        while list2_pointer.next!=None:
            list2_pointer=list2_pointer.next

        first.next=list2

        list2_pointer.next=second

        return list1