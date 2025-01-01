# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node=head

        hashmap=dict()

        prefix_sum=0

        while node:
            prefix_sum+=node.val

            if prefix_sum==0:
                head=node.next

                hashmap.clear()
            else:
                if hashmap.get(prefix_sum):
                    subarray_node=hashmap[prefix_sum].next

                    current_sum=prefix_sum

                    while subarray_node!=node:
                        current_sum+=subarray_node.val

                        del hashmap[current_sum]

                        subarray_node=subarray_node.next

                    hashmap[prefix_sum].next=node.next
                else:
                    hashmap[prefix_sum]=node
            
            node=node.next

        return head