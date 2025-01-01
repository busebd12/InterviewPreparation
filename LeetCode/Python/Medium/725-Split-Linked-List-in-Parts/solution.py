class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        result: List[Optional[ListNode]]=list()

        n: int=self.get_length(head)

        initial_bucket_amount: int=n // k

        left_over: int=n % k

        buckets: List[int]=[initial_bucket_amount] * k

        for index in range(0, left_over):
            buckets[index]+=1

        current: Optional[ListNode]=head

        for index in range(0, k):
            part: ListNode=ListNode()

            walker: ListNode=part

            nodes_to_add: int=buckets[index]

            for count in range(0, nodes_to_add):
                walker.next=ListNode(current.val)

                current=current.next

                walker=walker.next

            result.append(part.next)

        return result

    def get_length(self, head: Optional[ListNode]) -> int:
        length: int=0

        current: Optional[ListNode]=head

        while current:
            length+=1

            current=current.next

        return length