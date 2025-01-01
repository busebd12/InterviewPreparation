from collections import deque

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result: ListNode=None

        l1_values: list[int]=self.generate_list(l1)

        l2_values: list[int]=self.generate_list(l2)

        sum_values: deque[int]=self.do_addition(l1_values, l2_values)

        result=self.build_linked_list(sum_values)

        return result.next

    def generate_list(self, head: Optional[ListNode]) -> list[int]:
        values: list[int]=list()

        current: Optional[ListNode]=head

        while current:
            values.append(current.val)

            current=current.next

        return values

    def do_addition(self, l1_values: list[int], l2_values: list[int]) -> deque[int]:
        sum_values: deque[int]=deque()

        carry: int=0

        while l1_values or l2_values or carry > 0:
            sum: int=carry

            if l1_values:
                sum+=l1_values.pop()

            if l2_values:
                sum+=l2_values.pop()

            sum_values.appendleft(sum % 10)

            carry=sum // 10

        return sum_values

    def build_linked_list(self, sum_values: deque[int]) -> Optional[ListNode]:
        head: Optional[ListNode]=ListNode(-1)

        current: Optional[ListNode]=head

        while sum_values:
            value: int=sum_values.popleft()

            current.next=ListNode(value)

            current=current.next

        return head