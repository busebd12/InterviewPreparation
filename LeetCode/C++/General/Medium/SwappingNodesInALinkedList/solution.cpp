/*
Solution: see comments.

Time complexity: O(n) [where n is the length of the linked list]
Space complexity: O(1)
*/

class Solution
{
    public:
        ListNode* swapNodes(ListNode* head, int k)
        {
            ListNode* node1=head;

            ListNode* node2=head;

            //Decrement k to make k 0-indexed instead of 1-indexed
            k-=1;

            //Move node1 to point to the kth node in the list
            while(k > 0)
            {
                node1=node1->next;

                k--;
            }

            //Remember the kth node in the list
            ListNode* kth=node1;

            //Move node1 to the last node in the list
            while(node1->next!=nullptr)
            {
                node1=node1->next;

                node2=node2->next;
            }

            //At this point, node2 is pointing to the n-kth node, so swap the values
            swap(kth->val, node2->val);

            return head;
        }
};