#include "../ListNode.h"

class Solution
{
    public:
        void deleteNode(ListNode* node)
        {
            //Change the node's value to the value of the node after it
            node->val=node->next->val;
            
            //Change the current node to point to node after its immediate successor
            node->next=node->next->next;
        }
};