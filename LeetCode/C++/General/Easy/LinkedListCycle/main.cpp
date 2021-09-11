#include "../ListNode.h"
#include <iostream>
using namespace std;

/*
 * Approach:
 * Use two pointers, a "fast" and a "slow" one. The fast one moves twice as fast as the slow one.
 * As we move "fast" and "slow" through the linked-list, if the value pointed to by fast equals
 * the value pointed to by slow, then we have a cycle.
 */

bool hasCycle(ListNode *head)
{
    if(head==nullptr)
    {
        return false;
    }

    if(head->next==nullptr)
    {
        return false;
    }

    ListNode* slow=head;

    ListNode* fast=slow->next;

    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
        if(fast->val==slow->val)
        {
            return true;
        }

        slow=slow->next;

        fast=fast->next->next;
    }

    return false;
}