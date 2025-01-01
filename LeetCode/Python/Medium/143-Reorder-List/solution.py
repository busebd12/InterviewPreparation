class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        nodes=list()

        current=head

        while current:
            nodes.append(current)

            current=current.next

        length=len(nodes)

        low=1

        high=length-1

        current=head

        while low <= high:
            current.next=nodes[high]

            high-=1

            current=current.next

            current.next=nodes[low]

            current=current.next

            low+=1

        current.next=None