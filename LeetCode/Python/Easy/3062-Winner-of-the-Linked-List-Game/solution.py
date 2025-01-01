class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        result="Tie"

        even_score=0

        odd_score=0

        current=head

        while current and current.next:
            if current.val > current.next.val:
                even_score+=1
            elif current.next.val > current.val:
                odd_score+=1

            current=current.next.next

        if odd_score!=even_score:
            result="Odd" if odd_score > even_score else "Even"

        return result