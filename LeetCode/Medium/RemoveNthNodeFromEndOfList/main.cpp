#include "../ListNode.h"
#include <iostream>

/*
 * Solution: we first calculate the length of the linked list.
 * Then, we iterate through the linked list until we reach the
 * node before the node we want to delete. We then have to handle
 * two special cases: we are deleting the last node or the first
 * node. In either of those two cases, we simply move the head
 * pointer up one spot in the linked list and set our result
 * pointer equal to head. Else, we simply point our current
 * pointer to the node after the one we want to delete.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head==nullptr)
    {
        return head;
    }

    int length=0;

    auto current=head;

    while(current!=nullptr)
    {
        length++;

        current=current->next;
    }

    if(n > length)
    {
        return head;
    }

    int target=(length-n)-1;

    current=head;

    auto result=current;

    for(int count=0;count<target;++count)
    {
        current=current->next;
    }

    if(current->next==nullptr || n==length)
    {
        head=head->next;

        result=head;
    }
    else
    {
        current->next=current->next->next;
    }

    return result;
}