#include "../ListNode.h"
#include <iostream>
using namespace std;

/*
 * Approach: counter the number of elements in our linked list to get its length. Then, we just loop up to the middle
 * element in the linked list using a sentinel node. Then, return the sentinel node.
 *
 * Time complexity: O(n) [where n is the length of the input linked list]
 * Space complexity: O(1)
 */

ListNode* middleNode(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    size_t listSize=0;

    ListNode* current=head;

    while(current!=nullptr)
    {
        listSize++;

        current=current->next;
    }

    int middle=int(listSize/2);

    current=head;

    for(int count=0;count<middle;++count)
    {
        current=current->next;
    }

    return current;
}