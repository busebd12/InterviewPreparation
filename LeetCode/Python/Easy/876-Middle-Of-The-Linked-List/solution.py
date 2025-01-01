class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result: ListNode=None

        if head==None:
            return head

        length: int=self.get_length(head)

        middle: int=length // 2

        current: ListNode=head

        for count in range(0, middle):
            current=current.next

        result=current

        return result

    def get_length(self, head: Optional[ListNode]) -> int:
        length: int=0

        current: ListNode=head

        while current!=None:
            length+=1

            current=current.next

        return length