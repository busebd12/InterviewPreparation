#include "../ListNode.h"
#include <iostream>

/*
 * Solution: reverse both the input linked-lists and then add the two numbers using grade school addition.
 *
 * Time complexity: O(n + m) [where n and m are the lengths of the two linked-lists]
 * Space complexity: O(1)
 */
ListNode* reverseList(ListNode* head)
{
    ListNode* newHead=nullptr;

    ListNode* current=head;

    while(current!=nullptr)
    {
        ListNode* after=current->next;

        current->next=newHead;

        newHead=current;

        current=after;
    }

    return newHead;
}


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

    auto p1=reverseList(l1);

    auto p2=reverseList(l2);

    auto current=new ListNode(0);

    auto result=current;

    result=current;

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

    auto resultReversed=reverseList(result->next);

    return resultReversed;
}