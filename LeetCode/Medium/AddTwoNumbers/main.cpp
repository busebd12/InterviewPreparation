#include "../ListNode.h"
#include <iostream>

/*
 * Approach: we iterate over the two linked-lists using two pointers, p1 and p2, performing grade school addition as we go.
 * Once either p1 or p2 becomes nullptr, then we know we've reached the end of one of the linked-lists. After that,
 * we simply iterate over the rest of the longer linked-list and continue to add to our sum. Finally, after we have
 * iterated over both linked-lists, if the carry value is greater than zero, than we add it to the end of our result
 * linked-list. Since our result pointer has a dummy head value of zero, we return result->next.
 *
 * Time complexity: O(n + m) [where n is the length of linked-list l1 and m is the length of linked-list l2]
 * Space complexity: O(1)
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if(l1==nullptr)
    {
        return l2;
    }

    if(l2==nullptr)
    {
        return l1;
    }

    auto p1=l1;

    auto p2=l2;

    auto current=new ListNode(0);

    auto result=current;

    int carry=0;

    while(p1!=nullptr && p2!=nullptr)
    {
        int num1=p1->val;

        int num2=p2->val;

        int total=carry + num1 + num2;

        current->next=new ListNode(total % 10);

        current=current->next;

        carry=total/10;

        p1=p1->next;

        p2=p2->next;
    }

    while(p1!=nullptr)
    {
        int num1=carry + p1->val;

        current->next=new ListNode(num1 % 10);

        carry=num1/10;

        current=current->next;

        p1=p1->next;
    }

    while(p2!=nullptr)
    {
        int num2=carry + p2->val;

        current->next=new ListNode(num2 % 10);

        carry=num2/10;

        current=current->next;

        p2=p2->next;
    }

    if(carry > 0)
    {
        current->next=new ListNode(carry);
    }

    return result->next;
}