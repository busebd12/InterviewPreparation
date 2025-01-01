class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result=ListNode(-1)

        max_value=10**5

        frequencies=[0 for _ in range(0, max_value + 1)]

        current=head

        while current:
            frequencies[current.val]+=1

            current=current.next

        current=result

        for number in range(1, max_value + 1):
            if frequencies[number] > 0:
                current.next=ListNode(frequencies[number])

                current=current.next

        return result.next

class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result=ListNode(-1)

        frequencies=dict()

        current=head

        while current:
            if current.val not in frequencies.keys():
                frequencies[current.val]=0
            
            frequencies[current.val]+=1

            current=current.next

        current=result

        for frequency in frequencies.values():
            current.next=ListNode(frequency)

            current=current.next

        return result.next