#include "../ListNode.h"
#include <iostream>
using namespace std;

/*
 * Approach: Since we only have access to the current node and all nodes after it,
 * set the value of the current node equal to the value of the next node.
 * Then, change the next pointer of the current node to point to the next next node.
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

void deleteNode(ListNode* node)
{
    node->val=node->next->val;

    node->next=node->next->next;
}